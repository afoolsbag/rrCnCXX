/** \copyright The MIT License */

#include <stdlib.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>

#include "data/lfsys/dirmgmt/tsuite_dirmgmt.h"
#include "data/lfsys/dskmgmt/tsuite_dskmgmt.h"
#include "data/lfsys/fmgmt/tsuite_fmgmt.h"
#include "diag/dbg/errhdl/tsuite_errhdl.h"
#include "diag/dbg/basdbg/tsuite_basdbg.h"
#include "diag/th/tsuite_th.h"
#include "env/sh/tsuite_sh.h"
#include "net/rpc/tsuite_rpc.h"
#include "net/wnet/tsuite_wnet.h"
#include "sys/info/reg/tsuite_reg.h"
#include "ui/i18n/charset/tsuite_charset.h"
#include "ui/res/str/tsuite_str.h"

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);
    UNREFERENCED_PARAMETER(envp);

    SRunner *runner = srunner_create(NULL);

    srunner_add_suite(runner, TSuiteDirMgmt());
    srunner_add_suite(runner, TSuiteDskMgmt());
    srunner_add_suite(runner, TSuiteFMgmt());
    srunner_add_suite(runner, TSuiteErrHdl());
    srunner_add_suite(runner, TSuiteBasDbg());
    srunner_add_suite(runner, TSuiteTH());
    srunner_add_suite(runner, TSuiteSh());
    srunner_add_suite(runner, TSuiteRPC());
    srunner_add_suite(runner, TSuiteWNet());
    srunner_add_suite(runner, TSuiteReg());
    srunner_add_suite(runner, TSuiteCharSet());
    srunner_add_suite(runner, TSuiteStr());

    srunner_run_all(runner, CK_NORMAL);
    CONST INT errco = srunner_ntests_failed(runner);
    srunner_free(runner);

    _tsystem(_T("TIMEOUT /T 15"));

    return errco;
}
