
// TestSelfProctectDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestSelfProctect.h"
#include "TestSelfProctectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestSelfProctectDlg �Ի���




CTestSelfProctectDlg::CTestSelfProctectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestSelfProctectDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestSelfProctectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestSelfProctectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(SET_TRUST_PID, &CTestSelfProctectDlg::OnBnClickedTrustPid)
	ON_BN_CLICKED(SET_FILE_PATH, &CTestSelfProctectDlg::OnBnClickedFilePath)
	ON_BN_CLICKED(SET_REG_PATH, &CTestSelfProctectDlg::OnBnClickedRegPath)
	ON_BN_CLICKED(SET_PID_PROTECT_ON, &CTestSelfProctectDlg::OnBnClickedPidProtectOn)
	ON_BN_CLICKED(SET_PID_PROTECT_OFF, &CTestSelfProctectDlg::OnBnClickedPidProtectOff)
	ON_BN_CLICKED(SET_FILE_PROTECT_ON, &CTestSelfProctectDlg::OnBnClickedFileProtectOn)
	ON_BN_CLICKED(SET_FILE_PROTECT_OFF, &CTestSelfProctectDlg::OnBnClickedFileProtectOff)
	ON_BN_CLICKED(SET_REG_PROTECT_ON, &CTestSelfProctectDlg::OnBnClickedRegProtectOn)
	//ON_BN_CLICKED(UNINSTALL_DRV, &CTestSelfProctectDlg::OnBnClickedDrv)
	//ON_BN_CLICKED(UNINSTALL_DRIVER, &CTestSelfProctectDlg::OnBnClickedDriver)
	ON_BN_CLICKED(ID_INSTALL_DRIVER, &CTestSelfProctectDlg::OnBnClickedInstallDriver)
	ON_BN_CLICKED(ID_UNINSTALL_DRIVER, &CTestSelfProctectDlg::OnBnClickedUninstallDriver)
	ON_BN_CLICKED(SET_REG_PROTECT_OFF, &CTestSelfProctectDlg::OnBnClickedRegProtectOff)
END_MESSAGE_MAP()


// CTestSelfProctectDlg ��Ϣ��������

BOOL CTestSelfProctectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ����Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestSelfProctectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestSelfProctectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTestSelfProctectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#include "DriverInterface.h"
Trust_Pid_Vector gPidVector;
Path_Node_Vector gFileVector;
Path_Node_Vector gRegVector;

void CTestSelfProctectDlg::OnBnClickedTrustPid()
{
	// TODO: Add your control notification handler code here
	CString strPid_1;
	CString strPid_2;
	GetDlgItem(PID_1)->GetWindowText(strPid_1);
	GetDlgItem(PID_2)->GetWindowText(strPid_2);
	gPidVector.push_back(_wtoi(strPid_1.GetBuffer()));
	gPidVector.push_back(_wtoi(strPid_2.GetBuffer()));
	BOOL bRet = SetTrustPid(gPidVector);
	if (bRet)
	{
		AfxMessageBox(_T("Set trust pid sucess!!"));
	}
	else
	{
		AfxMessageBox(_T("Set trust pid faid!!!!"));
	}
}


void CTestSelfProctectDlg::OnBnClickedFilePath()
{
	// TODO: Add your control notification handler code here
	gFileVector.clear();
	CString strFilePath_1;
	CString strFilePath_2;
	GetDlgItem(FILE_PATH1)->GetWindowText(strFilePath_1);
	GetDlgItem(FILE_PATH2)->GetWindowText(strFilePath_2);
	PROTECT_PATH_NODE PathNode;
	//
	memset(&PathNode,0,sizeof(PROTECT_PATH_NODE));
	PathNode.Access = 0;
	PathNode.PathLeng = strFilePath_1.GetLength()*sizeof(TCHAR);
	if (PathNode.PathLeng > MAX_PATH_LENGTH)
	{
		AfxMessageBox(_T("Error: file path too leng!!!!"));
		gFileVector.clear();
		return;
	}
	memcpy(PathNode.Path,strFilePath_1.GetBuffer(),PathNode.PathLeng);

	//
	memset(&PathNode,0,sizeof(PROTECT_PATH_NODE));
	PathNode.Access = 0;
	PathNode.PathLeng = strFilePath_2.GetLength()*sizeof(TCHAR);
	if (PathNode.PathLeng > MAX_PATH_LENGTH)
	{
		AfxMessageBox(_T("Error: file path too leng!!!!"));
		gFileVector.clear();
		return;
	}
	memcpy(PathNode.Path,strFilePath_2.GetBuffer(),PathNode.PathLeng);

	BOOL bRet = SetProctFilePath(gFileVector);
	if (bRet)
	{
		AfxMessageBox(_T("Set protect files sucess!!"));
	}
	else
	{
		AfxMessageBox(_T("Set protect files faid!!!!"));
	}
}


