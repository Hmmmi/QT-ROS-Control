/****************************************************************************
** Meta object code from reading C++ file 'myviz.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/qtros/include/qtros/myviz.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myviz.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyViz_t {
    QByteArrayData data[6];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyViz_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyViz_t qt_meta_stringdata_MyViz = {
    {
QT_MOC_LITERAL(0, 0, 5), // "MyViz"
QT_MOC_LITERAL(1, 6, 12), // "setThickness"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 17), // "thickness_percent"
QT_MOC_LITERAL(4, 38, 11), // "setCellSize"
QT_MOC_LITERAL(5, 50, 17) // "cell_size_percent"

    },
    "MyViz\0setThickness\0\0thickness_percent\0"
    "setCellSize\0cell_size_percent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyViz[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void MyViz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyViz *_t = static_cast<MyViz *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setThickness((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setCellSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MyViz::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyViz.data,
      qt_meta_data_MyViz,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyViz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyViz::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyViz.stringdata0))
        return static_cast<void*>(const_cast< MyViz*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyViz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
