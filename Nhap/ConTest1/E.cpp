#include <bits/stdc++.h>
using namespace std;
int a[20][20], b[20][20], n, k;
bool mr;
set<string> res;
void Try(int i, int j, string s){
	if(i == 1 && j == 1 && !a[i][j]){
		mr = false;
		return;
	}
	if(i == n && j == n && a[i][j]){
		res.insert(s);
		mr = true;
		return;
	}
	if(i < n && a[i + 1][j] && !b[i + 1][j]){
		b[i + 1][j] = 1;
		Try(i + 1, j, s + "D");
		b[i + 1][j] = 0;
	}
	if(j < n && a[i][j + 1] && !b[i][j + 1]){
		b[i][j + 1] = 1;
		Try(i, j + 1, s + "R");
		b[i][j + 1] = 0;
	}
	if(i > 1 && i <= n && a[i - 1][j] && !b[i - 1][j]){
		b[i - 1][j] = 1;
		Try(i - 1, j, s + "U");
		b[i - 1][j] = 0;
	}
	if(j > 1 && j <= n && a[i][j - 1] && !b[i][j - 1]){
		b[i][j - 1] = 1;
		Try(i , j - 1, s + "L");
		b[i][j - 1] = 0;
	}
	if((i < n && j < n && !a[i][j]) || i > n || j > n || i < 1 || j < 1)
		return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		cin >> n;
		res.clear();
		memset(b, 0, sizeof(b));
		b[1][1] = 1;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				cin >> a[i][j];
		mr = false;
		Try(1, 1, "");
		if(!mr) cout << -1;
		else{
			cout << res.size() << " ";
			for(auto x: res) cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
