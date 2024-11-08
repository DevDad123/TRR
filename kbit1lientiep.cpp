#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(const string& binaryString, int k) {
    int count = 0;
    bool found = false;

    for (char c : binaryString) {
        count = (c == '1') ? count + 1 : 0;

        if (count == k) {
            if (found) return false;  
            found = true;
        } else if (count > k) {
            return false; 
        }
    }

    return found;
}

void gen(int n, int k, int a[], vector<string>& results) {
    bool ok = true;
    while (ok) {
        string binaryString;
        for (int i = 0; i < n; i++) {
            binaryString += (a[i] ? '1' : '0');
        }

        if (check(binaryString, k)) {
            results.push_back(binaryString);
        }

        ok = false;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == 0) {
                a[i] = 1;
                for (int j = i + 1; j < n; j++) {
                    a[j] = 0;
                }
                ok = true;
                break;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> k >> n;

    int a[20] = {0}; 
    vector<string> results;

    gen(n, k, a, results);

    for (const string& s : results) {
        for (char c : s) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}