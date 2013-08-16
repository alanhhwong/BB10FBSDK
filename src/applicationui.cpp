#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>

using namespace bb::cascades;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
        QObject(app)
{
    // prepare the localization
    m_pTranslator = new QTranslator(this);
    m_pLocaleHandler = new LocaleHandler(this);
    if(!QObject::connect(m_pLocaleHandler, SIGNAL(systemLanguageChanged()), this, SLOT(onSystemLanguageChanged()))) {
        // This is an abnormal situation! Something went wrong!
        // Add own code to recover here
        qWarning() << "Recovering from a failed connect()";
    }
    // initial load
    onSystemLanguageChanged();

    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
    qml->setContextProperty("app", this);

    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    logLabel = root->findChild<Label*>("log");

    // Set created root object as the application scene
    app->setScene(root);

    fbcontext = new BB10FBContext("287287514746804");
    publishService = new PublishService(fbcontext);
    _myself = NULL;

    connect(fbcontext, SIGNAL(accessTokenReceived(QString)), this, SLOT(onAccessTokenReceived(QString)));
    connect(fbcontext, SIGNAL(userProfileReceived(User)), this, SLOT(onUserProfileReceived(User)));
    connect(fbcontext, SIGNAL(userFriendsReceived(QList<User>)), this, SLOT(onUserFriendsReceived(QList<User>)));

    connect(publishService, SIGNAL(publishPostSuccess(Post)), this, SLOT(onPublishPostSuccess(Post)));
}

ApplicationUI::~ApplicationUI() {
	delete publishService;
	delete _myself;
}

void ApplicationUI::onSystemLanguageChanged()
{
    QCoreApplication::instance()->removeTranslator(m_pTranslator);
    // Initiate, load and install the application translation files.
    QString locale_string = QLocale().name();
    QString file_name = QString("BB10FBSDK_%1").arg(locale_string);
    if (m_pTranslator->load(file_name, "app/native/qm")) {
        QCoreApplication::instance()->installTranslator(m_pTranslator);
    }
}

void ApplicationUI::clearLogs() {
	logLabel->resetText();
}

void ApplicationUI::onAccessTokenReceived(QString access_token) {
	logMessage("Access Token received in app: " + access_token);
}

void ApplicationUI::logIn() {
	fbcontext->signIn();
}

void ApplicationUI::logOut() {
	fbcontext->signOut();
}

void ApplicationUI::getUserProfile() {
	fbcontext->getUserProfile();
}

void ApplicationUI::getUserFriends() {
	fbcontext->getUserFriends();
}

void ApplicationUI::onUserProfileReceived(User user) {
	_myself = new User(user);
	QString result = "ID: " + user.getId() +
					 "\nName: " + user.getName() +
					 "\nFirst Name: " + user.getFirstName() +
					 "\nLast Name: " + user.getLastName() +
					 "\nLink: " + user.getLink() +
					 "\nUser Name: " + user.getUsername();

	logMessage(result);
}

void ApplicationUI::onUserFriendsReceived(QList<User> friendsList) {
	QList<User>::iterator i;

	QString output;
	for (i = friendsList.begin(); i != friendsList.end(); ++i) {
		output += "Name: " + i->getName() + ", Username: "+i->getUsername() + "\n";
	}

	logMessage("Count: " + friendsList.count());
	logMessage("Friends:\n" + output);
}

void ApplicationUI::publishPost() {
	if (_myself && publishService) {
		User toUser;
		toUser.setId(_myself->getId());
		Post post;
		post.setMessage("Test Message from BB10SDK");
		logMessage("Publishing Post:\nid: " + _myself->getId() + "\nmsg: Test Message from BB10SDK");
		publishService->publishPost(toUser, post);
	}
	else {
		logMessage("My profile not set");
	}
}

void ApplicationUI::publishPostWithImageUrl() {
	if (_myself && publishService) {
		User toUser;
		toUser.setId(_myself->getId());
		Post post;
		post.setMessage("Test Message with Image from BB10SDK");
		post.setPicture("http://www.berrybk.com/wp-content/uploads/2013/02/blackberry-10-300113.jpg");
		logMessage("Publishing Post:\nid: " + _myself->getId() + "\nmsg: Test Message With Image Url from BB10SDK\npic:url: " + "http://www.berrybk.com/wp-content/uploads/2013/02/blackberry-10-300113.jpg");
		publishService->publishPost(toUser, post);
	}
	else {
		logMessage("My profile not set");
	}
}

void ApplicationUI::onPublishPostSuccess(Post post) {
	logMessage("Test Post (id: " + post.getId() + ") Published!");
}

void ApplicationUI::logMessage(QString message) {
	qDebug() << "[applicationui.cpp]: " << message;
	logLabel->setText(logLabel->text() + "\n" + message + "\n");
}
