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
	User(const User &user);
	User(QString id, QString name, QString first_name, QString last_name, QString link, QString username);
	virtual ~User();

	QString getId() const { return _id; }
	void setId(QString id) { _id = id; }

	QString getFirstName() const { return _first_name; }
	void setFirstName(QString firstName) { _first_name = firstName; }

	QString getLastName() const { return _last_name; }
	void setLastName(QString lastName) { _last_name = lastName; }

	QString getLink() const { return _link; }
	void setLink(QString link) { _link = link; }

	QString getName() const { return _name; }
	void setName(QString name) { _name = name; }

	QString getUsername() const { return _username; }
	void setUsername(QString username) { _username = username; }

private:
	QString _id;
	QString _name;
	QString _first_name;
	QString _last_name;
	QString _link;
	QString _username;
};

#endif /* USER_H_ */
