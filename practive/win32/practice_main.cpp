#include <windows.h>
#include <atlstr.h>
#include "resource.h"

CString /*�䴩wchar_t*/ WindowClass(MAKEINTRESOURCE(IDS_WindowClass));//���������O�W��
CString WindowTitle(MAKEINTRESOURCE(IDS_WindowTitle));//���������O�W��
HINSTANCE P_hInstance;
HWND P_hwnd;
ATOM Practice_RegisterClass(HINSTANCE hInstance);
bool Practice_CreateWindow(HINSTANCE hInstance, int nCmdShow);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK box(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool Practice_CreateWindow_button();


//���������J�I
int APIENTRY/*�o�ӥΨӪ�����ε{�����_�l�A�]�i�H�Ψ�L����WINAPI�N��ϥ�WINAPI*/ wWinMain/*�i�H�OwWinMain��WinMain*/(
    _In_/*��ܿ�J�B���|��Ȫ�SAL*/ HINSTANCE hInstance,//�����ε{�������
    _In_opt_/*��ܿ�J�B���|��ȡA�ӥB�i��ONULL*/ HINSTANCE hPrevInstance,//�W�@�����ε{������}�A�S���N��null
    _In_ LPWSTR    lpCmdLine,//�ǤJ���Ѽ�
    _In_ int       nCmdShow/*���������A�Ҧp�����̤j��*/
)
{
    UNREFERENCED_PARAMETER(hPrevInstance);//�N��o���ܼƨS���ϥΨ�]���n���ĵ�i
    UNREFERENCED_PARAMETER(lpCmdLine);//�N��o���ܼƨS���ϥΨ�]���n���ĵ�i

    Practice_RegisterClass(hInstance);//���������O
    
    if (Practice_CreateWindow(hInstance, nCmdShow))//�P�_�O�_�إߦ��\
    {
        return 0;
    }
    P_hInstance = hInstance;
    if (Practice_CreateWindow_button())//�P�_�O�_�إߦ��\
    {
        return 0;
    }
    MSG msg = { };//�����T��
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);//��L�T��
        DispatchMessage(&msg);//���t�T��
    }

    return 0;
}
//���������O
ATOM Practice_RegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex = {};
    wcex.cbSize = sizeof(wcex);//�O����j�p
    wcex.style = CS_HREDRAW | CS_VREDRAW;//�欰�]�w
    wcex.lpfnWndProc = WindowProc; //�������ƥ�
    wcex.hInstance = hInstance; //���������
    wcex.lpszClassName = WindowClass;//���������O�W��
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDR_MENU1);//������Menu�W��
    wcex.hIcon = nullptr;//�������ϥ�
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);//�I�����C��
    return RegisterClassExW(&wcex);
}
//�إߵ���
bool Practice_CreateWindow(HINSTANCE hInstance, int nCmdShow) {
    HWND hwnd = CreateWindowW(//�إߵ���
        WindowClass,//���������O�W��
        WindowTitle,//�������W��
        WS_OVERLAPPEDWINDOW,//������ܼҦ�
        0,//������mX
        0,//������mY
        500,//�����e��
        400,//��������
        nullptr,//�����\��
        nullptr,//����Menu
        hInstance,//���������
        nullptr
    );
    if (hwnd == NULL)//�P�_�O�_��NULL
    {
        return true;
    }
    ShowWindow(hwnd, nCmdShow);//��ܵ���
    UpdateWindow(hwnd);//��s����
    P_hwnd = hwnd;
    return false;
}
//�������ƥ�
LRESULT/*�T���B�z�����G*/ CALLBACK /*�^�ǩI�s*/ WindowProc(
    HWND hwnd,//����
    UINT uMsg,//�����T��
    WPARAM wParam,//��L�T���H�����M��uMsg
    LPARAM lParam//��L�T���H�����M��uMsg
)
{
    switch (uMsg)//�P�_�T��
    {
    case WM_COMMAND://�����ƥ�
    {
        int wmId = LOWORD(wParam);//���o�ĤG�ӰT��
        switch (wmId)
        {
        case IDS_WindowClass:
            MessageBox(P_hwnd, L"1", L"2", MB_OK);
            break;
        case ID_Test_Box:
            DialogBox(P_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, box);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);//�S���B�z���T��
        }
    }
    break;
    case WM_DESTROY://��������
        PostQuitMessage(0);//���X�����N�X
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);//�S���B�z���T��
    }
    return 0;
}
INT_PTR /*�T���B�z�����G*/ CALLBACK /*�^�ǩI�s*/ box(
    HWND hwnd,//����
    UINT uMsg,//�����T��
    WPARAM wParam,//��L�T���H�����M��uMsg
    LPARAM lParam//��L�T���H�����M��uMsg
)
{
    UNREFERENCED_PARAMETER(lParam);//�N��o���ܼƨS���ϥΨ�]���n���ĵ�i
    switch (uMsg)
    {
    case WM_INITDIALOG://�p�����ظm��A��ܥX�ӫe���T��
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK/*�p�����������s*/ || LOWORD(wParam) == IDCANCEL/*�������s�]�N�OX*/)
        {
            EndDialog(hwnd, LOWORD(wParam));//�����p����
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
bool Practice_CreateWindow_button() {
    HWND hwnd = CreateWindowW(//�إߵ���
        L"BUTTON",//���������O�W��
        L"OK",//�������W��
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,//������ܼҦ�
        10,//������mX
        10,//������mY
        100,//�����e��
        100,//��������
        P_hwnd,//�����\��
        (HMENU)MAKEINTRESOURCE(IDS_WindowClass),//����Menu
        P_hInstance,//���������
        nullptr
    );
    if (hwnd == NULL)//�P�_�O�_��NULL
    {
        return true;
    }
    return false;
}
INT_PTR /*�T���B�z�����G*/ CALLBACK /*�^�ǩI�s*/ Practice_button(
    HWND hwnd,//����
    UINT uMsg,//�����T��
    WPARAM wParam,//��L�T���H�����M��uMsg
    LPARAM lParam//��L�T���H�����M��uMsg
)
{
    UNREFERENCED_PARAMETER(lParam);//�N��o���ܼƨS���ϥΨ�]���n���ĵ�i
    switch (uMsg)
    {
    case WM_INITDIALOG://�p�����ظm��A��ܥX�ӫe���T��
        return (INT_PTR)TRUE;
    case WM_NOTIFY:
        switch (((LPNMHDR)lParam)->code)
        {
        case BCN_DROPDOWN:
        {
            NMBCDROPDOWN* pDropDown = (NMBCDROPDOWN*)lParam;
            if (pDropDown->hdr.hwndFrom = GetDlgItem(hDlg, IDC_SPLIT))
            {

                // Get screen coordinates of the button.
                POINT pt;
                pt.x = pDropDown->rcButton.left;
                pt.y = pDropDown->rcButton.bottom;
                ClientToScreen(pDropDown->hdr.hwndFrom, &pt);

                // Create a menu and add items.
                HMENU hSplitMenu = CreatePopupMenu();
                AppendMenu(hSplitMenu, MF_BYPOSITION, IDC_MENUCOMMAND1, L"Menu item 1");
                AppendMenu(hSplitMenu, MF_BYPOSITION, IDC_MENUCOMMAND2, L"Menu item 2");

                // Display the menu.
                TrackPopupMenu(hSplitMenu, TPM_LEFTALIGN | TPM_TOPALIGN, pt.x, pt.y, 0, hDlg, NULL);
                return TRUE;
            }
            break;
        }
        }
        return FALSE;
    }
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK/*�p�����������s*/ || LOWORD(wParam) == IDCANCEL/*�������s�]�N�OX*/)
        {
            EndDialog(hwnd, LOWORD(wParam));//�����p����
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}