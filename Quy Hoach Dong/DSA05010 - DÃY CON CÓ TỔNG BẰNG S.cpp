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
// Date: 12/03/22 10:30
// Program: Day con lien tiep co tong chia het cho K
// -------------------  Your code STARTS here !!!---------------------------

vector<vector<int> > f;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int dp[1005][1005];
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++) dp[0][i] = -1e9;
		for(int i = 1; i <= n; i++) {
			int x; cin >> x;
			x %= k;
			for(int j = 0; j < k; j++)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + k - x) % k] + 1);
		}
		cout << dp[n][0] << endl;
	}
	return 0;
}
