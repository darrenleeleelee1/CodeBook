#include <bits/stdc++.h>
using namespace std;
bool isSubstring(string a, string b){
        bool is =0;
        if(b.find(a) != std::string::npos){
            is =1;
        }
        return is;
}      
//check if string a is substring of b
int main(){
    string a = "123",b = "12345";
    // "123" 是不是 substring "12345"
    if(isSubstring(a,b)) cout << "yes"<<endl;
 	else cout << "no"<<endl;
    return 0;
}