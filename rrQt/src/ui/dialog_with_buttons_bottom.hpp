/** \file
 *  \author zhengrr
 *  \date 2016-10-21 – 12-5
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_DIALOGWITHBUTTONSBOTTOM_HPP
#define _RRDEMOCDOMQT_DIALOGWITHBUTTONSBOTTOM_HPP

#include <QDialog>

namespace rrdemo {
namespace cdom {
namespace qt {

namespace Ui {
class DialogWithButtonsBottom;
}

/// 带底部按钮的对话框。
/**
 */
class DialogWithButtonsBottom : public QDialog {
    Q_OBJECT

public:
    explicit DialogWithButtonsBottom(QWidget *parent = Q_NULLPTR);
    ~DialogWithButtonsBottom();

private:
    Q_DISABLE_COPY(DialogWithButtonsBottom);
    explicit DialogWithButtonsBottom(DialogWithButtonsBottom &&) Q_DECL_EQ_DELETE;
    DialogWithButtonsBottom &operator=(DialogWithButtonsBottom &&)Q_DECL_EQ_DELETE;

    Ui::DialogWithButtonsBottom *ui {Q_NULLPTR};

};// class DialogWithButtonsBottom

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_DIALOGWITHBUTTONSBOTTOM_HPP
