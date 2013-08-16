/****************************************************************************
** Meta object code from reading C++ file 'applicationui.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/applicationui.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'applicationui.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ApplicationUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      54,   41,   14,   14, 0x0a,
      92,   85,   14,   14, 0x0a,
     132,  120,   14,   14, 0x0a,
     172,  167,   14,   14, 0x0a,

 // methods: signature, parameters, type, tag, flags
     199,   14,   14,   14, 0x02,
     211,   14,   14,   14, 0x02,
     219,   14,   14,   14, 0x02,
     228,   14,   14,   14, 0x02,
     245,   14,   14,   14, 0x02,
     262,   14,   14,   14, 0x02,
     276,   14,   14,   14, 0x02,

       0        // eod
};

static const char qt_meta_stringdata_ApplicationUI[] = {
    "ApplicationUI\0\0onSystemLanguageChanged()\0"
    "access_token\0onAccessTokenReceived(QString)\0"
    "myself\0onUserProfileReceived(User)\0"
    "friendsList\0onUserFriendsReceived(QList<User>)\0"
    "post\0onPublishPostSuccess(Post)\0"
    "clearLogs()\0logIn()\0logOut()\0"
    "getUserProfile()\0getUserFriends()\0"
    "publishPost()\0publishPostWithImageUrl()\0"
};

void ApplicationUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ApplicationUI *_t = static_cast<ApplicationUI *>(_o);
        switch (_id) {
        case 0: _t->onSystemLanguageChanged(); break;
        case 1: _t->onAccessTokenReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onUserProfileReceived((*reinterpret_cast< User(*)>(_a[1]))); break;
        case 3: _t->onUserFriendsReceived((*reinterpret_cast< QList<User>(*)>(_a[1]))); break;
        case 4: _t->onPublishPostSuccess((*reinterpret_cast< Post(*)>(_a[1]))); break;
        case 5: _t->clearLogs(); break;
        case 6: _t->logIn(); break;
        case 7: _t->logOut(); break;
        case 8: _t->getUserProfile(); break;
        case 9: _t->getUserFriends(); break;
        case 10: _t->publishPost(); break;
        case 11: _t->publishPostWithImageUrl(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ApplicationUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ApplicationUI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ApplicationUI,
      qt_meta_data_ApplicationUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ApplicationUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ApplicationUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ApplicationUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ApplicationUI))
        return static_cast<void*>(const_cast< ApplicationUI*>(this));
    return QObject::qt_metacast(_clname);
}

int ApplicationUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
