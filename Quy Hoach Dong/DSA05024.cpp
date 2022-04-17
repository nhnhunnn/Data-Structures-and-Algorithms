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
// Date: 05/03/22 09:54
// Program: Cap So QHD
// -------------------  Your code STARTS here !!!---------------------------

ll dp[1000005];
int a[1005];
ll n, k;
void Solve(){
    dp[0] = 1;
    for(ll i = 1; i <= k; ++i){
        dp[i] = 0;
        for(int j = 1; j <= n; ++j){
            if(a[j] <= i){
                dp[i] += dp[i - a[j]] % mod;
                dp[i] %= mod;
            }
        }
    }
    cout << dp[k] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        Solve();
    }
    return 0;
}
