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
// Date: 21/02/22 20:30
// Program: Luy Thua Ma tran 2
// -------------------  Your code STARTS here !!!---------------------------

struct matrix{
	ll x[11][11];
} a, b;

int n;
ll k;

matrix operator * (matrix a, matrix b){
	matrix c;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			c.x[i][j] = 0;
			for(int k = 0; k < n; k ++){
				c.x[i][j] = (c.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
				c.x[i][j] %= mod;
			}
		}
	}
	return c;
}

matrix Power(matrix a, ll k){
	if(k == 1)
		return a;
	matrix t = Power(a, k / 2);
	if(k & 1) 
		return t * t * a;
	return t * t;
}

void Solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i ++) 
		for(int j = 0; j < n; j ++)
			cin >> a.x[i][j];
	a = Power(a, k);
	ll sum = 0;
	for(int i = 0; i < n; i ++){
		sum = sum + a.x[i][n - 1] % mod;
		sum %= mod;
	}
	cout << sum << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int t; cin >> t;
	while(t--){
		Solve();
	}
	return 0;
}
