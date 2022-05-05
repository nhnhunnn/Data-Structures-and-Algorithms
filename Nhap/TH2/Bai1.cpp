#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	for(int k = 1; k <= t; ++k){
		string s; cin >> s;
		int n = s.size();
		stack<int> st;
		string ans = "";
		for(int i = 0; i <= n; ++i){
			st.push(i + 1);
			if(s[i] == 'I' || i == n){
				while(st.size()){
					int x = st.top(); st.pop();
					ans += to_string(x);
				}
			} 
		}
		cout << "Test " << k << ": " << ans << endl;
	}
	return 0;
}
