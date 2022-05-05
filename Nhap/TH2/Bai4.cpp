#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int b[] = {4, 7};
int n, k, a[100];
vector<ll> res;
void Try(int i){
	for(int j = 0; j <= 1; ++j){
		a[i] = j;
		if(i == n){
			ll tmp = 0;
			for(int k = 1; k <= n; ++k){
				tmp = tmp * 10 + b[a[k]];
			}
			res.push_back(tmp);
		}else Try(i + 1);
	}
}
int main(){
	for(n = 1; n <= 9; ++n) Try(1);
	ll u = 0, v = 0, s = 0;
	cin >> u >> v;
	int id = 0;
	while(u <= v){
		if(u <= res[id] && v <= res[id]){
			s += (v - u + 1) * res[id];
			u = res[id] + 1;
		}
		if(u <= res[id] && v >= res[id]){
			s += (res[id] - u + 1) * res[id];
			u = res[id] + 1;
		}else
			id++;
	}
	cout << s << endl;
	return 0;
}
