#include<bits/stdc++.h>
using namespace std;
int n, k, c[24];
vector<vector<int> > v;
void Try(int i){
	for(int j = c[i - 1] + 1; j <= n - k + i; j ++){
		c[i] = j;
		if(i == k){
			vector<int> t;
			for(int i = 1; i <= k; i++)
				t.push_back(c[i]);
			v.push_back(t);
		}
		else Try(i + 1);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		v.clear();
		c[0] = 0;
		Try(1);
		reverse(v.begin(), v.end());
		for(int i = 0; i < v.size(); i ++){
			for(int j = 0; j < v[i].size(); j ++)
				cout << v[i][j] << " ";
			cout << endl;
		}
	}
}