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
// Date: 13/03/22 19:45
// Program: Hop Mat
// -------------------  Your code STARTS here !!!---------------------------

int n, m, k;
vector<int> adj[1005], a;
bool visited[1005];
map<int, int> mp;

void DFS(int u){
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            visited[v] = true;
            mp[v]++;
            DFS(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n >> m;
    a.clear(); a.resize(k);
    mp.clear();
    for(int i = 0; i < 1005; i ++) adj[i].clear();

    for(auto &x: a) cin >> x;
    for(int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for(auto u: a){
        memset(visited, false, sizeof(visited));
        mp[u]++;
        DFS(u);
    }
    int res = 0;
    for(int i = 1; i <= n; i ++)
        if(mp[i] == k) 
            ++res;
    cout << res << endl;
    return 0;
} 
