#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;

const ll mod = 1e9 + 7;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

// Author: Nguyen Quoc Dat
// ID: B20DCPT053
// Organization: PTIT
// Date: 07/03/22 10:30
// Program: Khoang cach 2 node la
// -------------------  Your code STARTS here !!!---------------------------
int n;
vector<int> adj[1005];
bool visited[1005];

void dfs(int u, int v, int cnt){
    if(u == v){
        cout << cnt << endl;
        return;
    }
    visited[u] = true;
    for(auto x: adj[u]){
        if(!visited[x]){
            dfs(x, v, cnt + 1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        for(int i = 0; i < 1005; ++i) adj[i].clear();
        cin >> n;
        for(int i = 1; i < n; ++i){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int q; cin >> q;
        while(q--){
            int u, v; cin >> u >> v;
            memset(visited, false, sizeof(visited));
            dfs(u, v, 0);
        }
    }
    return 0;
} 
