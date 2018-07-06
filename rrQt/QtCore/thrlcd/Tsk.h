//===-- Task ----------------------------------------------------*- C++ -*-===//
//!
//! \file
//! \brief 任务（类）。
//!
//! \verison 2018-07-06
//! \since 2016-11-30
//! \authors zhengrr
//! \copyright The MIT License
//!
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRQT_THREADLCD_TSK_H_
#define RRQT_THREADLCD_TSK_H_

#include <QtCore/QObject>

namespace rrqt {
namespace threadlcd {

class Task: public QObject {
    Q_OBJECT

public:
    explicit Task(QObject *parent = Q_NULLPTR): QObject(parent) {}
    virtual ~Task() override Q_DECL_EQ_DEFAULT;
    Q_DISABLE_COPY(Task)

public Q_SLOTS:
    void task();

Q_SIGNALS:
    void step(uint progress, uint total);
    void completed();

};//class Task

}//namespace threadlcd
}//namespace threadlcd

#endif//RRQT_THREADLCD_TSK_H_
