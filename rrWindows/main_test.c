/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>

#include "data/lfsys/dirmgmt/test.h"
#include "data/lfsys/dskmgmt/test.h"
#include "data/lfsys/fmgmt/test.h"
#include "diag/dbg/errhdl/test.h"
#include "diag/dbg/basdbg/test.h"
#include "diag/th/test.h"
#include "env/sh/test.h"
#include "net/rpc/test.h"
#include "net/wnet/test.h"
#include "svc/info/reg/test.h"
#include "dtpui/intl/charset/test.h"
#include "dtpui/menurc/str/test.h"
#include "dtpui/menurc/ver/test.h"

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
    srunner_add_suite(runner, TSuiteVer());

    srunner_run_all(runner, CK_NORMAL);
    CONST INT errco = srunner_ntests_failed(runner);
    srunner_free(runner);

    _tsystem(_T("TIMEOUT /T 15"));

    return errco;
}
