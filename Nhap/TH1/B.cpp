#include <bits/stdc++.h>
using namespace std;
int n, a[20], k;
char x;
bool check(){
	int cnt0 = 0, cnt1 = 0, m1 = 0, m2 = 0;
	for(int i = 1; i <= n; ++i){
		if(a[i] == k){
			cnt1++;
			m1 = max(m1, cnt1);
			cnt0 = 0;
		}
		else {
			cnt0++;
			m2 = max(m2, cnt0);
			cnt1 = 0;
		}
	}
	return (m1 >= 5 && m1 > m2);
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			if(check()){
				for(int k = 1; k <= n; ++k){
					if(a[k] == 1) cout << "X";
					else cout << "O";
				}
				cout << endl;
			}
		}
		else Try(i + 1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		cin >> n >> x;
		if(x == 'X') k = 1;
		else k = 0;
		Try(1);
	}
}