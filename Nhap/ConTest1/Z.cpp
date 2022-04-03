#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k, res = 0;
	cin >> n >> k;
	vector<string> v(n);
	for(auto &x: v) cin >> x;
	map<int, int> mp;
	for(int i = 0; i < n; ++i){
		if(i > k){
			string s = v[i - k - 1];
			--mp[s.size()];
		}
		int l = v[i].size();
		++mp[l];
		if(mp[l] > 1) res += mp[l] - 1;
	}
	cout << res << endl;
}
