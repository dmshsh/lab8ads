#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    const long long mod = 1e9 + 7;
    const long long pw = 31;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<string> pat(n);
        for (int i = 0; i < n; i++) cin >> pat[i];
        string text;
        cin >> text;
        long long mx = 0;
        vector<long long> cnt(n, 0);
        int T = text.size();
        vector<long long> h(T + 1, 0), p(T + 1, 1);
        for (int i = 0; i < T; i++) {
            h[i + 1] = (h[i] * pw + (text[i] - 'a' + 1)) % mod;
            p[i + 1] = (p[i] * pw) % mod;
        }
        for (int i = 0; i < n; i++) {
            long long hash_s = 0;
            int k = pat[i].size();
            for (char c : pat[i])
                hash_s = (hash_s * pw + (c - 'a' + 1)) % mod;
            for (int j = 0; j + k <= T; j++) {
                long long cur = (h[j + k] - h[j] * p[k]) % mod;
                if (cur < 0) cur += mod;
                if (cur == hash_s) {
                    if (text.compare(j, k, pat[i]) == 0)
                        cnt[i]++;
                }
            }
            mx = max(mx, cnt[i]);
        }

        cout << mx << "\n";
        for (int i = 0; i < n; i++)
            if (cnt[i] == mx)
                cout << pat[i] << "\n";
    }

    return 0;
}
