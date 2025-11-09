#include <bits/stdc++.h>
using namespace std;

int main() {
 
    string s;
    cin >> s;
    int n = s.size();

    const long long mod = 1000000007;
    const long long base = 131;

    vector<long long> h(n+1, 0), p(n+1, 1);

    for (int i = 0; i < n; i++) {
        h[i+1] = (h[i] * base + s[i]) % mod;
        p[i+1] = p[i] * base % mod;
    }

    auto get_hash = [&](int l, int r) {
        long long res = (h[r] - h[l] * p[r-l] % mod + mod) % mod;
        return res;
    };

    unordered_set<long long> st;
    st.reserve(n * n);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            st.insert(get_hash(i, j));
        }
    }

    cout << st.size();
}
