#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll H[100001], L[100001];
ll f[100001], res[100001];
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		H[0] = L[0] = 0;
		for(int i = 1; i <= n; i++) cin >> L[i];
		for(int i = 1; i <= n; i++) cin >> H[i];
		vector<ll> a, b(n + 1, 1);
		a.push_back(-1); a.push_back(-1);
		for(int i = 1; i <= n; i++){
			b[i] = 1;
			for(int j = i - 1; j > 0;){
				if(H[j] <= H[i]){
					b[i] += b[j];
					j -= b[j];
					if(j <= 0){
						a.push_back(-1);
						break;
					}
				}
				else{
					a.push_back(j);
					break;
				}
			}
		}
		res[0] = 0;
		res[1] = H[1];
		for(int i = 2; i <= n; i++) res[i] = H[i] + res[i - 1];
		f[1] = (ll)H[1] * L[1];
		for(int i = 2; i <= n; i++){
			if(a[i] == -1)
				f[i] = (ll)H[i] * L[i] - res[i] + H[i];
			else{
				ll s = res[i] - res[a[i]];
				f[i] = f[a[i]] + (ll)H[i] * (L[i] - L[a[i]] - 1) - s + H[i];
			}
		}
		int q; cin >> q;
		while(q--){
			ll k; cin >> k;
			int index = lower_bound(f, f + n + 1, k) - f;
			cout << index - 1 << endl;
		}
		cout << endl;
	}
	return 0;
}
