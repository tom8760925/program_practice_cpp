#include <iostream> 
using namespace std;
class a
{
    public:
        void pca(){
            cout<<"--pca--\n";
            cout<< "p:"<<pda()<<'\n';
            cout<< "p:"<<pea()<<'\n';
        }
    protected:
        int pda(){
            return 2;
        }
    private:
        int pea(){
            return 3;
        }
};
class b : public a 
{
    public:
        void pcb(){
            pca();
            cout<<"--pcb--\n";
            cout<< "p:"<<pda()<<'\n';
        }
};
class c : protected b 
{
    public:
        void pcc(){
            pcb();
        }
};
class d : private c
{
    public:
        void pcd(){
            pcc();
        }
};
int main(){
    a ca;
    b cb;
    c cc;
    d cd;
    cout<<"--ca--\n";
    ca.pca();
    cout<<"--cb--\n";
    cb.pcb();
    cb.pca();
    cout<<"--cc--\n";
    cc.pcc();//因為控制權限所以不能使用pca
    cout<<"--cd--\n";
    cd.pcd();//因為控制權限所以不能使用pca
    cout<<endl;
    return 0;
}