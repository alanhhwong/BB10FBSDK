#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include "BB10FBContext.h"
#include "PublishService.h"
#include "Post.h"
#include "User.h"

#include <QObject>
#include <bb/cascades/Label>

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
    Q_INVOKABLE void clearLogs();
    Q_INVOKABLE void logIn();
    Q_INVOKABLE void logOut();
    Q_INVOKABLE void getUserProfile();
    Q_INVOKABLE void getUserFriends();
    Q_INVOKABLE void publishPost();
    Q_INVOKABLE void publishPostWithImageUrl();

public slots:
    void onSystemLanguageChanged();
    void onAccessTokenReceived(QString access_token);
    void onUserProfileReceived(User myself);
    void onUserFriendsReceived(QList<User> friendsList);
    void onPublishPostSuccess(Post post);

private:
    void logMessage(QString);

    QTranslator *m_pTranslator;
    bb::cascades::LocaleHandler *m_pLocaleHandler;
    BB10FBContext *fbcontext;
    PublishService *publishService;
    User *_myself;
    Label *logLabel;
};

#endif /* ApplicationUI_HPP_ */
