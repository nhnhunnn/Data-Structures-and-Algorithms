#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
struct matrix{
	ll x[11][11];
} a, b;
int n;
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
int main(){
	int t; cin >> t;
	while(t--){
		ll k;
		cin >> n >> k;
		for(int i = 0; i < n; i ++) 
			for(int j = 0; j < n; j ++)
				cin >> a.x[i][j];
		a = Power(a, k);
		ll res = 0;
		for(int i = 0; i < n; i ++){
			res += a.x[n - 1][i];
			res %= mod;
		}
		cout << res << endl;
	}
	return 0;
}
