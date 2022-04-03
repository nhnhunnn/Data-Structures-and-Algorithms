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

//#define f first
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
// Date: 04/03/22 18:37
// Program: Xau con chung dai nhat 
// -------------------  Your code STARTS here !!!---------------------------

ll f[1005][1005];
ll dp(string a, string b){
	memset(f, 0 , sizeof(f));
	int n = a.size(), m = b.size();
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			if(a[i - 1] == b[j - 1])
				f[i][j] = f[i - 1][j - 1] + 1;
			else
				f[i][j] = max(f[i- 1][j], f[i][j - 1]);
		}
	}
	return f[n][m];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		string a, b; cin >> a >> b;
		cout << dp(a, b) << endl;
	}
	return 0;
}