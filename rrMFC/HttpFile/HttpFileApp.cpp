/// \copyright The MIT License

#include "stdafx.h"
#include "HttpFileApp.h"

#include <memory>

namespace {

/// \brief 超文本传输协议上传文件
///
/// \param url      统一资源定位符
/// \param filepath 文件路径
/// \return 成功与否
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cfile-class
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cfile-class#open
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cfile-class#getlength
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cfile-class#read
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cfile-class#close
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cinternetsession-class
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cinternetsession-class#setoption
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cinternetsession-class#gethttpconnection
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cinternetsession-class#close
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/chttpconnection-class
/// \sa https://docs.microsoft.com/cpp/mfc/reference/chttpconnection-class#openrequest
///
/// \sa https://docs.microsoft.com/cpp/mfc/reference/chttpfile-class
/// \sa https://docs.microsoft.com/cpp/mfc/reference/chttpfile-class#sendrequest
/// \sa https://docs.microsoft.com/cpp/mfc/reference/chttpfile-class#queryinfostatuscode
/// \sa https://docs.microsoft.com/cpp/mfc/reference/cinternetfile-class#close
BOOL HttpUploadFile(PCTSTR url, PCTSTR filepath)
{
    // 输入检查

    _tcprintf_s(TEXT("The url is \"%s\".\n"), url);
    if (!_tcsclen(url))
        return FALSE;

    _tcprintf_s(TEXT("The file path is \"%s\".\n"), filepath);
    if (!_tcsclen(filepath))
        return FALSE;

    if (!PathFileExists(filepath) || PathIsDirectory(filepath))
        return FALSE;

    CFile file;
    CONST INT kFileChunkSize = 1024;
    UINT8 filechunk[kFileChunkSize];

    CInternetSession httpsession;
    CHttpConnection *httpconnection = NULL;
    CHttpFile *httpfile = NULL;

    enum {
        NONE,
        NEED_CLOSE_FILE,
        NEED_CLOSE_HTTP_SESSION,
        NEED_CLOSE_HTTP_CONNECTION,
        NEED_CLOSE_HTTP_FILE
    } stus = NONE;
    BOOL succeed;
    do {

        // 解析URL

        DWORD urltype;
        CString urlserver;
        CString urlobject;
        INTERNET_PORT urlport;
        if (!AfxParseURL(url, urltype, urlserver, urlobject, urlport)) {
            succeed = FALSE;
            break;
        }

        // 打开文件

        if (!file.Open(filepath, CFile::modeRead | CFile::shareDenyNone)) {
            succeed = FALSE;
            break;
        }
        stus = NEED_CLOSE_FILE;

        INT filelen;  // file length
        if ((filelen = file.GetLength()) == 0) {
            succeed = FALSE;
            break;
        }

        // 创建HTTP会话

        httpsession.SetOption(INTERNET_OPTION_CONNECT_TIMEOUT, 5000);  // 超时
        httpsession.SetOption(INTERNET_OPTION_CONNECT_RETRIES, 1);     // 重试
        stus = NEED_CLOSE_HTTP_SESSION;

        // 连接服务器

        try {
            httpconnection = httpsession.GetHttpConnection(urlserver, urlport);
        } catch (CInternetException *e) {
            e->Delete();
            succeed = FALSE;
            break;
        }
        stus = NEED_CLOSE_HTTP_CONNECTION;

        // 开启请求并发送数据

        httpfile = httpconnection->OpenRequest(CHttpConnection::HTTP_VERB_POST, urlobject);
        stus = NEED_CLOSE_HTTP_FILE;

        CString boundary = TEXT("-------------http-boundary-")
            + CTime::GetCurrentTime().Format(TEXT("%Y-%m-%dT%H:%M:%S"))
            + TEXT("-zl11073902");
        CString header = TEXT("Content-Type: multipart/form-data; boundary=")
            + boundary + TEXT("\r\n");
        httpfile->AddRequestHeaders(header);

        httpfile->SendRequestEx(filelen, HSR_SYNC | HSR_INITIATE);

        INT chunklen;
        do {
            chunklen = file.Read(filechunk, kFileChunkSize);
            if (0 == chunklen)
                break;
            httpfile->Write(filechunk, chunklen);
        } while (TRUE);

        httpfile->EndRequest(HSR_SYNC);

        // 查询状态

        DWORD httpstus;
        httpfile->QueryInfoStatusCode(httpstus);
        _tcprintf_s(TEXT("The httpstus code is \"%i\".\n"), httpstus);

        succeed = httpstus == HTTP_STATUS_OK;

    } while (FALSE);
    switch (stus) {
    case NEED_CLOSE_HTTP_FILE: httpfile->Close(); //fallthrough
    case NEED_CLOSE_HTTP_CONNECTION: httpconnection->Close(); //fallthrough
    case NEED_CLOSE_HTTP_SESSION: httpsession.Close(); //fallthrough
    case NEED_CLOSE_FILE: file.Close(); //fallthrough
    case NONE: break;
    }

    return succeed;
}

}// namseapce

BOOL CHttpFileApp::InitInstance()
{
    CWinApp::InitInstance();

    if (!AllocConsole()) {
        AfxMessageBox(TEXT("Alloc console failed."));
        return FALSE;
    }

    HttpUploadFile(TEXT("http://192.168.101.121:5000/tmp?filename=testfile.txt"), TEXT("D:\\testfile.txt"));
    Sleep(10000);
    FreeConsole();
    return FALSE;
}
