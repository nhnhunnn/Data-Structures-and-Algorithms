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
// Program: Chu trinh am - Bellman-Ford
// -------------------  Your code STARTS here !!!---------------------------

int adj[1005][1005];
int dis[1005];
int n, m;

void Check(){
    memset(dis, oo, sizeof(dis));
    dis[1] = 0;
    for(int k = 2; k <= n; ++k)
        for(int u = 1; u <= n; ++u)
            for(int v = 1; v <= n; ++v)
                if(dis[v] > dis[u] + adj[u][v])
                    dis[v] = dis[u] + adj[u][v];
    for(int u = 1; u <= n; ++u){
        for(int v = 1; v <= n; ++v){
            int w = dis[u] + adj[u][v];
            if(dis[v] > w){
                cout << 1 << endl;
                return;
            } 
        }
    }
    cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        memset(adj, oo, sizeof(adj));
        cin >> n >> m;
        for(int i = 1; i <= m; ++i){
            int u, v, w; cin >> u >> v >> w;
            adj[u][v] = w;
        }
        Check();
    }
    return 0;
}
