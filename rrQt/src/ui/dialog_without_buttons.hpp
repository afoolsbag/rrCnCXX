/** \file
 *  \author zhengrr
 *  \date 2016-10-21 – 12-5
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_DIALOGWITHOUTBUTTONS_HPP
#define _RRDEMOCDOMQT_DIALOGWITHOUTBUTTONS_HPP

#include <QDialog>

namespace rrdemo {
namespace cdom {
namespace qt {

namespace Ui {
class DialogWithoutButtons;
}

/// 不带按钮的对话框。
/**
*/
class DialogWithoutButtons : public QDialog {
    Q_OBJECT

public:
    explicit DialogWithoutButtons(QWidget *parent = Q_NULLPTR);
    ~DialogWithoutButtons();

private:
    Q_DISABLE_COPY(DialogWithoutButtons);
    explicit DialogWithoutButtons(DialogWithoutButtons &&) Q_DECL_EQ_DELETE;
    DialogWithoutButtons &operator=(DialogWithoutButtons &&)Q_DECL_EQ_DELETE;

    Ui::DialogWithoutButtons *ui {Q_NULLPTR};

};// class DialogWithoutButtons

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_DIALOGWITHOUTBUTTONS_HPP
