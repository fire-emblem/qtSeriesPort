/****************************************************************************
** Meta object code from reading C++ file 'mtdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mtdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mtdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mtDlg_t {
    QByteArrayData data[9];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mtDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mtDlg_t qt_meta_stringdata_mtDlg = {
    {
QT_MOC_LITERAL(0, 0, 5), // "mtDlg"
QT_MOC_LITERAL(1, 6, 16), // "realtimeDataSlot"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 2), // "WZ"
QT_MOC_LITERAL(4, 27, 2), // "SD"
QT_MOC_LITERAL(5, 30, 1), // "i"
QT_MOC_LITERAL(6, 32, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(7, 54, 22), // "on_butShowWZSD_clicked"
QT_MOC_LITERAL(8, 77, 22) // "on_butShowIaIb_clicked"

    },
    "mtDlg\0realtimeDataSlot\0\0WZ\0SD\0i\0"
    "on_pushButton_clicked\0on_butShowWZSD_clicked\0"
    "on_butShowIaIb_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mtDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x0a /* Public */,
       6,    0,   41,    2, 0x08 /* Private */,
       7,    0,   42,    2, 0x08 /* Private */,
       8,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Long, QMetaType::Long, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mtDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mtDlg *_t = static_cast<mtDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->realtimeDataSlot((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_butShowWZSD_clicked(); break;
        case 3: _t->on_butShowIaIb_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject mtDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_mtDlg.data,
      qt_meta_data_mtDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mtDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mtDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mtDlg.stringdata0))
        return static_cast<void*>(const_cast< mtDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int mtDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
