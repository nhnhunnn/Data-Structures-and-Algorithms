#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int a[n];
	int mx = 0;
	for(auto &x: a) {
		cin >> x;
		mx = max(mx, x);
	}
	int res = 1, cnt = 0;
	for(int i = 0; i < n; ++i){
		if(a[i] == mx) ++cnt;
		else cnt = 0;
		res = max(res, cnt);
	}
	cout << res << endl;
}
