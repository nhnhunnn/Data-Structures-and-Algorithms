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
// Date: 06/03/22 21:00
// Program: Giai ma
// -------------------  Your code STARTS here !!!---------------------------

ll f[100005];

ll Solve(string s){
    int n = s.size();
    if(s[0] == '0')
        return 0ll;
    f[0] = f[1] = 1;
    for(int i = 2; i <= n; ++i){
        f[i] = 0;
        if(s[i - 1] != '0')
            f[i] += f[i - 1];
        if(s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')
            f[i] += f[i - 2];
    }
    return f[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << Solve(s) << endl; 
    }
    return 0;
}