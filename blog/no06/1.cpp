#include <iostream> 
using namespace std;
template <typename T>
void a(T n);
int main(){
    a(1);
    a('A');
    cout<<endl;
    return 0;
}
template <typename T>
void a(T n){
    cout<<"p:"<<n<<'\n';
}

