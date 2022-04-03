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
// Program: so Ugly
// -------------------  Your code STARTS here !!!---------------------------

ll f[10005];

ll Ugly_N(int n){
    f[1] = 1;
    ll x = 2, y = 3, z = 5;
    int i1 = 1, i2 = 1, i3 = 1;

    int cnt = 2;
    while (cnt <= n) {
        ll t = min(min(x, y), z);
        f[cnt++] = t;

        if (t == x)
            x = f[++i1] * 2;
        if (t == y)
            y = f[++i2] * 3;
        if (t == z)
            z = f[++i3] * 5;
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
        cout << Ugly_N(n) << endl;
    }
    return 0;
}