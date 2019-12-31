//===-- Boost.Predef --------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief Boost.Predef
/// \details This library defines a set of compiler, architecture, operating system, library, and other version numbers from the information it can gather of C, C++, Objective C, and Objective C++ predefined macros or those defined in generally available headers.
///
/// \sa <https://boost.org/doc/libs/master/libs/config/>
///
/// \version 2019-12-31
/// \since 2019-12-31
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <iostream>

#include <boost/format.hpp>
#include <boost/predef.h>
#include <gtest/gtest.h>

using namespace std;
using boost::format;

namespace rrboost {

/// \brief Boost.Predef 提供的关于架构的预定义宏
TEST(predef, architecture)
{
    cout << format("%|-24| %||\n") % BOOST_ARCH_ALPHA_NAME % BOOST_ARCH_ALPHA;
    cout << format("%|-24| %||\n") % BOOST_ARCH_ARM_NAME % BOOST_ARCH_ARM;
    cout << format("%|-24| %||\n") % BOOST_ARCH_BLACKFIN_NAME % BOOST_ARCH_BLACKFIN;
    cout << format("%|-24| %||\n") % BOOST_ARCH_CONVEX_NAME % BOOST_ARCH_CONVEX;
    cout << format("%|-24| %||\n") % BOOST_ARCH_IA64_NAME % BOOST_ARCH_IA64;
    cout << format("%|-24| %||\n") % BOOST_ARCH_M68K_NAME % BOOST_ARCH_M68K;
    cout << format("%|-24| %||\n") % BOOST_ARCH_MIPS_NAME % BOOST_ARCH_MIPS;
    cout << format("%|-24| %||\n") % BOOST_ARCH_PARISC_NAME % BOOST_ARCH_PARISC;
    cout << format("%|-24| %||\n") % BOOST_ARCH_PPC_NAME % BOOST_ARCH_PPC;
    cout << format("%|-24| %||\n") % BOOST_ARCH_PTX_NAME % BOOST_ARCH_PTX;
    cout << format("%|-24| %||\n") % BOOST_ARCH_PYRAMID_NAME % BOOST_ARCH_PYRAMID;
    cout << format("%|-24| %||\n") % BOOST_ARCH_RS6000_NAME % BOOST_ARCH_RS6000;
    cout << format("%|-24| %||\n") % BOOST_ARCH_SPARC_NAME % BOOST_ARCH_SPARC;
    cout << format("%|-24| %||\n") % BOOST_ARCH_SH_NAME % BOOST_ARCH_SH;
    cout << format("%|-24| %||\n") % BOOST_ARCH_SYS370_NAME % BOOST_ARCH_SYS370;
    cout << format("%|-24| %||\n") % BOOST_ARCH_SYS390_NAME % BOOST_ARCH_SYS390;
    cout << format("%|-24| %||\n") % BOOST_ARCH_X86_NAME % BOOST_ARCH_X86;
    cout << format("%|-24| %||\n") % BOOST_ARCH_X86_32_NAME % BOOST_ARCH_X86_32;
    cout << format("%|-24| %||\n") % BOOST_ARCH_X86_64_NAME % BOOST_ARCH_X86_64;
    cout << format("%|-24| %||\n") % BOOST_ARCH_Z_NAME % BOOST_ARCH_Z;
}

/// \brief Boost.Predef 提供的关于编译器的预定义宏
TEST(predef, compiler)
{
    cout << format("%|-24| %||\n") % BOOST_COMP_BORLAND_NAME % BOOST_COMP_BORLAND;
    cout << format("%|-24| %||\n") % BOOST_COMP_CLANG_NAME % BOOST_COMP_CLANG;
    cout << format("%|-24| %||\n") % BOOST_COMP_COMO_NAME % BOOST_COMP_COMO;
    cout << format("%|-24| %||\n") % BOOST_COMP_DEC_NAME % BOOST_COMP_DEC;
    cout << format("%|-24| %||\n") % BOOST_COMP_DIAB_NAME % BOOST_COMP_DIAB;
    cout << format("%|-24| %||\n") % BOOST_COMP_DMC_NAME % BOOST_COMP_DMC;
    cout << format("%|-24| %||\n") % BOOST_COMP_SYSC_NAME % BOOST_COMP_SYSC;
    cout << format("%|-24| %||\n") % BOOST_COMP_EDG_NAME % BOOST_COMP_EDG;
    cout << format("%|-24| %||\n") % BOOST_COMP_PATH_NAME % BOOST_COMP_PATH;
    cout << format("%|-24| %||\n") % BOOST_COMP_GNUC_NAME % BOOST_COMP_GNUC;
    cout << format("%|-24| %||\n") % BOOST_COMP_GCCXML_NAME % BOOST_COMP_GCCXML;
    cout << format("%|-24| %||\n") % BOOST_COMP_GHS_NAME % BOOST_COMP_GHS;
    cout << format("%|-24| %||\n") % BOOST_COMP_HPACC_NAME % BOOST_COMP_HPACC;
    cout << format("%|-24| %||\n") % BOOST_COMP_IAR_NAME % BOOST_COMP_IAR;
    cout << format("%|-24| %||\n") % BOOST_COMP_IBM_NAME % BOOST_COMP_IBM;
    cout << format("%|-24| %||\n") % BOOST_COMP_INTEL_NAME % BOOST_COMP_INTEL;
    cout << format("%|-24| %||\n") % BOOST_COMP_KCC_NAME % BOOST_COMP_KCC;
    cout << format("%|-24| %||\n") % BOOST_COMP_LLVM_NAME % BOOST_COMP_LLVM;
    cout << format("%|-24| %||\n") % BOOST_COMP_HIGHC_NAME % BOOST_COMP_HIGHC;
    cout << format("%|-24| %||\n") % BOOST_COMP_MWERKS_NAME % BOOST_COMP_MWERKS;
    cout << format("%|-24| %||\n") % BOOST_COMP_MRI_NAME % BOOST_COMP_MRI;
    cout << format("%|-24| %||\n") % BOOST_COMP_MPW_NAME % BOOST_COMP_MPW;
    cout << format("%|-24| %||\n") % BOOST_COMP_NVCC_NAME % BOOST_COMP_NVCC;
    cout << format("%|-24| %||\n") % BOOST_COMP_PALM_NAME % BOOST_COMP_PALM;
    cout << format("%|-24| %||\n") % BOOST_COMP_PGI_NAME % BOOST_COMP_PGI;
    cout << format("%|-24| %||\n") % BOOST_COMP_SGI_NAME % BOOST_COMP_SGI;
    cout << format("%|-24| %||\n") % BOOST_COMP_SUNPRO_NAME % BOOST_COMP_SUNPRO;
    cout << format("%|-24| %||\n") % BOOST_COMP_TENDRA_NAME % BOOST_COMP_TENDRA;
    cout << format("%|-24| %||\n") % BOOST_COMP_MSVC_NAME % BOOST_COMP_MSVC;
    cout << format("%|-24| %||\n") % BOOST_COMP_WATCOM_NAME % BOOST_COMP_WATCOM;
}

/// \brief Boost.Predef 提供的关于语言的预定义宏
TEST(predef, language)
{
    cout << format("%|-24| %||\n") % BOOST_LANG_CUDA_NAME % BOOST_LANG_CUDA;
    cout << format("%|-24| %||\n") % BOOST_LANG_CUDA_NAME % BOOST_LANG_CUDA;
    cout << format("%|-24| %||\n") % BOOST_LANG_OBJC_NAME % BOOST_LANG_OBJC;
    cout << format("%|-24| %||\n") % BOOST_LANG_STDC_NAME % BOOST_LANG_STDC;
    cout << format("%|-24| %||\n") % BOOST_LANG_STDCPP_NAME % BOOST_LANG_STDCPP;
    cout << format("%|-24| %||\n") % BOOST_LANG_STDCPPCLI_NAME % BOOST_LANG_STDCPPCLI;
    cout << format("%|-24| %||\n") % BOOST_LANG_STDECPP_NAME % BOOST_LANG_STDECPP;
}

/// \brief Boost.Predef 提供的关于标准库的预定义宏
TEST(predef, library)
{
    cout << format("%|-24| %||\n") % BOOST_LIB_C_CLOUDABI_NAME % BOOST_LIB_C_CLOUDABI;
    cout << format("%|-24| %||\n") % BOOST_LIB_C_GNU_NAME % BOOST_LIB_C_GNU;
    cout << format("%|-24| %||\n") % BOOST_LIB_C_UC_NAME % BOOST_LIB_C_UC;
    cout << format("%|-24| %||\n") % BOOST_LIB_C_VMS_NAME % BOOST_LIB_C_VMS;
    cout << format("%|-24| %||\n") % BOOST_LIB_C_ZOS_NAME % BOOST_LIB_C_ZOS;
    cout << format("%|-24| %||\n") % BOOST_LIB_STD_CXX_NAME % BOOST_LIB_STD_CXX;
    cout << format("%|-24| %||\n") % BOOST_LIB_STD_DINKUMWARE_NAME % BOOST_LIB_STD_DINKUMWARE;
    cout << format("%|-24| %||\n") % BOOST_LIB_STD_COMO_NAME % BOOST_LIB_STD_COMO;
    cout << format("%|-24| %||\n") % BOOST_LIB_STD_MSIPL_NAME % BOOST_LIB_STD_MSIPL;
    cout << format("%|-24| %||\n") % BOOST_LIB_STD_MSL_NAME % BOOST_LIB_STD_MSL;
    cout << format("%|-24| %||\n") % BOOST_LIB_STD_RW_NAME % BOOST_LIB_STD_RW;
    cout << format("%|-24| %||\n") % BOOST_LIB_STD_SGI_NAME % BOOST_LIB_STD_SGI;
    cout << format("%|-24| %||\n") % BOOST_LIB_STD_GNU_NAME % BOOST_LIB_STD_GNU;
    cout << format("%|-24| %||\n") % BOOST_LIB_STD_STLPORT_NAME % BOOST_LIB_STD_STLPORT;
    cout << format("%|-24| %||\n") % BOOST_LIB_STD_IBM_NAME % BOOST_LIB_STD_IBM;
}

/// \brief Boost.Predef 提供的关于操作系统的预定义宏
TEST(predef, os)
{
    cout << format("%|-24| %||\n") % BOOST_OS_AIX_NAME % BOOST_OS_AIX;
    cout << format("%|-24| %||\n") % BOOST_OS_AMIGAOS_NAME % BOOST_OS_AMIGAOS;
    cout << format("%|-24| %||\n") % BOOST_OS_ANDROID_NAME % BOOST_OS_ANDROID;
    cout << format("%|-24| %||\n") % BOOST_OS_BEOS_NAME % BOOST_OS_BEOS;
    cout << format("%|-24| %||\n") % BOOST_OS_BSD_NAME % BOOST_OS_BSD;
    cout << format("%|-24| %||\n") % BOOST_OS_CYGWIN_NAME % BOOST_OS_CYGWIN;
    cout << format("%|-24| %||\n") % BOOST_OS_HAIKU_NAME % BOOST_OS_HAIKU;
    cout << format("%|-24| %||\n") % BOOST_OS_HPUX_NAME % BOOST_OS_HPUX;
    cout << format("%|-24| %||\n") % BOOST_OS_IOS_NAME % BOOST_OS_IOS;
    cout << format("%|-24| %||\n") % BOOST_OS_IRIX_NAME % BOOST_OS_IRIX;
    cout << format("%|-24| %||\n") % BOOST_OS_LINUX_NAME % BOOST_OS_LINUX;
    cout << format("%|-24| %||\n") % BOOST_OS_MACOS_NAME % BOOST_OS_MACOS;
    cout << format("%|-24| %||\n") % BOOST_OS_OS400_NAME % BOOST_OS_OS400;
    cout << format("%|-24| %||\n") % BOOST_OS_QNX_NAME % BOOST_OS_QNX;
    cout << format("%|-24| %||\n") % BOOST_OS_SOLARIS_NAME % BOOST_OS_SOLARIS;
    cout << format("%|-24| %||\n") % BOOST_OS_UNIX_NAME % BOOST_OS_UNIX;
    cout << format("%|-24| %||\n") % BOOST_OS_SVR4_NAME % BOOST_OS_SVR4;
    cout << format("%|-24| %||\n") % BOOST_OS_VMS_NAME % BOOST_OS_VMS;
    cout << format("%|-24| %||\n") % BOOST_OS_WINDOWS_NAME % BOOST_OS_WINDOWS;
    cout << format("%|-24| %||\n") % BOOST_OS_BSD_BSDI_NAME % BOOST_OS_BSD_BSDI;
    cout << format("%|-24| %||\n") % BOOST_OS_BSD_DRAGONFLY_NAME % BOOST_OS_BSD_DRAGONFLY;
    cout << format("%|-24| %||\n") % BOOST_OS_BSD_FREE_NAME % BOOST_OS_BSD_FREE;
    cout << format("%|-24| %||\n") % BOOST_OS_BSD_NET_NAME % BOOST_OS_BSD_NET;
    cout << format("%|-24| %||\n") % BOOST_OS_BSD_OPEN_NAME % BOOST_OS_BSD_OPEN;
}

/// \brief Boost.Predef 提供的关于平台的预定义宏
TEST(predef, platform)
{
    cout << format("%|-32| %||\n") % BOOST_PLAT_ANDROID_NAME % BOOST_PLAT_ANDROID;
    cout << format("%|-32| %||\n") % BOOST_PLAT_CLOUDABI_NAME % BOOST_PLAT_CLOUDABI;
    cout << format("%|-32| %||\n") % BOOST_PLAT_IOS_DEVICE_NAME % BOOST_PLAT_IOS_DEVICE;
    cout << format("%|-32| %||\n") % BOOST_PLAT_IOS_SIMULATOR_NAME % BOOST_PLAT_IOS_SIMULATOR;
    cout << format("%|-32| %||\n") % BOOST_PLAT_MINGW_NAME % BOOST_PLAT_MINGW;
    cout << format("%|-32| %||\n") % BOOST_PLAT_MINGW32_NAME % BOOST_PLAT_MINGW32;
    cout << format("%|-32| %||\n") % BOOST_PLAT_MINGW64_NAME % BOOST_PLAT_MINGW64;
    cout << format("%|-32| %||\n") % BOOST_PLAT_WINDOWS_DESKTOP_NAME % BOOST_PLAT_WINDOWS_DESKTOP;
    cout << format("%|-32| %||\n") % BOOST_PLAT_WINDOWS_PHONE_NAME % BOOST_PLAT_WINDOWS_PHONE;
    cout << format("%|-32| %||\n") % BOOST_PLAT_WINDOWS_RUNTIME_NAME % BOOST_PLAT_WINDOWS_RUNTIME;
    cout << format("%|-32| %||\n") % BOOST_PLAT_WINDOWS_SERVER_NAME % BOOST_PLAT_WINDOWS_SERVER;
    cout << format("%|-32| %||\n") % BOOST_PLAT_WINDOWS_STORE_NAME % BOOST_PLAT_WINDOWS_STORE;
    cout << format("%|-32| %||\n") % BOOST_PLAT_WINDOWS_SYSTEM_NAME % BOOST_PLAT_WINDOWS_SYSTEM;
    cout << format("%|-32| %||\n") % BOOST_PLAT_WINDOWS_UWP_NAME % BOOST_PLAT_WINDOWS_UWP;
}

/// \brief Boost.Predef 提供的关于硬件的预定义宏
TEST(predef, hardware)
{
    cout << format("%|-24| %||\n") % BOOST_HW_SIMD_NAME % BOOST_HW_SIMD;
    cout << format("%|-24| %||\n") % BOOST_HW_SIMD_X86_NAME % BOOST_HW_SIMD_X86;
    cout << format("%|-24| %||\n") % BOOST_HW_SIMD_X86_AMD_NAME % BOOST_HW_SIMD_X86_AMD;
    cout << format("%|-24| %||\n") % BOOST_HW_SIMD_ARM_NAME % BOOST_HW_SIMD_ARM;
    cout << format("%|-24| %||\n") % BOOST_HW_SIMD_PPC_NAME % BOOST_HW_SIMD_PPC;
}

/// \brief Boost.Predef 提供的其它预定义宏
TEST(predef, other)
{
    cout << format("%|-24| %||\n") % BOOST_ENDIAN_BIG_BYTE_NAME % BOOST_ENDIAN_BIG_BYTE;
    cout << format("%|-24| %||\n") % BOOST_ENDIAN_LITTLE_BYTE_NAME % BOOST_ENDIAN_LITTLE_BYTE;
    cout << format("%|-24| %||\n") % BOOST_ENDIAN_BIG_WORD_NAME % BOOST_ENDIAN_BIG_WORD;
    cout << format("%|-24| %||\n") % BOOST_ENDIAN_LITTLE_WORD_NAME % BOOST_ENDIAN_LITTLE_WORD;
}

}
