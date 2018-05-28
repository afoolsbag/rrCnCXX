/** \copyright The MIT License */

#include <stdlib.h>
#include <tchar.h>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <check/check.h>

#include "diag/dbg/errhdl/tsuite_errhdl.h"
#include "diag/dbg/basdbg/tsuite_basdbg.h"
#include "diag/toolhelp/tsuite_toolhelp.h"
#include "net/rpc/tsuite_rpc.h"
#include "net/wnet/tsuite_wnet.h"
#include "ui/i18n/charset/tsuite_charset.h"
#include "ui/res/str/tsuite_str.h"

INT _tmain(INT argc, TCHAR *argv[], TCHAR *envp[])
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);
    UNREFERENCED_PARAMETER(envp);

    SRunner *runner = srunner_create(NULL);

    srunner_add_suite(runner, TSuiteErrHdl());
    srunner_add_suite(runner, TSuiteBasDbg());
    srunner_add_suite(runner, TSuiteToolHelp());
    srunner_add_suite(runner, TSuiteRPC());
    srunner_add_suite(runner, TSuiteWNet());
    srunner_add_suite(runner, TSuiteCharSet());
    srunner_add_suite(runner, TSuiteStr());

    srunner_run_all(runner, CK_NORMAL);
    CONST INT errco = srunner_ntests_failed(runner);
    srunner_free(runner);

    _tsystem(_T("TIMEOUT /T 3"));

    return errco;
}
