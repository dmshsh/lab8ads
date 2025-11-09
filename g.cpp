#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;
    int n = s.size();

    int q;
    cin >> q;

    const long long mod1 = 1000000007;
    const long long mod2 = 1000000009;
    const long long base = 131;

    vector<long long> h1(n+1, 0), p1(n+1, 1);
    vector<long long> h2(n+1, 0), p2(n+1, 1);

    for(int i = 0; i < n; i++){
        h1[i+1] = (h1[i] * base + s[i]) % mod1;
        p1[i+1] = (p1[i] * base) % mod1;

        h2[i+1] = (h2[i] * base + s[i]) % mod2;
        p2[i+1] = (p2[i] * base) % mod2;
    }

    auto get_hash = [&](int l, int r){
        long long x1 = (h1[r] - h1[l] * p1[r-l] % mod1 + mod1) % mod1;
        long long x2 = (h2[r] - h2[l] * p2[r-l] % mod2 + mod2) % mod2;
        return make_pair(x1, x2);
    };

    while(q--) {
        int L, R;
        cin >> L >> R;
        L--, R--;

        int len = R - L + 1;
        auto target = get_hash(L, R+1);

        int ans = 0;
        for(int i = 0; i + len <= n; i++){
            if(get_hash(i, i+len) == target)
                ans++;
        }
        cout << ans << "\n";
    }
}