void CTestSelfProctectDlg::OnBnClickedRegPath()
{
	// TODO: Add your control notification handler code here
	gRegVector.clear();
	CString strRegPath_1;
	CString strRegPath_2;
	GetDlgItem(FILE_PATH1)->GetWindowText(strRegPath_1);
	GetDlgItem(FILE_PATH2)->GetWindowText(strRegPath_2);
	PROTECT_PATH_NODE PathNode;
	//
	memset(&PathNode,0,sizeof(PROTECT_PATH_NODE));
	PathNode.Access = 0;
	PathNode.PathLeng = strRegPath_1.GetLength()*sizeof(TCHAR);
	if (PathNode.PathLeng > MAX_PATH_LENGTH)
	{
		AfxMessageBox(_T("Error: file path too leng!!!!"));
		gRegVector.clear();
		return;
	}
	memcpy(PathNode.Path,strRegPath_1.GetBuffer(),PathNode.PathLeng);

	//
	memset(&PathNode,0,sizeof(PROTECT_PATH_NODE));
	PathNode.Access = 0;
	PathNode.PathLeng = strRegPath_2.GetLength()*sizeof(TCHAR);
	if (PathNode.PathLeng > MAX_PATH_LENGTH)
	{
		AfxMessageBox(_T("Error: file path too leng!!!!"));
		gRegVector.clear();
		return;
	}
	memcpy(PathNode.Path,strRegPath_2.GetBuffer(),PathNode.PathLeng);

	BOOL bRet = SetProctRegPath(gRegVector);
	if (bRet)
	{
		AfxMessageBox(_T("Set protect files sucess!!"));
	}
	else
	{
		AfxMessageBox(_T("Set protect files faid!!!!"));
	}
}


void CTestSelfProctectDlg::OnBnClickedPidProtectOn()
{
	// TODO: Add your control notification handler code here
	BOOL bRet = EnablePidProctect();
	if (bRet)
	{
		AfxMessageBox(_T("turn on pid protect sucess!!"));
	}
	else
	{
		AfxMessageBox(_T("turn on pid protect faild!"));
	}
}


void CTestSelfProctectDlg::OnBnClickedPidProtectOff()
{
	// TODO: Add your control notification handler code here
	BOOL bRet = DisablePidProctect();
	if (bRet)
	{
		AfxMessageBox(_T("turn off pid protect sucess!!"));
	}
	else
	{
		AfxMessageBox(_T("turn off pid protect faild!"));
	}
}


void CTestSelfProctectDlg::OnBnClickedFileProtectOn()
{
	// TODO: Add your control notification handler code here
	BOOL bRet = EnableFileProctect();
	if (bRet)
	{
		AfxMessageBox(_T("turn on file protect sucess!!"));
	}
	else
	{
		AfxMessageBox(_T("turn on file protect faild!"));
	}
}


void CTestSelfProctectDlg::OnBnClickedFileProtectOff()
{
	// TODO: Add your control notification handler code here
	BOOL bRet = DisableFileProctect();
	if (bRet)
	{
		AfxMessageBox(_T("turn off file protect sucess!!"));
	}
	else
	{
		AfxMessageBox(_T("turn off file protect faild!"));
	}
}


void CTestSelfProctectDlg::OnBnClickedRegProtectOn()
{
	// TODO: Add your control notification handler code here
	BOOL bRet = EnableRegProctect();
	if (bRet)
	{
		AfxMessageBox(_T("turn on reg protect sucess!!"));
	}
	else
	{
		AfxMessageBox(_T("turn on reg protect faild!"));
	}
}


void CTestSelfProctectDlg::OnBnClickedRegProtectOff()
{
	// TODO: Add your control notification handler code here
	BOOL bRet = DisableRegProctect();
	if (bRet)
	{
		AfxMessageBox(_T("turn off reg protect sucess!!"));
	}
	else
	{
		AfxMessageBox(_T("turn off reg protect faild!"));
	}
}

BOOL UnInstallMiniFilerDriver()
{
	return UnInstallService(CloudSelfpDriverServiceName);
}

BOOL InstallMiniFilerDriver()
{
	BOOL bRet = FALSE;
	TCHAR SystemDir[MAX_PATH]={0};
	::GetSystemDirectory(SystemDir,MAX_PATH);
	CString strDesDriverPath=SystemDir;
	strDesDriverPath +=_T("\\drivers\\SelfProtect.sys");

	CString strBinaryName = strDesDriverPath;

#ifdef _AMD64_
	CString strDriverName = _T("SelfProtect_x64.sys");
#else
	CString strDriverName = _T("SelfProtect.sys");
#endif

	TCHAR CurrentDir[MAX_PATH]={0};
	::GetCurrentDirectory(MAX_PATH,CurrentDir);
	CString strSrcDriverPath =CurrentDir;
	strSrcDriverPath += strDriverName;
	OutputDebugString(strSrcDriverPath);
	OutputDebugString(_T("\n"));
	OutputDebugString(strDesDriverPath);
	::CopyFile(strSrcDriverPath.GetBuffer(),strDesDriverPath.GetBuffer(),FALSE);

	bRet = InstallMiniFilterDriver(strBinaryName.GetBuffer());
	if (bRet)
	{
		OutputDebugString(_T("InstallVsecDriver: install vsec driver sucess!!\n"));
	}
	else
	{
		OutputDebugString(_T("InstallVsecDriver: install vsec driver faild!!!!!\n"));
	}

	return bRet;
}

void CTestSelfProctectDlg::OnBnClickedInstallDriver()
{
	// TODO: Add your control notification handler code here
	BOOL bRet = InstallMiniFilerDriver();
	if (bRet) 
	{
		AfxMessageBox(_T("driver install sucess!!!"));
	}
	else
	{
		AfxMessageBox(_T("driver install faild!!!"));
	}
}

void CTestSelfProctectDlg::OnBnClickedUninstallDriver()
{
	// TODO: Add your control notification handler code here
	BOOL bRet = UnInstallMiniFilerDriver();
	if (bRet)
	{
		AfxMessageBox(_T("driver uninstall sucess!!!"));
	}
	else
	{
		AfxMessageBox(_T("driver uninstall faild!!!"));
	}
}

