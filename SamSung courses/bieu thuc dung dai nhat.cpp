#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.length();
		int res = 0;
		stack<int> st;
		for(int i = 0; i < n; ++i){
			if(s[i] == '(') st.push(i);
			else{
				if(st.size() > 0){
					res += 2;
					st.pop();
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
