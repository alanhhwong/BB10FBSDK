/*
 * BB10FBManager.cpp
 *
 *  Created on: Aug 6, 2013
 *      Author: alanwong
 */

#include "BB10FBManager.h"
#include <bb/cascades/WebStorage>

using namespace bb::cascades;
using namespace bb::data;

BB10FBManager* BB10FBManager::_instance = NULL;

BB10FBManager::BB10FBManager() {
	_qnam = new QNetworkAccessManager;
}

BB10FBManager* BB10FBManager::instance() {
	if (!_instance) {
		_instance = new BB10FBManager;
	}
	return _instance;
}

BB10FBManager::~BB10FBManager() {
}

void BB10FBManager::signIn() {
	m_sheet = Sheet::create();
	connect(m_sheet, SIGNAL(closed()), m_sheet, SLOT(deleteLater()));
	//m_webview = WebView::create();
	m_webview = new WebView;

	Page* m_page = Page::create();
	TitleBar* titleBar = new TitleBar;
	titleBar->setTitle("Facebook Sign In");
	ActionItem* actionItem = new ActionItem;
	actionItem->setTitle("Cancel");
	connect(actionItem, SIGNAL(triggered()), this, SLOT(onCancelActionTriggered()));
	titleBar->setDismissAction(actionItem);
	m_page->setTitleBar(titleBar);

	Container* m_container = new Container;
	m_page->setContent(m_container);
	m_container->add(m_webview);
	m_sheet->setContent(m_page);

	QObject::connect(m_webview, SIGNAL(urlChanged(QUrl)), this, SLOT(webViewURLChanged(QUrl)));
	m_webview->setUrl(QUrl("https://www.facebook.com/dialog/oauth?client_id="+_appId+"&redirect_uri=https://www.facebook.com/connect/login_success.html&scope=publish_stream&display=touch&response_type=token"));
	m_sheet->open();
}

void BB10FBManager::webViewURLChanged(QUrl url) {
	QString newURL = url.toString();
	qDebug() << "\nURL CHANGED:" << newURL << "\n";
	if (newURL.contains("login_success") && newURL.contains("access_token=")) {  //successful login
		int startIndex = newURL.indexOf("access_token=") + 13;
		int endIndex = newURL.indexOf("&expires");
		_accessToken = newURL.mid(startIndex, endIndex - startIndex);
		emit accessTokenReceived(_accessToken);
		m_sheet->close();
	} else if (newURL.contains("user_denied") && !newURL.contains("login.php")) { //app install denied.  (not a facebook login req url)
		qDebug() << "User Denied";
	}
	else if (newURL.contains("login_success") && !newURL.contains("client_id")) {	//logout (no client id passed)
		emit signOutSuccess();
		m_sheet->close();
	}
}

void BB10FBManager::signOut() {
	m_sheet = Sheet::create();
	connect(m_sheet, SIGNAL(closed()), m_sheet, SLOT(deleteLater()));
	m_webview = WebView::create();

	Page* m_page = Page::create();
	TitleBar* titleBar = new TitleBar;
	titleBar->setTitle("Facebook Sign Out");
	ActionItem* actionItem = new ActionItem;
	actionItem->setTitle("Cancel");
	connect(actionItem, SIGNAL(triggered()), this, SLOT(onCancelActionTriggered()));
	titleBar->setDismissAction(actionItem);
	m_page->setTitleBar(titleBar);

	Container* m_container = new Container;
	m_page->setContent(m_container);
	m_container->add(m_webview);
	m_sheet->setContent(m_page);

	QObject::connect(m_webview, SIGNAL(urlChanged(QUrl)), this, SLOT(webViewURLChanged(QUrl)));
	m_webview->setUrl(QUrl("https://www.facebook.com/logout.php?next=https://www.facebook.com/connect/login_success.html&access_token="+accessToken()));
	m_sheet->open();
}

void BB10FBManager::onCancelActionTriggered() {
	m_sheet->close();
}

void BB10FBManager::getUserProfile() {
	QNetworkRequest request;
	request.setUrl(QUrl("https://graph.facebook.com/me?access_token="+accessToken()));
	_reply = _qnam->get(request);
	connect(_reply, SIGNAL(finished()), this, SLOT(onUserProfileReceived()));
}

void BB10FBManager::onUserProfileReceived() {
	QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
	QString jsonResponse = reply->readAll();
	JsonDataAccess jda;
	QVariantMap qmap = jda.loadFromBuffer(jsonResponse).value<QVariantMap>();
	User user(qmap["id"].toString(), qmap["name"].toString(), qmap["first_name"].toString(), qmap["last_name"].toString(), qmap["link"].toString(), qmap["username"].toString());
	emit userProfileReceived(user);
	reply->deleteLater();
}

void BB10FBManager::getUserFriends() {
	QNetworkRequest request;
	request.setUrl(QUrl("https://graph.facebook.com/me/friends?fields=id,name,first_name,last_name,link,username&access_token="+ accessToken()));
	_reply = _qnam->get(request);
	connect(_reply, SIGNAL(finished()), this, SLOT(onUserFriendsReceived()));
}

void BB10FBManager::onUserFriendsReceived() {
	QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
	QString jsonResponse = reply->readAll();
	JsonDataAccess jda;
	QVariantMap qmap = jda.loadFromBuffer(jsonResponse).value<QVariantMap>();
	QVariantList raw_list = qmap["data"].value<QVariantList>();

	QList<User> qlist;
	QVariantList::iterator i;
	for (i = raw_list.begin(); i != raw_list.end(); ++i) {
		qlist.append(User(i->value<QVariantMap>()["id"].toString(), i->value<QVariantMap>()["name"].toString(), i->value<QVariantMap>()["first_name"].toString(),
				i->value<QVariantMap>()["last_name"].toString(), i->value<QVariantMap>()["link"].toString(), i->value<QVariantMap>()["username"].toString()));
	}

	emit userFriendsReceived(qlist);
}
