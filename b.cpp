#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
const long long N = 2e5 + 17;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;
const long long pw = 31;

vector<long long> prefix_hash(string s) {
    int n = s.size();
    vector<long long> h(n + 5, 0), p(n + 5, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * pw + (s[i] - 'a' + 1)) % mod;
        p[i + 1] = (p[i] * pw) % mod;
    }
    return h;
}

long long get_hash(const vector<long long> &h, const vector<long long> &p, int l, int r) {
    long long res = (h[r] - h[l] * p[r - l]) % mod;
    if (res < 0) res += mod;
    return res;
}

int main(){
    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    int n = s1.size(), m = t.size();

    auto h1 = prefix_hash(s1);
    auto h2 = prefix_hash(s2);
    vector<long long> p(n + 1, 1);
    for (int i = 1; i <= n; i++) p[i] = (p[i - 1] * pw) % mod;

    long long hash_t = 0;
    for (char c : t) hash_t = (hash_t * pw + (c - 'a' + 1)) % mod;

    int count = 0;
    for (int i = 0; i + m <= n; i++) {
        long long h_s1 = get_hash(h1, p, i, i + m);
        long long h_s2 = get_hash(h2, p, i, i + m);
        if (h_s1 == hash_t && h_s2 == hash_t) count++;
    }

    cout << count;

}
