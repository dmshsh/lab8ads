#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

const long long N = 2e5 + 17;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;

vector<string> v;
unordered_set<string> st;

string hashing(const string &s) {
    long long h = 0, p = 1;
    for (char c : s) {
        h = (h + ((c - 47) * p) % mod) % mod;
        p = (p * 11) % mod;
    }
    return to_string(h);
}

int main(){
    int n; string s;
    cin >> n;
    for(int i = 1; i <= n * 2; i++){
        cin >> s;
        v.push_back(s);
        st.insert(s);
    }

    int cnt = 0;

    for(int i = 0; i < v.size(); i++){
        if(cnt == n) break;
        string hs = hashing(v[i]);
        if(st.find(hs) != st.end()){
            cout << "Hash of string \"" << v[i] << "\"" << " is " << hs << endl;
            cnt++;
        }
    }
}

