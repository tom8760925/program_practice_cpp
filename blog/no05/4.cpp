#include <iostream> 
using namespace std;
class a
{
    public:
        a(int n):n(n){}
        void pca(){
            cout<<"p:"<<this->n<<'\n';
        }
    private:
        int n=0;
};
class b :public a
{
    public:
        using a::a;//直接繼承宣告
        void pcb(){
            a::pca();//直接繼承函式
        }
};
class c :public a
{
    using ca=a;//將繼承修改
    public:
        using ca::a;
        void pcc(){
            ca::pca();
        }
};
int main(){
    b cb(1);
    cb.pcb();
    cout<<"----\n";
    c cc(2);
    cc.pcc();
    cout<<endl;
    return 0;
}