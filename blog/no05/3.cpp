#include <iostream> 
using namespace std;
class a
{
    public:
        a()=default;//設定預設
        a(int n):n(n){}
        a(int n1,int n2){
            this->n=n1+n2;
        }
        a(const a&)=delete;//將這個宣告禁止，例ca1=ca2不能用。
        void pca(){
            cout<<"p:"<<this->n<<'\n';
        }
    private:
        int n=0;
};
int main(){
    a ca1;
    ca1.pca();
    a ca2(1);
    ca2.pca();
    a ca3(1,2);
    ca3.pca();
    cout<<endl;
    return 0;
}