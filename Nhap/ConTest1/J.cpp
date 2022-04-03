#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	while(t--){
		int n; cin >> n;
		ll a[n];
		for(auto &x: a) cin >> x;
		stack<int> st;
		ll res = LONG_LONG_MIN;
		int i = 0;
		while(i < n){
			if(st.empty() || a[i] >= a[st.top()]) {
				st.push(i);
				++i;
			}
			else{
				int id = st.top();
				st.pop();
				if(st.empty()) res = max(res, i * a[id]);
				else res = max(res, (i - st.top() - 1) * a[id]);
			}
		}
		while(!st.empty()){
			int id = st.top();
			st.pop();
			if(st.empty()) res = max(res, i * a[id]);
			else res = max(res, (i - st.top() - 1) * a[id]);
		}
		cout << res << endl;
	}
	return 0;
}


