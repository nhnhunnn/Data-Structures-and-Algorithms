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
// Date: 09/03/22 19:55
// Program: Hinh vuong lon nhat
// -------------------  Your code STARTS here !!!---------------------------

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        int n, m;
        cin>> n >> m;
        int a[n][m];
        ll f[n][m];
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++) cin >> a[i][j];
        for(int i = 0; i < n; i ++){
            (a[i][0] == 1) ? f[i][0] = 1 : f[i][0] = 0;
            for(int j = 1; j < m; j ++){
                if(a[i][j])
                    f[i][j] = f[i][j - 1] + 1;
                else 
                    f[i][j] = 0;
            }
        }
        ll res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j ++){
                if(f[i][j] > res){
                    if(res > i + 1) continue;
                    ll tp = f[i][j];
                    for(int k = i; k > i - res - 1; k --)
                        tp = min(tp, f[k][j]);
                    res = max(tp, res);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}