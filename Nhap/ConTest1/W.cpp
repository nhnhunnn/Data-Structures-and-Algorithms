#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<pair<float, float> > v(n);
		for(int i = 0; i < n; i ++) cin >> v[i].first >> v[i].second;
		int f[n + 5]; 
		f[0] = 1;
		int res = 1;
		for(int i = 0; i < n; i ++){
			f[i] = 1;
			for(int j = 0; j < i; j++){
				if(v[j].first < v[i].first && v[j].second > v[i].second)
					f[i] = max(f[i], f[j] + 1);
			}
			res = max(res, f[i]);
		}
		cout << res << endl;
	}
}
