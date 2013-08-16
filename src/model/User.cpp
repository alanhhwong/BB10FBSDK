/*
 * User.cpp
 *
 *  Created on: Aug 6, 2013
 *      Author: alanwong
 */

#include "User.h"

User::User() {
}

User::~User() {
}

User::User(const User &user) {
	_id = user.getId();
	_name = user.getName();
	_first_name = user.getFirstName();
	_last_name = user.getLastName();
	_link = user.getLink();
	_username = user.getUsername();
}

User::User(QString id, QString name, QString first_name, QString last_name, QString link, QString username) {
	_id = id;
	_name = name;
	_first_name = first_name;
	_last_name = last_name;
	_link = link;
	_username = username;
}

