/**
 * \file
 * \brief 单例模式
 * \author zhengrr
 * \date 2016-10-18 – 2018-1-23
 * \copyright The MIT License
 */

#include "cxx_std_ver.hpp"

#if !CXX_N2660
#include <mutex>
#endif

#include <gtest/gtest.h>

namespace {

/* 结论：
 * 　若非必要，建议使用提前初始化单例模式，其无需互斥锁；
 * 　若有必要，延迟初始化应直接用锁，而非双重检查锁，且在调用时善用变量缓存，减少访问。
 *
 * 议题：为什么反对使用双重检查锁？
 * 　简言之，Ｃ＋＋抽象机是单线程的，天性不支持多线程，双重检查锁无法保证线程安全。
 *
 * 议题：为什么直接使用锁可以认为是线程安全的？
 * 　Ｃ＋＋线程库会借助于超出Ｃ＋＋语言范畴的方式，来确保线程安全（如嵌入汇编指令）。
 *
 * 参见：<http://blog.jobbole.com/86392> */

/// 饿汉单例模式
class EagerSingleton {
 public:
  explicit EagerSingleton(const EagerSingleton &) = delete;
  EagerSingleton &operator=(const EagerSingleton &) = delete;
  static EagerSingleton &Instance();
 private:
  explicit EagerSingleton() = default;
};// class EagerSingleton

EagerSingleton &EagerSingleton::Instance() {
  static EagerSingleton *instancePointer{};
  if (!instancePointer) {
    instancePointer = new EagerSingleton();
  }
  return *instancePointer;
}

EagerSingleton &gBeforeMain = EagerSingleton::Instance();

/// 懒汉单例模式
class LazySingleton {
 public:
  explicit LazySingleton(const LazySingleton &) = delete;
  LazySingleton &operator=(const LazySingleton &) = delete;
  static LazySingleton &Instance();
 private:
  explicit LazySingleton() = default;
};// class LazySingleton

LazySingleton &LazySingleton::Instance() {
#if CXX_N2660
  static LazySingleton inst;
  return inst;
#else// !CXX_N2660
  static LazySingleton *pInst{};
  static std::mutex mutex;
  mutex.lock();
  {
    if (!pInst)
      pInst = new LazySingleton;
  }
  mutex.unlock();
  return *pInst;
#endif// CXX_N2660
};

}// namespace

TEST(singleton, preliminary) {
  auto &eagerSingleton1 = EagerSingleton::Instance();
  auto &eagerSingleton2 = EagerSingleton::Instance();
  assert(&eagerSingleton1 == &eagerSingleton2);

  auto &lazySingleton1 = LazySingleton::Instance();
  auto &lazySingleton2 = LazySingleton::Instance();
  assert(&lazySingleton1 == &lazySingleton2);
}
