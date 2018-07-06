//! \copyright The MIT License

#include "Tsk.h"

#include <QtCore/QThread>
#include <QtCore/QTimer>

namespace rrqt {
namespace threadlcd {

void Task::task()
{
    static Q_CONSTEXPR uint TOTAL {UINT8_MAX};

    for (uint i {0}; i < TOTAL; ++i) {
        Q_EMIT step(i, TOTAL);
        QThread::msleep(1);
    }

    Q_EMIT completed();
}

}//namespace mainwindow
}//namespace rrqt
