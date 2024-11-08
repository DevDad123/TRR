#include<iostream>
using namespace std;
int n,k;
int a[1000];
bool ok = false;
void Try(int n , int k , int a[]){
    int i = k - 1;
    while(i >= 0 && a[i] == n - k + i + 1){
        --i;
    }
    if(i < 0){
        ok = true;
        return;
    }
    ++a[i];
    for(int j = i + 1 ; j < k ; j++){
        a[j] = a[j - 1] + 1;
    }
}
int main(){
    cin >> k >> n;
    for(int i = 0 ; i < k ; i++){
        a[i] = i + 1;
    }
    while(!ok){
        for(int i = 0 ; i < k ; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        Try(n,k,a);
    }
    return 0;
}