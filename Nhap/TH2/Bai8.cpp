#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited[1005];
bool check[1005];
vector<int> adj[1005];
int n, m;
bool dfs(){
	stack<int> st;
	for(int u = 0; u < n; ++u){
		if(visited[u]) continue;
		st.push(u);
		while(!st.empty()){
			int v = st.top();
			if(!visited[v]){
				visited[v] = true;
				check[v] = true;
			}else{
				check[v] = false;
				st.pop();
			}
			for(auto x: adj[v]){
				if(!visited[x]) st.push(x);
				else if(check[x]) return true;
			}
		}
	}
	return false;
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < 1005; ++i) adj[i].clear();
		memset(visited, false, sizeof(visited));
		memset(check, false, sizeof(check));
		for(int i = 1; i <= m; ++i){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
		}
		if(dfs()) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
}
