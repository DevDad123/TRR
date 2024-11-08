#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check(const string& str, int k) {
    int count = 0;
    bool found = false;
    for (char c : str) {
        count = (c == 'A') ? count + 1 : 0;
        if (count == k) {
            if (found) return false;
            found = true;
        } else if (count > k) {
            return false;
        }
    }
    return found;
}

void gen(int n, int k, char a[], vector<string>& results) {
    bool ok = true;
    while (ok) {
        string str;
        for (int i = 0; i < n; i++) {
            str += a[i];
        }
        if (check(str, k)) {
            results.push_back(str);
        }
        ok = false;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == 'B') {
                a[i] = 'A';
                for (int j = i + 1; j < n; j++) {
                    a[j] = 'B';
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

    char a[20];
    fill(a, a + n, 'B');
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