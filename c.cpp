#include <iostream>
#include <vector>
#include <string>
using namespace std;

const long long mod = 1e9 + 7;
const long long pw = 31;

string s, t;
int n;

int main() {

    cin >> s;

    int m = s.size();
    string check(m, '0');

    vector<long long> h(m + 1, 0), p(m + 1, 1);
    for (int i = 0; i < m; i++) {
        long long val = s[i] - 'a' + 1; 
        h[i + 1] = (h[i] * pw + val) % mod;
        p[i + 1] = (p[i] * pw) % mod;
    }

    cin >> n;

    while (n--) {
        cin >> t;
        int k = t.size();

        long long hash_t = 0;
        for (char c : t) {
            long long val = c - 'a' + 1;
            hash_t = (hash_t * pw + val) % mod;
        }

        for (int i = 0; i + k <= m; i++) {
            long long cur = (h[i + k] - h[i] * p[k] % mod + mod) % mod;

            if (cur == hash_t) {
                if (s.substr(i, k) == t) {
                    for (int j = i; j < i + k; j++)
                        check[j] = '1';
                }
            }
        }
    }

    for (char c : check) {
        if (c == '0') {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
