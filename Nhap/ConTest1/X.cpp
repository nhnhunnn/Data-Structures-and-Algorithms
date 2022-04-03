#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 1e9 + 7;
int main(){
	int t; cin >> t;
	while(t--){
		ll a[102][102];
		ll f[102];
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		int n; cin >> n;
		for(int i = 1; i <= 10; ++i) a[2][i] = i;
		for(int i = 1; i <= n + 1; ++i) a[i][1] = 1;
		for(int i = 2; i <= n + 1; ++i){
			for(int j = 2; j <= 10; ++j)
				a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
		for(int i = 1; i <= 10; ++i)
			f[n + 1] = (f[n + 1] + a[n + 1][i]) % p;
		cout << f[n + 1] << endl;
	}
}
