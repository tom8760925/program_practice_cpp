#include <iostream> 
#include <vector>
using namespace std;
int main(){
    vector<int> a;
    vector<int> b = {1,2,3};
    vector<int> c {1,2,3};
    vector<vector<int>> d {{1,2},{3}};
    int e[]={4,5,6};
    vector<int> f (e,e+3);
    vector<int> g (b.begin()+1,b.end()-1);
    for(int n=0 ;n<3;n++){
        cout<<"p:"<<b[n]<<'\n';
    }
    cout<<"---\n";
    for(int n=0 ;n<3;n++){
        cout<<"p:"<<f[n]<<'\n';
    }
    cout<<"---\n";
    for(auto &n:g){//簡易顯示方法
        cout<<"p:"<<n<<'\n';
    }
    cout<<"---\n";
    cout<<"p:"<<a.capacity()<<'\n';
    a.reserve(3);//預先配置記憶體大小
    cout<<"p:"<<a.capacity()<<'\n';
    cout<<endl;
    return 0;
}