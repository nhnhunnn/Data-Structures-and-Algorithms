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
// Date: 23/03/22 01:09
// Program: Tong chu so
// -------------------  Your code STARTS here !!!---------------------------

int dp[101][10005];
void qhd(){
	int i, j, k;
	for(i = 0; i <= 100; i ++){
		for(j = 0; j <= 10000; j ++)
			dp[i][j] = 101;
	}
	dp[0][0] = 0;
	for(i = 1; i < 10; i ++) dp[i][i * i] = 1;
	for(i = 1; i <= 100; i ++){
		for(j = i; j <= i * 81; j ++){
			for(k = 9; k > 0; k --){
				int kk = k * k;
				if(i > k && j > kk && dp[i][j] > dp[i - k][j - kk] + 1)
					dp[i][j] = dp[i - k][j - kk] + 1;
			}
		}
	}
}

void Solve(int a, int b){
	if(a <= 0 || a > 100 || b <= 0 || b > 10000 || (dp[a][b] > 100)){
		cout << -1 << endl;
		return;
	}
	int i, k, n = dp[a][b];
	for(k = n; k > 0; k --){
		for(i = 1; i <= 9; i ++){
			if(a >= i && b >= i * i && (dp[a][b] == dp[a - i][b - i * i] + 1)){
				cout << i;
				a -= i;
				b -= i * i;
				break;
			}
		}
	}
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t; cin >> t;
	qhd();
	while(t--){
		int a, b; cin >> a >> b;
		Solve(a, b);
	}
	return 0;
}