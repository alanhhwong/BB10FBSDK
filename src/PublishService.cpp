/*
 * PublishService.cpp
 *
 *  Created on: Aug 8, 2013
 *      Author: alanwong
 */

#include "PublishService.h"

PublishService::PublishService(BB10FBContext* context) {
	_context = context;
	_qnam = new QNetworkAccessManager;
	_reply = NULL;
}

PublishService::~PublishService() {
	delete _qnam;
}

void PublishService::publishPost(User toUser, Post post) {
	if (_context->accessToken().isEmpty()) {
		qDebug() << "Access token missing.  Please log in.";
	}
	else {
		if (toUser.getId().isEmpty() || post.getMessage().isEmpty()) {
			//TODO: error handling
		}
		else {
			QNetworkRequest request;
			request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
			request.setUrl(QUrl("https://graph.facebook.com/" + toUser.getId() + "/feed"));

			QByteArray data;
			QUrl params;
			params.addQueryItem("access_token", _context->accessToken());
			params.addQueryItem("message", post.getMessage());
			if (!post.getPicture().isEmpty()) {
				params.addQueryItem("picture", post.getPicture());
			}
			data = params.encodedQuery();

			_reply = _qnam->post(request, data);
			connect(_reply, SIGNAL(finished()), this, SLOT(onPublishPostResponseReceived()));
		}
	}
}

void PublishService::onPublishPostResponseReceived() {
	QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
	QString jsonResponse = reply->readAll();
	JsonDataAccess jda;
	QVariantMap qmap = jda.loadFromBuffer(jsonResponse).value<QVariantMap>();
	if (!qmap["id"].toString().isEmpty()) {
		Post post;
		post.setId(qmap["id"].toString());
		emit publishPostSuccess(post);
	}
	reply->deleteLater();
}
