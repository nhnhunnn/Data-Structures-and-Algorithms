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
// Date: 07/03/22 10:30
// Program: Chon o
// -------------------  Your code STARTS here !!!---------------------------
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, ans = -1e9, s = -1e9;
        cin >> n;
        int a[4][n + 1], f[n + 1][11] = {}, d[] = {0, 1, 2, 4, 5, 8, 9, 10};
        for (int i = 0; i < 4; i++)
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
                ans = max(ans, a[i][j]);
            }
        for (int j = 1; j <= n; j++){
            for (int k = 0; k < 8; k++){
                for (int i = 0; i < 4; i++)
                    if (d[k] & (1 << i))
                        f[j][d[k]] += a[i][j];
                int x = -1e9;
                for (int i = 0; i < 8; i++)
                    if ((d[k] | d[i]) == (d[k] ^ d[i]))
                        x = max(x, f[j - 1][d[i]]);
                f[j][d[k]] += x;
            }
        }
        for (int i = 0; i < 8; i++)
            s = max(f[n][d[i]], s);
        if (ans < 0)
            cout << ans << endl;
        else
            cout << s << endl;
    }
    return 0;
}
