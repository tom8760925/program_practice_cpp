#include <filesystem>
#include <iostream>
#include <string>

int main()
{
    std::cout << "===絕對路徑===" << std::endl;
    // 現在所在位置
    std::cout << std::filesystem::current_path() << std::endl;
    // 檔案絕對位置
    std::cout << std::filesystem::absolute("test.txt") << std::endl;

    std::cout << "===規範路徑===" << std::endl;
    // 顯示檔案絕對路徑
    std::cout << std::filesystem::canonical("../1.cpp") << std::endl;
    // 顯示檔案絕對路徑
    std::cout << std::filesystem::weakly_canonical("../1.cpp") << std::endl;

    std::cout << "===相對路徑===" << std::endl;
    // 顯示檔案相對路徑
    std::cout << std::filesystem::relative("/Users/tomku/Desktop/program_practice_cpp/blog/notes37/output/test.txt") << std::endl;
    // 顯示檔案相對路徑
    std::cout << std::filesystem::proximate("/Users/tomku/Desktop/program_practice_cpp/blog/notes37/output/test.txt") << std::endl;

    std::cout << "===刪除===" << std::endl;
    // 刪圖單的檔案或資聊夾
    std::filesystem::remove("test1.txt");
    // 刪圖檔案或資聊夾包含以內的
    std::filesystem::remove_all("test1.txt");

    std::cout << "===複製===" << std::endl;
    // 複製檔案或目錄 如果已經有檔案會錯誤
    std::filesystem::copy("test.txt", "test1.txt");
    // 複製檔案 如果已經有檔案會錯誤
    // std::filesystem::copy_file("test.txt", "test1.txt");
    // 複製連結檔 如果已經有檔案會錯誤
    // std::filesystem::copy_symlink("test.txt", "test1.txt");
    // 顯示檔案絕對路徑
    std::cout << std::filesystem::canonical("test.txt") << std::endl;
    std::cout << std::filesystem::canonical("test1.txt") << std::endl;

    std::cout << "===新增===" << std::endl;
    // 新增單個資料夾 如果有不會跳錯誤
    std::filesystem::create_directory("test1");
    std::cout << std::filesystem::canonical("test1") << std::endl;
    // 新增多個資料夾 如果有不會跳錯誤
    std::filesystem::create_directories("test2/test2");
    std::cout << std::filesystem::canonical("test2/test2") << std::endl;

    std::cout << "===比對路徑===" << std::endl;
    // 比對路徑是否相同
    if (std::filesystem::equivalent(".", std::filesystem::current_path()))
    {
        std::cout << "yes" << std::endl;
    }

    std::cout << "===檔案大小===" << std::endl;
    // 檔案大小
    std::cout << std::filesystem::file_size("test.txt") << std::endl;

    std::cout << "===檔案修改時間===" << std::endl;
    std::filesystem::file_time_type file_time_type = std::filesystem::last_write_time("test.txt");

    std::cout << "===檔案修改名稱===" << std::endl;
    // 修改名稱
    std::filesystem::rename("test1.txt", "test2.txt");
    std::cout << std::filesystem::canonical("test2.txt") << std::endl;

    return 0;
}