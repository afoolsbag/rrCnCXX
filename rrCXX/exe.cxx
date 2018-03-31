//===-- Executable ----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 可执行文件
///
/// \version 2018-03-31
/// \since 2018-03-30
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "lib.h"

int main(int argc, char *argv[])
{
  struct rrcxx_version_t ver;
  rrcxx_get_version(&ver);
  std::cout << "version: " << ver.major << "." << ver.minor << "." << ver.patch << "." << ver.tweak << std::endl;

  time_t sigh = rrcxx_sigh();
  std::cout << "whisper: " << asctime(localtime(&sigh)) << std::endl;

  return EXIT_SUCCESS;
}
