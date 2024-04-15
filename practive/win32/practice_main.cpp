#include <windows.h>
#include <atlstr.h>
#include "resource.h"

CString /*支援wchar_t*/ WindowClass(MAKEINTRESOURCE(IDS_WindowClass));//視窗的類別名稱
CString WindowTitle(MAKEINTRESOURCE(IDS_WindowTitle));//視窗的類別名稱
HINSTANCE P_hInstance;
HWND P_hwnd;
ATOM Practice_RegisterClass(HINSTANCE hInstance);
bool Practice_CreateWindow(HINSTANCE hInstance, int nCmdShow);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK box(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool Practice_CreateWindow_button();


//視窗的載入點
int APIENTRY/*這個用來表示應用程式的起始，也可以用其他的像WINAPI代表使用WINAPI*/ wWinMain/*可以是wWinMain或WinMain*/(
    _In_/*表示輸入且不會改值的SAL*/ HINSTANCE hInstance,//此應用程式的實例
    _In_opt_/*表示輸入且不會改值，而且可能是NULL*/ HINSTANCE hPrevInstance,//上一個應用程式的位址，沒有就為null
    _In_ LPWSTR    lpCmdLine,//傳入的參數
    _In_ int       nCmdShow/*視窗的狀態例如視窗最大化*/
)
{
    UNREFERENCED_PARAMETER(hPrevInstance);//就算這個變數沒有使用到也不要顯示警告
    UNREFERENCED_PARAMETER(lpCmdLine);//就算這個變數沒有使用到也不要顯示警告

    Practice_RegisterClass(hInstance);//視窗的類別
    
    if (Practice_CreateWindow(hInstance, nCmdShow))//判斷是否建立成功
    {
        return 0;
    }
    P_hInstance = hInstance;
    if (Practice_CreateWindow_button())//判斷是否建立成功
    {
        return 0;
    }
    MSG msg = { };//視窗訊息
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);//鍵盤訊息
        DispatchMessage(&msg);//分配訊息
    }

    return 0;
}
//視窗的類別
ATOM Practice_RegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex = {};
    wcex.cbSize = sizeof(wcex);//記憶體大小
    wcex.style = CS_HREDRAW | CS_VREDRAW;//行為設定
    wcex.lpfnWndProc = WindowProc; //視窗的事件
    wcex.hInstance = hInstance; //視窗的實例
    wcex.lpszClassName = WindowClass;//視窗的類別名稱
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDR_MENU1);//視窗的Menu名稱
    wcex.hIcon = nullptr;//視窗的圖示
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);//背景的顏色
    return RegisterClassExW(&wcex);
}
//建立視窗
bool Practice_CreateWindow(HINSTANCE hInstance, int nCmdShow) {
    HWND hwnd = CreateWindowW(//建立視窗
        WindowClass,//視窗的類別名稱
        WindowTitle,//視窗的名稱
        WS_OVERLAPPEDWINDOW,//視窗顯示模式
        0,//視窗位置X
        0,//視窗位置Y
        500,//視窗寬度
        400,//視窗高度
        nullptr,//視窗功能
        nullptr,//視窗Menu
        hInstance,//視窗的實例
        nullptr
    );
    if (hwnd == NULL)//判斷是否為NULL
    {
        return true;
    }
    ShowWindow(hwnd, nCmdShow);//顯示視窗
    UpdateWindow(hwnd);//更新視窗
    P_hwnd = hwnd;
    return false;
}
//視窗的事件
LRESULT/*訊息處理的結果*/ CALLBACK /*回傳呼叫*/ WindowProc(
    HWND hwnd,//視窗
    UINT uMsg,//視窗訊息
    WPARAM wParam,//其他訊息信息取決於uMsg
    LPARAM lParam//其他訊息信息取決於uMsg
)
{
    switch (uMsg)//判斷訊息
    {
    case WM_COMMAND://視窗事件
    {
        int wmId = LOWORD(wParam);//取得第二個訊息
        switch (wmId)
        {
        case IDS_WindowClass:
            MessageBox(P_hwnd, L"1", L"2", MB_OK);
            break;
        case ID_Test_Box:
            DialogBox(P_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, box);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);//沒有處理的訊息
        }
    }
    break;
    case WM_DESTROY://視窗關閉
        PostQuitMessage(0);//提出結束代碼
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);//沒有處理的訊息
    }
    return 0;
}
INT_PTR /*訊息處理的結果*/ CALLBACK /*回傳呼叫*/ box(
    HWND hwnd,//視窗
    UINT uMsg,//視窗訊息
    WPARAM wParam,//其他訊息信息取決於uMsg
    LPARAM lParam//其他訊息信息取決於uMsg
)
{
    UNREFERENCED_PARAMETER(lParam);//就算這個變數沒有使用到也不要顯示警告
    switch (uMsg)
    {
    case WM_INITDIALOG://小視窗建置後，顯示出來前的訊息
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK/*小視窗中的按鈕*/ || LOWORD(wParam) == IDCANCEL/*取消按鈕也就是X*/)
        {
            EndDialog(hwnd, LOWORD(wParam));//關閉小視窗
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
bool Practice_CreateWindow_button() {
    HWND hwnd = CreateWindowW(//建立視窗
        L"BUTTON",//視窗的類別名稱
        L"OK",//視窗的名稱
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,//視窗顯示模式
        10,//視窗位置X
        10,//視窗位置Y
        100,//視窗寬度
        100,//視窗高度
        P_hwnd,//視窗功能
        (HMENU)MAKEINTRESOURCE(IDS_WindowClass),//視窗Menu
        P_hInstance,//視窗的實例
        nullptr
    );
    if (hwnd == NULL)//判斷是否為NULL
    {
        return true;
    }
    return false;
}
INT_PTR /*訊息處理的結果*/ CALLBACK /*回傳呼叫*/ Practice_button(
    HWND hwnd,//視窗
    UINT uMsg,//視窗訊息
    WPARAM wParam,//其他訊息信息取決於uMsg
    LPARAM lParam//其他訊息信息取決於uMsg
)
{
    UNREFERENCED_PARAMETER(lParam);//就算這個變數沒有使用到也不要顯示警告
    switch (uMsg)
    {
    case WM_INITDIALOG://小視窗建置後，顯示出來前的訊息
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
        if (LOWORD(wParam) == IDOK/*小視窗中的按鈕*/ || LOWORD(wParam) == IDCANCEL/*取消按鈕也就是X*/)
        {
            EndDialog(hwnd, LOWORD(wParam));//關閉小視窗
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}