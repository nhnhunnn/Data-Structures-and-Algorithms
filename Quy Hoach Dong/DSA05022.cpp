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
// Date: 11/03/22 15:43
// Program: Ky tu giong nhau
// -------------------  Your code STARTS here !!!---------------------------

ll f[10005];

ll Solve(int Ins, int Del, int Cop, int n){
    if(n == 1) 
        return Ins;
    f[1] = Ins;
    for(int i = 2; i <= n; ++i){
        if(i % 2 == 0) f[i] = min(f[i - 1] + Ins, f[i / 2] + Cop);
        else f[i] = min(f[i - 1] + Ins, f[(i + 1) / 2] + Del + Cop); 
    }
    return f[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int x, y, z; cin >> x >> y >> z;
        cout << Solve(x, y, z, n) << endl;
    }
    return 0;
}