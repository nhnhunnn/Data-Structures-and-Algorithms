#include <bits/stdc++.h>
using namespace std;
set<string> res;
int n, a[100];
void Try(int i){
	for(int j = 0; j <= 1; ++j){
		a[i] = j;
		if(i == n){
			string s = "";
			for(int k = 1; k <= n; ++k){
				if(a[k] == 0) s += "6";
				else s += "8";
			}
			res.insert(s);
		}
		else Try(i + 1);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		res.clear();
		Try(1);
		cout << res.size() << endl;
		for(auto x: res) cout << x << " ";
		cout << endl;
	}
}
