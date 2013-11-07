/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue Nov 15 05:32:39 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      22,   11,   11,   11, 0x0a,
      32,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      50,   11,   11,   11, 0x0a,
      55,   11,   11,   11, 0x0a,
      60,   11,   11,   11, 0x0a,
      73,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
      96,   11,   11,   11, 0x0a,
     105,   11,   11,   11, 0x0a,
     121,   11,  116,   11, 0x0a,
     140,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0handler()\0movebmp()\0menuA()\0"
    "menuIDA()\0h0()\0h1()\0combo_algo()\0"
    "combo_ht()\0myrefresh()\0update()\0"
    "nextMove()\0bool\0checkSolvability()\0"
    "shuffle()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handler(); break;
        case 1: movebmp(); break;
        case 2: menuA(); break;
        case 3: menuIDA(); break;
        case 4: h0(); break;
        case 5: h1(); break;
        case 6: combo_algo(); break;
        case 7: combo_ht(); break;
        case 8: myrefresh(); break;
        case 9: update(); break;
        case 10: nextMove(); break;
        case 11: { bool _r = checkSolvability();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: shuffle(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
