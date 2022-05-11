#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; 
	cin >> t;
	cin.ignore();
	while(t--){
		string a; getline(cin, a);
		stack<int> s;
		vector<int> v;
		int id = 1;
		for(int i = 0; i < a.size(); i++){
			if(a[i] == '('){
				s.push(id); 
				v.push_back(id); 
				++id;
			}else if(a[i] == ')'){
				int x = s.top(); 
				v.push_back(x); 
				s.pop();
			}
		}
		for(auto x: v) cout << x << " ";
		cout << endl;
	}
}
