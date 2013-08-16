/*
 * PublishService.h
 *
 *  Created on: Aug 8, 2013
 *      Author: alanwong
 */

#ifndef PUBLISHSERVICE_H_
#define PUBLISHSERVICE_H_

#include "BB10FBContext.h"
#include "Post.h"
#include "User.h"
#include <bb/data/JsonDataAccess>

using namespace bb::data;

class PublishService : public QObject
{
    Q_OBJECT
public:
	PublishService(BB10FBContext*);
	virtual ~PublishService();

	void publishPost(User, Post);

public slots:
	void onPublishPostResponseReceived();

signals:
	void publishPostSuccess(Post post);

private:
	BB10FBContext *_context;
    QNetworkAccessManager* _qnam;
    QNetworkReply* _reply;
};

#endif /* PUBLISHSERVICE_H_ */
