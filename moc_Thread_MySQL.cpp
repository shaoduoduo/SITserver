/****************************************************************************
** Meta object code from reading C++ file 'Thread_MySQL.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Thread_MySQL.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Thread_MySQL.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Thread_MySQL_t {
    QByteArrayData data[8];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Thread_MySQL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Thread_MySQL_t qt_meta_stringdata_Thread_MySQL = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Thread_MySQL"
QT_MOC_LITERAL(1, 13, 11), // "signalMySQL"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "dealmesfrommain"
QT_MOC_LITERAL(4, 42, 1), // "s"
QT_MOC_LITERAL(5, 44, 16), // "deallistfromfile"
QT_MOC_LITERAL(6, 61, 17), // "dealstrfromserver"
QT_MOC_LITERAL(7, 79, 13) // "handleTimeout"

    },
    "Thread_MySQL\0signalMySQL\0\0dealmesfrommain\0"
    "s\0deallistfromfile\0dealstrfromserver\0"
    "handleTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Thread_MySQL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void Thread_MySQL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Thread_MySQL *_t = static_cast<Thread_MySQL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalMySQL((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->dealmesfrommain((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->deallistfromfile((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->dealstrfromserver((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->handleTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Thread_MySQL::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Thread_MySQL::signalMySQL)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Thread_MySQL::staticMetaObject = {
    { &MoveToThreadTest::staticMetaObject, qt_meta_stringdata_Thread_MySQL.data,
      qt_meta_data_Thread_MySQL,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Thread_MySQL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Thread_MySQL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Thread_MySQL.stringdata0))
        return static_cast<void*>(this);
    return MoveToThreadTest::qt_metacast(_clname);
}

int Thread_MySQL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MoveToThreadTest::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Thread_MySQL::signalMySQL(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
