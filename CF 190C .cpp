#include <bits/stdc++.h>
using namespace std;

vector<string> tokens;
int idx = 0;

string solve() {
    if (idx >= tokens.size()) return "";
    
    if (tokens[idx] == "int") {
        idx++;
        return "int";
    }
    
    if (tokens[idx] == "pair") {
        idx++;
        string left = solve();
        if (left == "") return "";
        string right = solve();
        if (right == "") return "";
        return "pair<" + left + "," + right + ">";
    }
    
    return "";
}

int main() {
    int n;
    cin >> n;
    
    tokens.resize(n);
    for (int i = 0; i < n; i++) cin >> tokens[i];
    
    string res = solve();
    
    if (idx != n || res == "") cout << "Error occurred";
    else cout << res;
    
    return 0;
}
