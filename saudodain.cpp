#include<iostream>
#include<algorithm>
using namespace std;
void sinh(int a[] , int n){
    int ok = 0;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(a[i] == 0){
            a[i] = 1;
            ok = 1;
            for(int j = i + 1 ; j < n ; j++){
                a[j] = 0;
            }
            break;
        }
    }
    if(ok == 0){
        for(int i = 0 ; i < n ; i++){
            cout << "0" << " ";
        }
        cout << endl;
    }
    else {
        for(int i = 0 ; i < n ; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
int main(){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0 ; i < n ; i++){
            a[i] = 0;
        }
        for(int i = 0 ; i < n ; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        for(int i = 1 ; i <(1 << n) ; i++){
            sinh(a,n);
        }
    return 0;
}