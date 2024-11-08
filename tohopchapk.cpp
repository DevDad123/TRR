#include<iostream>
#include<algorithm>
using namespace std;
bool ok = true;
void nextgen(int n , int k , int a[]){
    int i = k;
    while(i > 0 && a[i] == n - k + i){
        i--;
    }
    if(i <= 0){
        ok = false;
        return;
    }
    else {
        a[i]++;
        for(int j = i + 1 ; j < n ; j++){
            a[j] = a[j - 1] + 1; 
        }
    }
}
int main(){
    int k,n;
    cin >> k >> n;
    int a[k];
    for(int i = 1 ; i <= k ; i++){
        a[i] = i;
    }
    ok = true;
    while(ok){
        for(int i = 1 ; i <= k ; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        nextgen(n,k,a);
    }
    cout << endl;
}