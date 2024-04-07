#include <iostream> 
#include <regex>
#include <string>
using namespace std;
void rim(string n);
int main(){
    string a="AzxB",b="12456";
    rim(a);
    cout<<"-----"<<'\n';
    rim(b);
    cout<<endl;
    return 0;
}
void rim(string n){
    regex r("[A-Za-z]*");
    if(regex_match(n,r)){//與字串比對
        cout<<"T"<<'\n';
    }
    else{
        cout<<"F"<<'\n';
    }
}
