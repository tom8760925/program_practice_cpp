#include <iostream> 
#include <vector>
using namespace std;
int main(){
    vector<int> a = {1,2,3};
    a.push_back(4);
    cout<<"p:"<<a[3]<<'\n';
    a.pop_back();
    cout<<"p:"<<a.size()<<'\n';
    cout<<"p:"<<a[3]<<'\n';//值還是在
    cout<<endl;
    return 0;
}