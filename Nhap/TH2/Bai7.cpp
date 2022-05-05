#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited[10005];
bool check[10005];
vector<int> adj[10005];
vector<int> readj[10005];
stack<int> st;
int n, m;
void dfs(int u){
	visited[u] = true;
	for(auto v: adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
	st.push(u);
}
void dfs2(int u){
	check[u] = true;
	for(auto v: readj[u]){
		if(!check[v])
			dfs2(v);
	}
}
int main(){
	int t = 1;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < 10005; ++i) adj[i].clear();
		for(int i = 0; i < 10005; ++i) readj[i].clear();
		memset(visited, false, sizeof(visited));
		memset(check, false, sizeof(check));
		for(int i = 1; i <= m; ++i){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			readj[v].push_back(u);
		}
		for(int u = 1; u <= n; ++u){
			if(!visited[u]){
				dfs(u);
			}
		}
		ll res = 0;
		while(!st.empty()){
			int u = st.top(); st.pop();
			if(!check[u]){
				++res;
				dfs2(u);
			}
			else if(!st.empty() && check[st.top()]) st.pop();
		}
		cout << res << endl;
	}
}
