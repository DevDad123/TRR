#include<iostream>
#include<vector>
using namespace std;
bool a[20],xuoi[40],nguoc[40];
int x[20];
int n;
vector<vector<int> > solutions;
void Try(int i){
    for(int j = 1 ; j <= n ; j++){
        if(a[j] && xuoi[i - j + n] && nguoc[i + j - 1]){
            x[i] = j;
            a[j] = false;
            xuoi[i - j + n] = false;
            nguoc[i + j - 1] = false;
            if(i == n){
                vector<int> solution;
                for(int k = 1; k <= n ; k++){
                    solution.push_back(x[k]);
                }
                solutions.push_back(solution);
            }
            else {
                Try(i + 1);
            }
                a[j] = true;
                xuoi[i - j + n] = true;
                nguoc[i + j - 1] = true;
            }
    }
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        a[i] = true;
    }
    for(int i = 1 ; i <= 2 * n ; i++){
        xuoi[i] = true;
        nguoc[i] = true;
    }
    Try(1);
    for(int i = 0 ; i < solutions.size() ; i++){
        for(int j = 0 ; j < solutions[i].size(); j++){
            cout << solutions[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}