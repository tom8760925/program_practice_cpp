#include <stdio.h>
#include <iostream>

#include <curl/curl.h>
#include <curl/easy.h>

// 處理資料
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    // 資料大小
    size_t realsize = size * nmemb;
    // 宣告接收資料的變數的指標
    std::string *str = static_cast<std::string *>(userp);
    // 新增取得的資料
    str->append(static_cast<char *>(contents), realsize);
    // 回傳
    return realsize;
}
int main(int argc, const char *argv[])
{
    // 宣告
    CURL *curl;
    // curl執行狀態
    CURLcode res;
    // 宣告接收變數
    std::string s;
    // 初始化libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    // 初始化curl
    curl = curl_easy_init();
    // 判斷是否正常
    if (curl)
    {
        // 使用網址
        curl_easy_setopt(curl, CURLOPT_URL, "url");
        // 設定使用get或post
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        // 設定回調函數
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &WriteCallback);
        // 設定接收變數
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        // 執行
        res = curl_easy_perform(curl);
    }
    // 關閉curl
    curl_easy_cleanup(curl);
}