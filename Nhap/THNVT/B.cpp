#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; 
	cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n + 1], b[n + 1];
		b[0] = 1;
		for(int i = 0; i < n; i++) cin >> a[i];
		stack<int> st;
		st.push(0);
		for(int i = 1; i < n; i++){
			while(!st.empty() && a[st.top()] <= a[i]) 
				st.pop();
			if(st.empty()) b[i] = i + 1;
			else b[i] = i - st.top();
			st.push(i);
		}
		for(int i = 0; i < n; i++) 
			cout << b[i] << " ";
		cout << endl;
	}
}
