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
// Date: 11/03/22 16:12
// Program: So nho nhat
// -------------------  Your code STARTS here !!!---------------------------

void Solve(int d, int s) {
    if (s == 0) {
        (d == 1)? cout << 0 << endl : cout << "-1" << endl;
        return;
    }
    if (s > 9 * d) {
        cout << "-1" << endl;
        return;
    }
    int res[d];
    s -= 1;
    for (int i = d - 1; i > 0; i--) {
        if (s > 9) {
            res[i] = 9;
            s -= 9;
        }
        else {
            res[i] = s;
            s = 0;
        }
    }
    res[0] = s + 1;
    for (int i = 0; i < d; i++)
        cout << res[i];
    
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        int d, s; cin >> s >> d;
        Solve(d, s);
    }
    return 0;
}
