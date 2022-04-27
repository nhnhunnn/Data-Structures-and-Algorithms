#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; 
	cin >> t;
    cin.ignore();
    while (t--) {
        string s; getline(cin, s);
        stringstream ss(s);
        string tmp;
        vector<string> res;
        while(ss >> tmp){
            reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
        }
        for(auto x: res) cout << x << " ";
        cout << endl;
    }
    return 0;
}
