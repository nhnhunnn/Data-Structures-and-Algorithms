#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool vs[10005];
vector<int> adj[10005];
stack<int> st;
int n, m, connect;
int ver = 0, bri = 0;
void bfs(int u){
	queue<int> q;
	q.push(u);
	vs[u] = true;
	while(!q.empty()){
		int v = q.front(); q.pop();
		vs[v] = true;
		for(auto x: adj[v]){
			if(!vs[x]){
				q.push(x);
				vs[x] = true;
			}
		}
	}
}
void Vertex(int u){
	memset(vs, false, sizeof(vs));
	vs[u] = true;
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(!vs[i]){
			++cnt;
			bfs(i);
		}
	}
	if(cnt > connect) ver++;
}
bool cmp(int u, int v, int a, int b){
	if((u == a && v == b) || v == a && u == b)
		return false;
	return true;
}
void bfs2(int u, int a, int b){
	queue<int> q;
	q.push(u);
	vs[u] = true;
	while(!q.empty()){
		int v = q.front(); q.pop();
		vs[v] = true;
		for(auto x: adj[v]){
			if(!vs[x] && cmp(v, x, a, b)){
				q.push(x);
				vs[x] = true;
			}
		}
	}
}
void Bridge(int u, int v){
	memset(vs, false, sizeof(vs));
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(!vs[i]){
			++cnt;
			bfs2(i, u, v);
		}
	}
	if(cnt > connect) bri++;
}

int main(){
	int t = 1;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < 10005; ++i) adj[i].clear();
		memset(vs, false, sizeof(vs));
		for(int i = 1; i <= m; ++i){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		connect = 0;
		for(int u = 1; u <= n; ++u){
			if(!vs[u]){
				++connect;
				bfs(u);
			}
		}
		memset(vs, false, sizeof(vs));
		for(int u = 1; u <= n; ++u)
			Vertex(u);
		for(int u = 1; u <= n; ++u){
			for(auto v: adj[u]){
				if(u > v) continue;
				else Bridge(u, v);
			}
		}
		cout << ver << " " << bri << endl;
	}
}
