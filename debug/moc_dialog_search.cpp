/****************************************************************************
** Meta object code from reading C++ file 'dialog_search.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dialog_search.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_search.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Dialog_search_t {
    QByteArrayData data[23];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_search_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_search_t qt_meta_stringdata_Dialog_search = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Dialog_search"
QT_MOC_LITERAL(1, 14, 7), // "getinfo"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 14), // "setTableWidget"
QT_MOC_LITERAL(4, 38, 12), // "httpDownload"
QT_MOC_LITERAL(5, 51, 13), // "replyFinished"
QT_MOC_LITERAL(6, 65, 14), // "QNetworkReply*"
QT_MOC_LITERAL(7, 80, 5), // "reply"
QT_MOC_LITERAL(8, 86, 18), // "onDownloadProgress"
QT_MOC_LITERAL(9, 105, 9), // "bytesSent"
QT_MOC_LITERAL(10, 115, 10), // "bytesTotal"
QT_MOC_LITERAL(11, 126, 11), // "onReadyRead"
QT_MOC_LITERAL(12, 138, 4), // "stop"
QT_MOC_LITERAL(13, 143, 11), // "onclicked_0"
QT_MOC_LITERAL(14, 155, 11), // "onclicked_1"
QT_MOC_LITERAL(15, 167, 11), // "onclicked_2"
QT_MOC_LITERAL(16, 179, 11), // "onclicked_3"
QT_MOC_LITERAL(17, 191, 11), // "onclicked_4"
QT_MOC_LITERAL(18, 203, 11), // "onclicked_5"
QT_MOC_LITERAL(19, 215, 11), // "onclicked_6"
QT_MOC_LITERAL(20, 227, 11), // "onclicked_7"
QT_MOC_LITERAL(21, 239, 11), // "onclicked_8"
QT_MOC_LITERAL(22, 251, 11) // "onclicked_9"

    },
    "Dialog_search\0getinfo\0\0setTableWidget\0"
    "httpDownload\0replyFinished\0QNetworkReply*\0"
    "reply\0onDownloadProgress\0bytesSent\0"
    "bytesTotal\0onReadyRead\0stop\0onclicked_0\0"
    "onclicked_1\0onclicked_2\0onclicked_3\0"
    "onclicked_4\0onclicked_5\0onclicked_6\0"
    "onclicked_7\0onclicked_8\0onclicked_9"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_search[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    1,  101,    2, 0x09 /* Protected */,
       5,    1,  104,    2, 0x09 /* Protected */,
       8,    2,  107,    2, 0x09 /* Protected */,
      11,    0,  112,    2, 0x09 /* Protected */,
      12,    0,  113,    2, 0x09 /* Protected */,
      13,    0,  114,    2, 0x09 /* Protected */,
      14,    0,  115,    2, 0x09 /* Protected */,
      15,    0,  116,    2, 0x09 /* Protected */,
      16,    0,  117,    2, 0x09 /* Protected */,
      17,    0,  118,    2, 0x09 /* Protected */,
      18,    0,  119,    2, 0x09 /* Protected */,
      19,    0,  120,    2, 0x09 /* Protected */,
      20,    0,  121,    2, 0x09 /* Protected */,
      21,    0,  122,    2, 0x09 /* Protected */,
      22,    0,  123,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    9,   10,
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

void Dialog_search::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Dialog_search *_t = static_cast<Dialog_search *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getinfo(); break;
        case 1: _t->setTableWidget(); break;
        case 2: _t->httpDownload((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->onDownloadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 5: _t->onReadyRead(); break;
        case 6: _t->stop(); break;
        case 7: _t->onclicked_0(); break;
        case 8: _t->onclicked_1(); break;
        case 9: _t->onclicked_2(); break;
        case 10: _t->onclicked_3(); break;
        case 11: _t->onclicked_4(); break;
        case 12: _t->onclicked_5(); break;
        case 13: _t->onclicked_6(); break;
        case 14: _t->onclicked_7(); break;
        case 15: _t->onclicked_8(); break;
        case 16: _t->onclicked_9(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject Dialog_search::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Dialog_search.data,
      qt_meta_data_Dialog_search,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Dialog_search::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_search::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_search.stringdata0))
        return static_cast<void*>(const_cast< Dialog_search*>(this));
    return QDialog::qt_metacast(_clname);
}

int Dialog_search::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
