#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		ll f[n + 4];
		f[0] = 1;
		for(int i = 1; i <= n; ++i){
			f[i] = 0;
			for(int j = 1; j <= min(i, k); ++j)
				f[i] = (f[i] + f[i - j]) % mod;
		}
		cout << f[n] << endl;
	}
}

