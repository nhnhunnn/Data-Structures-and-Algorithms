#include <bits/stdc++.h>
using namespace std;
void Solve(){
	string a; getline(cin, a);
	stack<int> st;
	for(int i = 0; i < a.size(); ++i){
		if(a[i] == '[' || a[i] == '(') st.push(a[i]);
		else if(a[i] == ']' || a[i] == ')'){
			if(st.empty()){
				cout << "NO";
				return;
			}
			int tp = st.top();
			if(tp == 91 && a[i] == ']') st.pop();
			else if(tp == 40 && a[i] == ')') st.pop();
			else{
				cout << "NO";
				return;
			} 
		}
	}
	if(st.empty()) cout << "YES";
	else cout << "NO";
}
int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		Solve();
		cout << endl;
	}
}
