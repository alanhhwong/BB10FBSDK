/*
 * BB10FBManager.h
 *
 *  Created on: Aug 6, 2013
 *      Author: alanwong
 */

#ifndef BB10FBMANAGER_H_
#define BB10FBMANAGER_H_

#include "User.h"

#include <bb/cascades/Sheet>
#include <bb/cascades/WebView>
#include <bb/cascades/ActionItem>
#include <bb/cascades/Page>
#include <bb/cascades/TitleBar>
#include <bb/cascades/Container>
#include <QtNetwork/QNetworkAccessManager>
#include <bb/data/JsonDataAccess>

using namespace bb::cascades;

class BB10FBManager : public QObject
{
    Q_OBJECT
public:
	BB10FBManager();
	static BB10FBManager* instance();
	virtual ~BB10FBManager();

	void signIn();
	void signOut();
	void getUserProfile();
	void getUserFriends();

	void setAppID(QString app_id) { _appId = app_id; }

	QString accessToken() { return _accessToken; }
	void setAccessToken(QString token) { _accessToken = token; }

public slots:
	void webViewURLChanged(QUrl);
	void onCancelActionTriggered();
	void onUserProfileReceived();
	void onUserFriendsReceived();

signals:
	void accessTokenReceived(QString);
	void userProfileReceived(User);
	void userFriendsReceived(QList<User>);
	void signOutSuccess();

private:
	static BB10FBManager* _instance;
	QString _appId;
	QString _accessToken;

    WebView* m_webview;
    Sheet* m_sheet;
    QNetworkAccessManager* _qnam;
    QNetworkReply* _reply;
};

#endif /* BB10FBMANAGER_H_ */
