#include <bits/stdc++.h>
using namespace std;
int n, m, a[1001][1001], b[1001][1001];
void bfs(){
	queue<pair<int, int> > q;
	q.push({1, 1});
	b[1][1] = 0;
	while(!q.empty()){
		int x = q.front().first, y = q.front().second; q.pop();
		if(x == n && y == m){
			cout << b[n][m] << endl;
			return;
		}
		if(x <= n - 1){
			int c = x + abs(a[x][y] - a[x + 1][y]), d = y;
			if(c <= n && b[c][d] == INT_MAX){
				b[c][d] = b[x][y] + 1;
				q.push({c, d});
			}
		}
		if(y <= m - 1){
			int c = x , d = y + abs(a[x][y] - a[x][y + 1]);
			if(d <= m && b[c][d] == INT_MAX){
				b[c][d] = b[x][y] + 1;
				q.push({c, d});
			}
		}
		int c = x + abs(a[x][y] - a[x + 1][y + 1]), d = y + abs(a[x][y] - a[x + 1][y + 1]);
		if(c <= n && d <= m && b[c][d] == INT_MAX){
			b[c][d] = b[x][y] + 1;
			q.push({c, d});
		}
	}
	cout << -1 << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) cin >> a[i][j], b[i][j] = INT_MAX;
		bfs();
	}
}
