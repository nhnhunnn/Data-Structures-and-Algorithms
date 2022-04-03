#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<pair<int, int > > a(n);
		for(int i = 0; i < n; i ++)
			cin >> a[i].first >> a[i].second;
		ll f[n][2];
		f[0][1] = a[0].second;
		f[0][0] = 0;
		for(int i = 1; i < n; ++i){
			if(a[i].first == a[i - 1].first){
				f[i][1] = min(f[i - 1][0], f[i - 1][1]) + a[i].second;
				f[i][0] = f[i - 1][1];
			}
			else{
				f[i][0] = min(f[i - 1][0], f[i - 1][1]);
				f[i][1] = f[i][0] + a[i].second;
			}
		}
		cout << min(f[n - 1][0], f[n - 1][1]) << endl;
	}
	return 0;
}
