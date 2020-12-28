/****************************************************************************
** Meta object code from reading C++ file 'mythread2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PraSys/mythread2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mythread2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mythread2_t {
    QByteArrayData data[6];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mythread2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mythread2_t qt_meta_stringdata_Mythread2 = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Mythread2"
QT_MOC_LITERAL(1, 10, 4), // "over"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 7), // "lcd_sig"
QT_MOC_LITERAL(4, 24, 7), // "timestr"
QT_MOC_LITERAL(5, 32, 8) // "lcd_slot"

    },
    "Mythread2\0over\0\0lcd_sig\0timestr\0"
    "lcd_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mythread2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void Mythread2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mythread2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->over(); break;
        case 1: _t->lcd_sig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->lcd_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Mythread2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mythread2::over)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Mythread2::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mythread2::lcd_sig)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mythread2::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_Mythread2.data,
    qt_meta_data_Mythread2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mythread2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mythread2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mythread2.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Mythread2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Mythread2::over()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Mythread2::lcd_sig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
