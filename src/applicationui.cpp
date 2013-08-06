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

    // Set created root object as the application scene
    app->setScene(root);

    fbmanager = BB10FBManager::instance();
    fbmanager->setAppID("287287514746804");
    connect(fbmanager, SIGNAL(accessTokenReceived(QString)), this, SLOT(onAccessTokenReceived(QString)));
    connect(fbmanager, SIGNAL(userProfileReceived(User)), this, SLOT(onUserProfileReceived(User)));
    connect(fbmanager, SIGNAL(userFriendsReceived(QList<User>)), this, SLOT(onUserFriendsReceived(QList<User>)));
}

ApplicationUI::~ApplicationUI() {
	delete fbmanager;
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

void ApplicationUI::onAccessTokenReceived(QString access_token) {
	qDebug() << "\nAccess Token received in app: " << access_token;
}

void ApplicationUI::logIn() {
	fbmanager->signIn();
}

void ApplicationUI::logOut() {
	fbmanager->signOut();
}

void ApplicationUI::getUserProfile() {
	fbmanager->getUserProfile();
}

void ApplicationUI::getUserFriends() {
	fbmanager->getUserFriends();
}

void ApplicationUI::onUserProfileReceived(User myself) {
	QString result = "ID: " + myself.getId() +
					 "\nName: " + myself.getName() +
					 "\nFirst Name: " + myself.getFirstName() +
					 "\nLast Name: " + myself.getLastName() +
					 "\nLink: " + myself.getLink() +
					 "\nUser Name: " + myself.getUsername();

	qDebug() << "\n" << result;
}

void ApplicationUI::onUserFriendsReceived(QList<User> friendsList) {
	QList<User>::iterator i;

	QString output;
	for (i = friendsList.begin(); i != friendsList.end(); ++i) {
		output += "Name: " + i->getName() + ", Username: "+i->getUsername() + "\n";
	}

	qDebug() << "Count: " << friendsList.count();
	qDebug() << "Friends:\n" << output;
}
