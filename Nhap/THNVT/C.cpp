#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max_area(vector<ll> a, int n){
	stack <ll> st;
	ll res = LLONG_MIN, k = 0;
	while(k < n){
		if(st.empty() || a[k] >= a[st.top()]){
			st.push(k);
			++k;
		}else{
			ll id = st.top(); st.pop();
			if(st.empty()) res = max(res, k * a[id]);
			else res = max(res, (ll)a[id] * (k - st.top() - 1));
		}
	}
	while(!st.empty()){
		ll id = st.top(); st.pop();
		if(st.empty()) res = max(res, k * a[id]);
		else res = max(res, (ll)a[id] * (k - st.top() - 1));
	}
	return res;
}
int main(){
	int n, m; cin >> m >> n;
	vector <ll> a(n), b(n);
	for(auto &x: a) cin >> x;
	for(int i = 0; i < n; ++i) b[i] = m - a[n - i - 1];
	reverse(b.begin(), b.end());
	ll ans = max(max_area(a, n), max_area(b, n));
	cout << ans << endl;
}
