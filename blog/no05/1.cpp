#include <iostream> 
using namespace std;
class a
{
    public:
        int pca(){
            return 1;
        }
};
class b:public a
{
    public:
        int pcb(){
            return 2;
        }
};
int main(){
    a ca;
    b cb;
    cout<< "p:"<<ca.pca()<<'\n';
    cout<< "p:"<<cb.pca()<<'\n';
    cout<< "p:"<<cb.pcb()<<'\n';
    return 0;
}