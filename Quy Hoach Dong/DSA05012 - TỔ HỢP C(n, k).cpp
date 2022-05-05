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
// Date: 02/03/22 21:19
// Program: To Hop
// -------------------  Your code STARTS here !!!---------------------------

ll dp[1001][1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i = 0; i <= 1000; i ++){
		for(int j = 0 ; j <= i; j ++){
			if(j == 0 || j == i) 
				dp[i][j] = 1; 
			else 
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod; 
		} 
	} 
	int t; cin >> t;
	while(t--) {
		int n, r;
		cin >> n >> r;
		cout << dp[n][r] << endl;
	}
	return 0;
}
