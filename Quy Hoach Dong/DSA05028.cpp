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
// Date: 11/03/22 08:09
// Program: Bien doi xau
// -------------------  Your code STARTS here !!!---------------------------

const int mx = 105;
ll f[mx][mx];
string a, b;

ll dp(){
	int n = a.size(), m = b.size();
	memset(f, 0, sizeof(f));
	for(int i = 0; i < mx; i ++) f[0][i] = i;
	for(int i = 0; i < mx; i ++) f[i][0] = i;
	for(int i = 1; i < mx; i ++){
		for(int j = 1; j < mx; j ++){
			if(a[i - 1] == b[j - 1])
				f[i][j] = f[i - 1][j - 1];
			else
				f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
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
		cin >> a >> b;
		cout << dp() << endl;
	}
	return 0;
}