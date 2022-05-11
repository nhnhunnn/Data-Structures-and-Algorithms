#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; 
	cin >> t;
	while(t--){
		int n; cin >> n;
		queue<string> q;
		q.push("6");
		q.push("8");
		for(int i = 0; i < n; ++i){
			string s = q.front(); q.pop();
			q.push(s + "6");
			q.push(s + "8");
			string a = s;
			reverse(a.begin(), a.end());
			cout << s << a << " ";
		}
		cout << endl;
	}
}
