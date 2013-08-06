#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include "BB10FBManager.h"

#include <QObject>

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class Application;
        class LocaleHandler;
    }
}

class QTranslator;

/*!
 * @brief Application object
 *
 *
 */

class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI();
    Q_INVOKABLE void logIn();
    Q_INVOKABLE void logOut();
    Q_INVOKABLE void getUserProfile();
    Q_INVOKABLE void getUserFriends();
public slots:
    void onSystemLanguageChanged();
    void onAccessTokenReceived(QString access_token);
    void onUserProfileReceived(User myself);
    void onUserFriendsReceived(QList<User> friendsList);
private:
    QTranslator* m_pTranslator;
    bb::cascades::LocaleHandler* m_pLocaleHandler;
    BB10FBManager* fbmanager;
};

#endif /* ApplicationUI_HPP_ */
