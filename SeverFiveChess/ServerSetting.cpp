// ServerSetting.cpp : implementation file
//

#include "stdafx.h"
#include "SrvFiveChess.h"
#include "ServerSetting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerSetting dialog
CServerSetting::CServerSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CServerSetting::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerSetting)
	m_HostName = _T("");
	m_Port = 0;
	m_NickName = _T("");
	//}}AFX_DATA_INIT
}


void CServerSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerSetting)
	DDX_Text(pDX, IDC_HOSTNAME, m_HostName);
	DDX_Text(pDX, IDC_PORT, m_Port);
	DDX_Text(pDX, IDC_NICKNAME, m_NickName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CServerSetting, CDialog)
	//{{AFX_MSG_MAP(CServerSetting)
	ON_BN_CLICKED(IDC_SET, OnSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CServerSetting message handlers

void CServerSetting::OnOK() 
{

}

void CServerSetting::OnSet() 
{
	UpdateData();
	EndDialog(IDOK);
}

BOOL CServerSetting::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//获取主机名称
	char host[MAX_PATH];
	gethostname(host,MAX_PATH);//获取主机名称
	m_HostName = host;
	//MessageBox(m_HostName);
	hostent* phost = gethostbyname(host);//获取主机的IP地址
	m_HostIP = "";
	if (phost)
	{
		char* pIP = inet_ntoa(*(in_addr*)phost->h_addr_list[0]);//将所获取的IP地址转换为点分十进制数 
		m_HostIP = pIP;
	}
	/*MessageBox(m_HostName);
	MessageBox(m_HostIP);*/
	UpdateData(FALSE);
	return TRUE;
}
