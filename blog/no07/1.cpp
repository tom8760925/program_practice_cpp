#include <iostream> 
using namespace std;
namespace a
{
    int r(int n){
        return n;
    }
    namespace b
    {
        int r2(int n){
        return n+1;
    }
    }

}
using namespace a;
using namespace b;//指向b
using namespace a::b;//指向b
int main(){
    cout<<"p:"<<r(1)<<'\n';
    cout<<"p:"<<r2(1)<<'\n';
    cout<<"p:"<<a::b::r2(1)<<'\n';
    cout<<endl;
    return 0;
}