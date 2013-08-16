/****************************************************************************
** Meta object code from reading C++ file 'BB10FBContext.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/BB10FBContext.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BB10FBContext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BB10FBContext[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      44,   14,   14,   14, 0x05,
      70,   14,   14,   14, 0x05,
     103,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     120,   14,   14,   14, 0x0a,
     144,   14,   14,   14, 0x0a,
     170,   14,   14,   14, 0x0a,
     194,   14,   14,   14, 0x0a,
     218,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BB10FBContext[] = {
    "BB10FBContext\0\0accessTokenReceived(QString)\0"
    "userProfileReceived(User)\0"
    "userFriendsReceived(QList<User>)\0"
    "signOutSuccess()\0webViewURLChanged(QUrl)\0"
    "onCancelActionTriggered()\0"
    "onUserProfileReceived()\0onUserFriendsReceived()\0"
    "handleLayoutFrameUpdated(QRectF)\0"
};

void BB10FBContext::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BB10FBContext *_t = static_cast<BB10FBContext *>(_o);
        switch (_id) {
        case 0: _t->accessTokenReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->userProfileReceived((*reinterpret_cast< User(*)>(_a[1]))); break;
        case 2: _t->userFriendsReceived((*reinterpret_cast< QList<User>(*)>(_a[1]))); break;
        case 3: _t->signOutSuccess(); break;
        case 4: _t->webViewURLChanged((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 5: _t->onCancelActionTriggered(); break;
        case 6: _t->onUserProfileReceived(); break;
        case 7: _t->onUserFriendsReceived(); break;
        case 8: _t->handleLayoutFrameUpdated((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BB10FBContext::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BB10FBContext::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BB10FBContext,
      qt_meta_data_BB10FBContext, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BB10FBContext::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BB10FBContext::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BB10FBContext::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BB10FBContext))
        return static_cast<void*>(const_cast< BB10FBContext*>(this));
    return QObject::qt_metacast(_clname);
}

int BB10FBContext::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void BB10FBContext::accessTokenReceived(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BB10FBContext::userProfileReceived(User _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BB10FBContext::userFriendsReceived(QList<User> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BB10FBContext::signOutSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
