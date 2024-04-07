#include <stdio.h>  //載入指令
#include <iostream> //載入指令
#include <string>   //載入指令
#include <vector>   //載入指令
#include <typeinfo> //載入指令
using namespace std;
#ifndef MAX // 定義
#define MAX 2
#endif
namespace student_input // 輸入
{
    class st_input_default // 輸入預設
    {
    public:
        st_input_default(vector<string> sa) : sa(sa) {}
        ~st_input_default()
        {
            cout << "輸入完成" << endl;
        }
        void st_input_cout(int n)
        {
            cout << "請輸入" << this->sa[n] << ":";
        }

    protected:
        vector<string> sa; // 輸入的欄位名稱
    };
    class st_input_add : public st_input_default // 新增
    {
    public:
        using st_input_default::st_input_default;
        template <typename T>
        void st_input_cin(T *s, int n) // 輸入資料
        {
            auto i = *s;
            st_input_cout(n);
            cin >> i;
            *s = i;
            cout << this->sa[n] << ":" << i << endl;
        }
    };
}
namespace student_output // 輸出
{
    class st_output_default // 輸出預設
    {
    public:
        st_output_default(vector<string> sa) : sa(sa) {}
        ~st_output_default()
        {
            cout << "顯示完成" << endl;
        }

    protected:
        vector<string> sa; // 輸出的欄位名稱
    };
    class st_output_show : public st_output_default // 顯示資料
    {
    public:
        using st_output_default::st_output_default;
        template <typename T>
        void st_output_cout(T s, int n) // 顯示欄位資料
        {
            cout << this->sa[n] << ":" << s << endl;
        }
    };

}
struct student // 結構宣告
{
    int id;
    string name;
    int no, score;
    student()
    {
        id = 0;
        name = "";
        no = 0;
        score = 0;
    }
    student(int id) : id(id) {}
    student(int id, string name, int no, int score) : id(id), name(name), no(no), score(score) {}
};
struct visit_type // 判斷資料型態
{
    string type = ""; // 存放資料的型態
    void operator()(const int *t)
    {
        type = "int*";
    }
    void operator()(const int t)
    {
        type = "int";
    }
    void operator()(const string *t)
    {
        type = "string*";
    }
    void operator()(const string t)
    {
        type = "string";
    }
};
void st_input(int n);                // 函數宣告
void st_list(int n);                 // 函數宣告
void st_sumscore(int n);             // 函數宣告
vector<struct student> student_data; // 資料庫
int main()
{
    string cin_if;
    int n = 0;
    bool cin_if_while = true;
    while (cin_if_while)
    {
        cout << "輸入1輸入學生資料(最多輸入" << MAX << "筆資料，現在已經輸入" << n << "筆)\n輸入2計算總成績\n輸入3查看輸入的資料\n輸入4離開\n請輸入半形的1、2、3、4:";
        cin >> cin_if;
        try
        {
            switch (stoi(cin_if))
            {
            case 1:
                if (n < MAX)
                {
                    st_input(n + 1);
                    n++;
                }
                else
                {
                    cout << "已達輸入上限" << endl;
                }
                break;
            case 2:
                if (n > 0)
                {
                    st_sumscore(n);
                }
                else
                {
                    cout << "尚未輸入任何資料" << endl;
                }
                break;
            case 3:
                if (n > 0)
                {
                    st_list(n);
                }
                else
                {
                    cout << "尚未輸入任何資料" << endl;
                }
                break;
            case 4:
                cin_if_while = false;
                cout << "結束" << endl;
                break;
            default:
                cout << "輸入錯誤(請輸入半形的1-4)" << endl;
                break;
            }
        }
        catch (const std::invalid_argument &e) // 輸入了數字以外的的例外
        {
            cout << "輸入錯誤(請輸入半形的1-4)" << endl;
        }
    }
    return 0;
}
void st_input(int n) // 輸入資料
{
    using namespace student_input;
    vector<string> vector_string = {"姓名", "學號", "成績"}; // 欄位名稱
    struct student stud(n);
    struct visit_type vt;
    vector<variant<int *, string *>> vector_student = {&stud.name, &stud.no, &stud.score}; // 資料型態
    st_input_add st(vector_string);
    for (int i = 0; i < (int)vector_string.size(); i++)
    {
        visit(vt, vector_student[i]); // 判斷資料型態
        if (vt.type == "int*")
        {
            st.st_input_cin(get<int *>(vector_student[i]), i); // 資料型態為int
        }
        else if (vt.type == "string*")
        {
            st.st_input_cin(get<string *>(vector_student[i]), i); // 資料型態為string
        }
    }
    student_data.push_back(stud); // 將資料存放到資料庫
}
void st_list(int n) // 顯示資料
{
    using namespace student_output;
    vector<string> vector_string = {"編號", "姓名", "學號", "成績"}; // 欄位名稱
    st_output_show st(vector_string);
    struct visit_type vt;
    for (int i = 0; i < n; i++)
    {
        vector<variant<int, string>> vector_student = {student_data[i].id, student_data[i].name, student_data[i].no, student_data[i].score}; // 資料型態
        for (int ii = 0; ii < (int)vector_string.size(); ii++)
        {
            visit(vt, vector_student[ii]); // 判斷資料型態
            if (vt.type == "int")
            {
                st.st_output_cout(get<int>(vector_student[ii]), ii); // 資料型態為int
            }
            else if (vt.type == "string")
            {
                st.st_output_cout(get<string>(vector_student[ii]), ii); // 資料型態為string
            }
        }
    }
}
void st_sumscore(int n) // 計算總成績
{
    using namespace student_output;
    vector<string> vector_string = {"總成績"}; // 欄位名稱
    st_output_show st(vector_string);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += student_data[i].score;
    }
    st.st_output_cout(sum, 0); // 顯示總成績
}
