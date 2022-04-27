#include <bits/stdc++.h>
using namespace std;
bool check(string s){
    map<char, int> mp;
    for(auto x: s){
        mp[x]++;
    }
    return (mp['2'] != 0 && mp['3'] != 0 && mp['5'] != 0 && mp['7'] != 0);
}
int main() {
    queue<string> q;
    vector<string> v;
    q.push("2"); q.push("3"); q.push("5"); q.push("7");
    while(!q.empty()){
        string s = q.front();
        if(s.length() >= 10) break;
        else if(check(s) && s.size() >= 3 && s[s.size() - 1] != '2'){ 
            v.push_back(s);
        }
        q.pop();
        q.push(s + "2"); 
        q.push(s + "3"); 
        q.push(s + "5"); 
        q.push(s + "7");
    }
    int n; cin >> n;
    for(int i = 0; i < v.size(); ++i){
        if(v[i].size() <= n) cout << v[i] << endl;
    }
    return 0;
}
