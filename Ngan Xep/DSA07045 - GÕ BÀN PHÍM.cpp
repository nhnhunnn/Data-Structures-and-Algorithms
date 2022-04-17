#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;

const ll mod = 1e9 + 7;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

// Author: Nguyen Quoc Dat
// ID: B20DCPT053
// Organization: PTIT
// Date: 11/03/22 08:30
// Program: Go ban phim
// -------------------  Your code STARTS here !!!---------------------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    stack<char> x, y;
    int n = s.length();
    for(int i = 0; i < n; ++i){
        if(s[i] == '-'){
            if(x.size()) x.pop();
        }
        else if(s[i] == '<'){
            if(x.size()){
                char t = x.top(); x.pop(); y.push(t);
            }
        }
        else if(s[i] == '>'){
            if(y.size()){
                char t = y.top(); y.pop(); x.push(t);
            }
        }
        else x.push(s[i]);
    }
    while(!x.empty()){
        char t = x.top(); x.pop(); y.push(t);
    }
    while(!y.empty()){
        cout << y.top();
        y.pop();
    }
    return 0;
}
