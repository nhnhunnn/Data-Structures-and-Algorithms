#include <bits/stdc++.h>
using namespace std;
int n, k, s, a[100];
vector<string> res;
void Try(int i, int k, int s){
	for(int j = k; j >= 1; j--){
		if(s + j <= n){
			a[i] = j;
			s += j;
			if(s == n) {
				string r = "(";
				for(int k = 1; k < i; k ++) 
					r += (to_string(a[k]) + " ");
				r += (to_string(a[i]) + ")");
				res.push_back(r);
			}
			else 
				Try(i + 1, j, s);
			s -= j;
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		res.clear();
		memset(a, 0, sizeof(a));
		Try(1, n, 0);
		cout << res.size() << endl;
		for(int i = 0; i < res.size(); i ++)
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}