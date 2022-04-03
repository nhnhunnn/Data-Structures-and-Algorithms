#include <bits/stdc++.h>
using namespace std;
int r[1000005];
int main(){
	int a, b; cin >> a >> b;
	int cnt = 0;
	memset(r, 0, sizeof(r));
	for(int i = 1; i <= b; ++i){
		for(int j = 2 * i; j <= b; j += i){
			r[j] += i;
		}
	}
	for(int i = a; i <= b; ++i){
		if(r[i] > i) cnt ++;
	}
	cout << cnt << endl;
}