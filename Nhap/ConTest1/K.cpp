#include <bits/stdc++.h>
using namespace std;
char x[505][505];
int main(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j) cin >> x[i][j];
	}
	int res = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(x[i][j] == '#') ++res;
			if(x[i][j] == '#' && x[i + 1][j] == '#') --res;
			if(x[i][j] == '#' && x[i][j + 1] == '#') --res;
		}
	}
	cout << res << endl;
}
