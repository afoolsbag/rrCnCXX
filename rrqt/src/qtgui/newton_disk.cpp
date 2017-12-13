/** \copyright The MIT License */
#include "newton_disk.hpp"

#include <QApplication>
#include <QPainter>

namespace {
Q_CONSTEXPR double R {150.};
}// namespace

namespace rrdemo {
namespace cdom {
namespace qt {

NewtonDisk::NewtonDisk(QWidget* parent) : QWidget(parent)
{
    setFixedSize(2 * R, 2 * R);
}


void NewtonDisk::paintEvent(QPaintEvent*)
{
    QConicalGradient cg(0., 0., 0. / 360.);
    cg.setColorAt(0 * (360. / 7) / 360., Qt::red);      // Red
    ;                                                   // Orange
    cg.setColorAt(2 * (360. / 7) / 360., Qt::yellow);   // Yellow
    cg.setColorAt(3 * (360. / 7) / 360., Qt::green);    // Green
    cg.setColorAt(4 * (360. / 7) / 360., Qt::cyan);     // Blue
    cg.setColorAt(5 * (360. / 7) / 360., Qt::blue);     // Indigo
    cg.setColorAt(6 * (360. / 7) / 360., Qt::magenta);  // Violet
    cg.setColorAt(7 * (360. / 7) / 360., Qt::red);

    QBrush brush(cg);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(R, R);
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawEllipse(QPointF(0., 0.), R, R);
}

}// namespace qt
}// namespace cdom
}// namespace rrdemo

namespace {
int Main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    rrdemo::cdom::qt::NewtonDisk cd;
    cd.show();

    return app.exec();
}
}// namespace

#ifdef ENTRY_SWITCH
int main(int argc, char *argv[]) { return Main(argc, argv); }
#endif// ENTRY SWITCH
