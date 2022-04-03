#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct matrix{
	ll x[11][11];
}a, b;
int n;
matrix operator *(matrix a, matrix b){
	matrix res;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			res.x[i][j] = 0;
			for(int k = 0; k < n; k++){
				res.x[i][j] = (res.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
				res.x[i][j] %= mod;
			}
		}
	}
	return res;
}
matrix Power(matrix a, ll k){
	if(k == 1) return a;
	matrix m = Power(a, k / 2);
	if(k % 2 == 0) return m * m;
	return m * m * a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		ll k; cin >> n >> k;
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++) cin >> a.x[i][j];
		a = Power(a, k);
		ll res = 0;
		for(int i = 0; i < n; i ++){
			res += a.x[n - 1][i];
			res %= mod;
		}
		cout << res % mod << endl;
	}
	return 0;
}