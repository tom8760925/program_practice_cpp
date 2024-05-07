#include <iostream> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;
void sf();//收尋
void ii();//新增
void us();//修改
void df();//刪除
string ip = "tcp://localhost:3306";
string user = "root";
string password = "password";
int main()
{
    sf();
}
void sf() {
    try {
        sql::mysql::MySQL_Driver* driver;//宣告
        sql::Connection* con;//宣告
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(ip, user, password);//輸入IP、USER、PASSWORD
        con->setSchema("test");//輸入資料庫名稱
        sql::Statement* stmt;//宣告
        stmt = con->createStatement();//啟動連接
        string selectDataSQL = "SELECT * FROM tests";//SQL語法
        sql::ResultSet* res = stmt->executeQuery(selectDataSQL);//執行SQL語法
        int count = 1;
        while (res->next()) {//依照每一筆輸出
            cout << "id" << ":" << res->getString("id") << '\n';
            cout << "v" << ":" << res->getString("v") << '\n';
            cout << "i" << ":" << res->getString("i") << '\n';
            cout << "ii" << ":" << res->getString("ii") << '\n';
            cout << "count:"<<count++<<"-----" << endl;
        }
        delete res;//關閉
        delete stmt;//關閉
        delete con;//關閉
    }
    catch (sql::SQLException& e) {//錯誤
        std::cerr << "SQL Error: " << e.what() << std::endl;//錯誤輸出
    }
}
void ii() {
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(ip, user, password);
        con->setSchema("test");
        sql::Statement* stmt;
        stmt = con->createStatement();
        string i
            = "INSERT INTO tests (v,i,ii) VALUES ('C', 3, 3)";
        stmt->execute(i);//
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}
void us() {
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(ip, user, password);
        con->setSchema("test");
        sql::Statement* stmt;
        stmt = con->createStatement();
        string u
            = "UPDATE tests SET ii=3 WHERE id='2'";
        stmt->executeUpdate(u);
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}
void df() {
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(ip, user, password);
        con->setSchema("test");
        sql::Statement* stmt;
        stmt = con->createStatement();
        string d
            = "DELETE FROM tests WHERE id='3'";
        stmt->execute(d);
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

