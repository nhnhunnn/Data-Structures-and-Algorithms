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
// Date: 04/03/22 18:37
// Program: So co Tong chu so bang K
// -------------------  Your code STARTS here !!!---------------------------

ll f[105][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for(int i = 1; i <= 9; i ++) f[1][i] = 1;
	for(int i = 1; i <= 100; i ++){
		for(int j = 1; j <= 1000; j ++){
			for(int k = 0; k <= 9; k ++){
				if(k <= j){
					f[i][j] += f[i - 1][j - k];
					f[i][j] %= mod;
				}
			}
		}
	}
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		cout << f[n][k] << endl;
	}
	return 0;
}
