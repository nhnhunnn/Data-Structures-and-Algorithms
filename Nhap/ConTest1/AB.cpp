#include <bits/stdc++.h>
using namespace std;
bool check = false;
typedef long long ll;
ll c[35], a[35], n, k, res = 0, s;
void Try(int i){
	for(int j = c[i - 1] + 1; j <= n - k + i; j ++){
		c[i] = j;
		if(i == k){
			ll Sum = 0;
			for(int x = 1; x <= k; ++x) Sum += a[c[x]];
			if(Sum == s) {
				res = k; check = true; return;
			}
		}
		else Try(i + 1);
	}
}
int main(){
	cin >> n >> s;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(k = 2; k <= n; ++k){
		Try(1);
		if(check){
			cout << res << endl;
			return 0;
		}
		else continue;
	}
	if(!check) cout << -1;
}
