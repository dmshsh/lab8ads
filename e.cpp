#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    vector<long long> p(n);
    p[0] = 1;
    for(int i = 1; i < n; i++)
        p[i] = p[i-1] * 2;

    string s = "";
    s += char(h[0] + 97); 
    for(int i = 1; i < n; i++) {
        long long diff = h[i] - h[i-1];
        long long val = diff / p[i];        
        s += char(val + 97);
    }

    cout << s;
    return 0;
}
