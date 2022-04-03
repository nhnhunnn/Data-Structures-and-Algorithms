#include <bits/stdc++.h>
using namespace std;
int n, a[20];
bool ok;
void sinhketiep(){
	int i = n;
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i == 0) ok = true;
	else a[i] = 1;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		int cnt = 1;
		ok = false;
		int x = pow(2, n);
		while(!ok){
			cnt++;
			for(int i = 1; i <= n; ++i) cout << (a[i] == 0 ? "A" : "B");
			if(cnt <= x) cout << ",";
			else cout << endl;
			sinhketiep();
		}
	}
	return 0;
}
