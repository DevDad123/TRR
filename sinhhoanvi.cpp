#include<iostream>
#include<algorithm>
using namespace std;
bool ok = true;;
void nextgen(int n, int a[]){
    int i = n - 2;
    while(i >= 0 && a[i] > a[i + 1]){
        i--;
    }
    if(i < 0){
        ok = false;
    }
    else{
        int j = n - 1;
        while(a[i] > a[j]) j--;
        swap(a[i],a[j]);
        reverse(a + i + 1 , a + n);
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        a[i] = i + 1;
    }
    while(ok){
        for(int i = 0 ; i < n ; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        nextgen(n,a);
    }
    return 0;
}