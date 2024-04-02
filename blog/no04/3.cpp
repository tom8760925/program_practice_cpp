#include <iostream> 
#include <vector>
using namespace std;
int main(){
    vector<int> a = {1,2,3,4,5};
    cout<<"p:"<<a.size()<<'\n';//大小
    cout<<"p:"<<a.end()-a.begin()<<'\n';
    cout<<"p:"<<a.capacity()<<'\n';//記憶體大小
    cout<<"---\n";
    a.push_back(6);
    cout<<"p:"<<a.size()<<'\n';
    cout<<"p:"<<a.capacity()<<'\n';
    a.shrink_to_fit();//清多餘的記憶體大小
    cout<<"p:"<<a.size()<<'\n';
    cout<<"p:"<<a.capacity()<<'\n';
    cout<<endl;
    return 0;
}