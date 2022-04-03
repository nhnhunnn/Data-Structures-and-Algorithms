#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 9;
ll dp [1010][1010][15], a[1005], b[1005];
int main(){
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
			if(a[i] > b[j]) dp[i][j][1] = 1;
			else dp[i][j][1] = 0;
		}
	}
    for (int p = 1; p <= k; p++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                dp[i][j][p] += dp[i - 1][j][p] + dp[i][j - 1][p] - dp[i - 1][j - 1][p];
                if (a[i] > b[j]) 
					dp[i][j][p] += dp[i - 1][j - 1][p - 1];
				dp[i][j][p] %= mod;
            }
        }
    }
    cout << dp[n][m][k] << endl;
}
