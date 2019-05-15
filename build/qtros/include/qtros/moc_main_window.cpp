/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/qtros/include/qtros/main_window.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_qtros__MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[336];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qtros__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qtros__MainWindow_t qt_meta_stringdata_qtros__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 17), // "qtros::MainWindow"
QT_MOC_LITERAL(1, 18, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 25), // "on_button_connect_clicked"
QT_MOC_LITERAL(4, 70, 5), // "check"
QT_MOC_LITERAL(5, 76, 40), // "on_checkbox_use_environment_s..."
QT_MOC_LITERAL(6, 117, 5), // "state"
QT_MOC_LITERAL(7, 123, 13), // "on_up_clicked"
QT_MOC_LITERAL(8, 137, 15), // "on_down_clicked"
QT_MOC_LITERAL(9, 153, 15), // "on_left_clicked"
QT_MOC_LITERAL(10, 169, 16), // "on_right_clicked"
QT_MOC_LITERAL(11, 186, 17), // "updateLoggingView"
QT_MOC_LITERAL(12, 204, 21), // "updateLoggingView_sub"
QT_MOC_LITERAL(13, 226, 7), // "pub_cmd"
QT_MOC_LITERAL(14, 234, 24), // "on_dialog_button_clicked"
QT_MOC_LITERAL(15, 259, 26), // "on_lib_rviz_button_clicked"
QT_MOC_LITERAL(16, 286, 23), // "on_romap_button_clicked"
QT_MOC_LITERAL(17, 310, 25) // "on_mapping_button_clicked"

    },
    "qtros::MainWindow\0on_actionAbout_triggered\0"
    "\0on_button_connect_clicked\0check\0"
    "on_checkbox_use_environment_stateChanged\0"
    "state\0on_up_clicked\0on_down_clicked\0"
    "on_left_clicked\0on_right_clicked\0"
    "updateLoggingView\0updateLoggingView_sub\0"
    "pub_cmd\0on_dialog_button_clicked\0"
    "on_lib_rviz_button_clicked\0"
    "on_romap_button_clicked\0"
    "on_mapping_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qtros__MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    1,   90,    2, 0x0a /* Public */,
       5,    1,   93,    2, 0x0a /* Public */,
       7,    0,   96,    2, 0x0a /* Public */,
       8,    0,   97,    2, 0x0a /* Public */,
       9,    0,   98,    2, 0x0a /* Public */,
      10,    0,   99,    2, 0x0a /* Public */,
      11,    0,  100,    2, 0x0a /* Public */,
      12,    0,  101,    2, 0x0a /* Public */,
      13,    0,  102,    2, 0x0a /* Public */,
      14,    0,  103,    2, 0x0a /* Public */,
      15,    0,  104,    2, 0x0a /* Public */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
       3,    0,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void qtros::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionAbout_triggered(); break;
        case 1: _t->on_button_connect_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_checkbox_use_environment_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_up_clicked(); break;
        case 4: _t->on_down_clicked(); break;
        case 5: _t->on_left_clicked(); break;
        case 6: _t->on_right_clicked(); break;
        case 7: _t->updateLoggingView(); break;
        case 8: _t->updateLoggingView_sub(); break;
        case 9: _t->pub_cmd(); break;
        case 10: _t->on_dialog_button_clicked(); break;
        case 11: _t->on_lib_rviz_button_clicked(); break;
        case 12: _t->on_romap_button_clicked(); break;
        case 13: _t->on_mapping_button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject qtros::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qtros__MainWindow.data,
      qt_meta_data_qtros__MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *qtros::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qtros::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_qtros__MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int qtros::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
