/** \copyright The MIT License */

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>

#include <check/check.h>

#include "data/lfsys/dirmgmt/_test.h"
#include "data/lfsys/dskmgmt/_test.h"
#include "data/lfsys/fmgmt/_test.h"
#include "diag/dbg/errhdl/_test.h"
#include "diag/dbg/basdbg/_test.h"
#include "diag/th/_test.h"
#include "dtpui/intl/charset/_test.h"
#include "dtpui/menurc/str/_test.h"
#include "dtpui/menurc/ver/_test.h"
#include "env/cons/_test.h"
#include "env/sh/_test.h"
#include "net/rpc/_test.h"
#include "net/wnet/_test.h"
#include "svc/info/reg/_test.h"
#include "svc/sync/_test.h"

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
    srunner_add_suite(runner, TSuiteCharSet());
    srunner_add_suite(runner, TSuiteStr());
    srunner_add_suite(runner, TSuiteVer());
    srunner_add_suite(runner, TSuiteCons());
    srunner_add_suite(runner, TSuiteSh());
    srunner_add_suite(runner, TSuiteRPC());
    srunner_add_suite(runner, TSuiteWNet());
    srunner_add_suite(runner, TSuiteReg());
    srunner_add_suite(runner, TSuiteSync());
    srunner_run_all(runner, CK_NORMAL);
    CONST INT errco = srunner_ntests_failed(runner);
    srunner_free(runner);

    _tsystem(_T("TIMEOUT /T 15"));

    return errco;
}
