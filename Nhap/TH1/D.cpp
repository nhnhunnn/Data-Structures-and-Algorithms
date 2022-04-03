#include <bits/stdc++.h>
using namespace std;
int a[20], n, s;
vector<string> res;
void Try(int i, int k, int s){
	for(int j = k; j >= 1; --j){
		if(s + j <= n){
			a[i] = j;
			s += j;
			if(s == n){
				string r = "(";
				for(int x = 1; x < i; ++x){
					r += (to_string(a[x]) + " ");
				}
				r += (to_string(a[i]) + ")");
				res.push_back(r);
			}
			else Try(i + 1, j, s);
			s -= j;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		cin >> n;
		res.clear();
		memset(a, 0, sizeof(a));
		Try(1, n, 0);
		cout << res.size() << endl;
		for(auto x: res) cout << x << " ";
		cout << endl;
	}
}