/****************************************************************************
** Meta object code from reading C++ file 'send.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../send.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'send.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Send_t {
    QByteArrayData data[10];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Send_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Send_t qt_meta_stringdata_Send = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Send"
QT_MOC_LITERAL(1, 5, 25), // "on_sendpushButton_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "sendMessage"
QT_MOC_LITERAL(4, 44, 25), // "on_exitpushButton_clicked"
QT_MOC_LITERAL(5, 70, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 92, 11), // "eventFilter"
QT_MOC_LITERAL(7, 104, 3), // "obj"
QT_MOC_LITERAL(8, 108, 7), // "QEvent*"
QT_MOC_LITERAL(9, 116, 5) // "event"

    },
    "Send\0on_sendpushButton_clicked\0\0"
    "sendMessage\0on_exitpushButton_clicked\0"
    "on_pushButton_clicked\0eventFilter\0obj\0"
    "QEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Send[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    2,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 8,    7,    9,

       0        // eod
};

void Send::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Send *_t = static_cast<Send *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sendpushButton_clicked(); break;
        case 1: _t->sendMessage(); break;
        case 2: _t->on_exitpushButton_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Send::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Send.data,
      qt_meta_data_Send,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Send::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Send::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Send.stringdata0))
        return static_cast<void*>(const_cast< Send*>(this));
    return QDialog::qt_metacast(_clname);
}

int Send::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
