/*
 * User.h
 *
 *  Created on: Aug 6, 2013
 *      Author: alanwong
 */

#ifndef USER_H_
#define USER_H_

#include <QString>

class User {

public:
	User();
	User(QString id, QString name, QString first_name, QString last_name, QString link, QString username);
	virtual ~User();

	QString getFirstName() const {
		return _first_name;
	}

	QString getId() const {
		return _id;
	}

	QString getLastName() const {
		return _last_name;
	}

	QString getLink() const {
		return _link;
	}

	QString getName() const {
		return _name;
	}

	QString getUsername() const {
		return _username;
	}

private:
	QString _id;
	QString _name;
	QString _first_name;
	QString _last_name;
	QString _link;
	QString _username;
};

#endif /* USER_H_ */
