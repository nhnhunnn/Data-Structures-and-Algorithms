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
// Date: 03/03/22 23:30
// Program: Duong di nho nhat - qhd
// -------------------  Your code STARTS here !!!---------------------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a[n + 5][m + 5];
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++) cin >> a[i][j];
        }
        int dp[n + 5][m + 5];
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(i == 1 && j == 1)
                    dp[i][j] = a[i][j];
                else if(i == 1)
                    dp[i][j] = dp[i][j - 1] + a[i][j];
                else if(j == 1)
                    dp[i][j] = dp[i - 1][j] + a[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + a[i][j];
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
