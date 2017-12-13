/** \file
 *  \author zhengrr
 *  \date 2016-12-6
 *  \copyright The MIT License
 */
#ifndef _RRDEMOCDOMQT_FILESYSTEMMODELDIALOG_HPP
#define _RRDEMOCDOMQT_FILESYSTEMMODELDIALOG_HPP

#include <QDialog>
#include <QFileSystemModel>

namespace rrdemo {
namespace cdom {
namespace qt {

namespace Ui {
class FileSystemModelDialog;
}

class FileSystemModelDialog : public QDialog {
    Q_OBJECT

public:
    explicit FileSystemModelDialog(QWidget *parent = Q_NULLPTR);
    void initialize();
    ~FileSystemModelDialog();

private:
    Q_DISABLE_COPY(FileSystemModelDialog);
    explicit FileSystemModelDialog(FileSystemModelDialog &&) Q_DECL_EQ_DELETE;
    FileSystemModelDialog &operator=(FileSystemModelDialog &&)Q_DECL_EQ_DELETE;

    bool initialized {false};

private Q_SLOTS:
    void on_mkdirButton_clicked();
    void on_rmButton_clicked();

private:
    Ui::FileSystemModelDialog *ui {Q_NULLPTR};

    QFileSystemModel *model {Q_NULLPTR};

};// class FileSystemModelDialog 

}// namespace qt
}// namespace cdom
}// namespace rrdemo

#endif// _RRDEMOCDOMQT_FILESYSTEMMODELDIALOG_HPP
