/** \file
 *  \author zhengrr
 *  \date 2016-10-21 – 12-5
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_DIALOGWITHBUTTONSRIGHT_HPP
#define _RRDEMOCDOMQT_DIALOGWITHBUTTONSRIGHT_HPP

#include <QDialog>

namespace rrdemo {
namespace cdom {
namespace qt {

namespace Ui {
class DialogWithButtonsRight;
}

/// 带右侧按钮的对话框。
/**
*/
class DialogWithButtonsRight : public QDialog {
    Q_OBJECT

public:
    explicit DialogWithButtonsRight(QWidget *parent = Q_NULLPTR);
    ~DialogWithButtonsRight();

private:
    Q_DISABLE_COPY(DialogWithButtonsRight);
    explicit DialogWithButtonsRight(DialogWithButtonsRight &&) Q_DECL_EQ_DELETE;
    DialogWithButtonsRight &operator=(DialogWithButtonsRight &&)Q_DECL_EQ_DELETE;

    Ui::DialogWithButtonsRight *ui {Q_NULLPTR};

};// class DialogWithButtonsRight

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_DIALOGWITHBUTTONSRIGHT_HPP
