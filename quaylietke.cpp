#include<iostream>
#include<algorithm>
using namespace std;
void Try(int n, string s){
    if(s.size() == n){
        for(int i = 0 ; i < s.length() ; i++){
            cout << s[i] << " ";
        }
        cout << endl;
        return;
    }
    else {
        Try(n,s + "0");
        Try(n, s + "1");
    }
}
int main(){
    int n;
    cin >> n;
    Try(n,"");
}