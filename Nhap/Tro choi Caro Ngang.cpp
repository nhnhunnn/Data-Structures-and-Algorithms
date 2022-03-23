#include <bits/stdc++.h>
using namespace std;
int a[16], n, k;
char x;
set<string> s;
bool check(){
	int cntzero = 0, cntone = 0, m1 = 0, m2 = 0;
	for(int i = 1; i <= n; ++i){
		if(a[i] == k){
			cntzero ++;
			m1 = max(m1, cntzero);
			cntone = 0;
		}
		else{
			cntone ++;
			m2 = max(m2, cntone);
			cntzero = 0;
		}
	}
	return (m1 > m2 && m1 >= 5);
}
void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			if(check()){
				string tp = "";
				for(int k = 1; k <= n; ++k){
					if(a[k] == 0) tp += "O";
					else tp += "X";
				}
				s.insert(tp);
			}
		}
		else Try(i + 1);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> x;
		s.clear();
		if(x == 'X') k = 1; 
		else k = 0;
		Try(1);
		for(auto y: s) cout << y << endl;
	}
}
