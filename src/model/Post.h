/*
 * Post.h
 *
 *  Created on: Aug 16, 2013
 *      Author: alanwong
 */

#ifndef POST_H_
#define POST_H_

#include <QString>
#include <QList>
#include "User.h"

class Post {

public:
	Post();
	virtual ~Post();

	QString getId() { return _id; }
	void setId(QString id) { _id = id; }

	User getFrom() { return _from; }
	void setFrom(User from) { _from = from; }

	QList<User> getTo() { return _to; }
	void setTo(QList<User> to) { _to = to; }

	QString getMessage() { return _message; }
	void setMessage(QString message) { _message = message; }

	QString getPicture() { return _picture; }
	void setPicture(QString picture) { _picture = picture; };

private:
	QString _id;
	User _from;
	QList<User> _to;
	QString _message;
	QString _picture;

};

#endif /* POST_H_ */
