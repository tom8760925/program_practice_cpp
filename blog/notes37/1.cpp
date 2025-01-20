#include <filesystem>
#include <iostream>
#include <string>

void funcpath(std::string path);
void funcentry(std::string path);
void funciterator(std::string path);
void funcrecursiveiterator(std::string path);
void funcspace_info(std::string path);
void funcfile_type(std::string path);
void funcperms(std::string path);

int main()
{
    return 0;
}
// path
void funcpath(std::string path)
{
    // 輸入位址
    std::filesystem::path str(path);
    // 判斷是否存在
    if (!std::filesystem::exists(str))
    {
        std::cout << "null" << std::endl;
    }
    std::cout << str << std::endl;
}
// directory_entry
void funcentry(std::string path)
{
    // 輸入位址
    std::filesystem::path str(path);
    // 資料夾
    std::filesystem::directory_entry entry(str);
    // 資料夾位置
    std::cout << entry.path() << std::endl;
    // 判斷是否存在
    if (!entry.exists())
    {
        std::cout << "null" << std::endl;
    }
}
// directory_iterator
void funciterator(std::string path)
{
    // 輸入位址
    std::filesystem::path str(path);
    // 資料夾內容
    std::filesystem::directory_iterator iterator(str);
    // 顯示資料夾內容
    for (auto const &dir_entry : iterator)
    {
        std::cout << dir_entry.path() << std::endl;
    }
}
// recursive_directory_iterator
void funcrecursiveiterator(std::string path)
{
    // 輸入位址
    std::filesystem::path str(path);
    // 遞迴的資料夾內容
    std::filesystem::recursive_directory_iterator recursive(str);
    // 顯示資料夾內容
    for (auto const &dir_entry : recursive)
    {
        std::cout << dir_entry << std::endl;
    }
}
// space_info
void funcspace_info(std::string path)
{
    // 輸入位址
    std::filesystem::path str(path);
    // 可用容量
    std::filesystem::space_info space_info = std::filesystem::space(str);
    // 可用的容量
    std::cout << space_info.available << std::endl;
    // 總容量
    std::cout << space_info.capacity << std::endl;
    // 可用的容量
    std::cout << space_info.free << std::endl;
}
// file_type
void funcfile_type(std::string path)
{
    // 輸入位址
    std::filesystem::path str(path);
    // 資料屬性
    std::filesystem::file_status file_status = std::filesystem::status(str);
    // 判斷型態
    switch (file_status.type())
    {
        // 塊設備文件 例如硬碟分區
    case std::filesystem::file_type::block:
        std::cout << "file_type:block" << std::endl;
        break;
        // 字符設備文件 例如硬碟分區
    case std::filesystem::file_type::character:
        std::cout << "file_type:character" << std::endl;
        break;
        // 目錄
    case std::filesystem::file_type::directory:
        std::cout << "file_type:directory" << std::endl;
        break;
        // 命名管道
    case std::filesystem::file_type::fifo:
        std::cout << "file_type:fifo" << std::endl;
        break;
        // 錯誤
    case std::filesystem::file_type::none:
        std::cout << "file_type:none" << std::endl;
        break;
        // 沒有找到檔案
    case std::filesystem::file_type::not_found:
        std::cout << "file_type:not_found" << std::endl;
        break;
        // 檔案
    case std::filesystem::file_type::regular:
        std::cout << "file_type:regular" << std::endl;
        break;
        // 網路通訊文件
    case std::filesystem::file_type::socket:
        std::cout << "file_type:regular" << std::endl;
        break;
        // 連結檔 例如捷徑
    case std::filesystem::file_type::symlink:
        std::cout << "file_type:regular" << std::endl;
        break;
        // 不確定型態
    case std::filesystem::file_type::unknown:
        std::cout << "file_type:unknown" << std::endl;
        break;
    default:
        std::cout << "file_type" << std::endl;
        break;
    }
}
// perms
void funcperms(std::string path)
{
    // 輸入位址
    std::filesystem::path str(path);
    // 資料屬性
    std::filesystem::file_status file_status = std::filesystem::status(str);
    // 資料許可權
    switch (file_status.permissions())
    {
        // 全部都許可
    case std::filesystem::perms::all:
        std::cout << "perms::all" << std::endl;
        break;
    case std::filesystem::perms::group_all:
        std::cout << "perms::group_all" << std::endl;
        break;
    case std::filesystem::perms::others_all:
        std::cout << "perms::others_all" << std::endl;
        break;
    case std::filesystem::perms::owner_all:
        std::cout << "perms::owner_all" << std::endl;
        break;
        // 全部許可權欄位
    case std::filesystem::perms::mask:
        std::cout << "perms::mask" << std::endl;
        break;
        // 未設置許可權
    case std::filesystem::perms::none:
        std::cout << "perms::none" << std::endl;
        break;
        // 未知許可權
    case std::filesystem::perms::unknown:
        std::cout << "perms::unknown" << std::endl;
        break;
    default:
        std::cout << "perms" << std::endl;
        break;
    }
}
