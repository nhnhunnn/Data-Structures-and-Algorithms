#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[n + 5], res[n + 5];
		for(int i = 1; i <= n; i ++) cin >> a[i];
		deque<int> dq;
		while(dq.size()) dq.pop_front();
		for(int i = 1; i <= n; i ++){
			while(dq.size() && a[dq.back()] <= a[i])
				dq.pop_back();
			dq.push_back(i);
			if(dq.front() + k <= i) dq.pop_front();
			if(i >= k) res[i] = a[dq.front()];
		}	
		for(int i = k; i <= n; i ++) 
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
