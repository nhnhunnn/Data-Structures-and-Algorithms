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
// Program: Dijkstra
// -------------------  Your code STARTS here !!!---------------------------

int n, m, st;
int D[1005], parent[1005];
vector<pair<int, int> > List[1005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

void Dijkstra(int st){
    for(int i = 1; i <= n; i++) {
        D[i] = 1e9;
        parent[i] = -1;
    }
    D[st] = 0;
    while(!q.empty()) q.pop();
    q.push({0, st});
    while(!q.empty()){
        int u = q.top().second; q.pop();
        for(int i = 0; i < List[u].size(); i++){
            int v = List[u][i].s;
            int d_u_v = List[u][i].f;
            if(D[u] + d_u_v < D[v]){
                D[v] = D[u] + d_u_v;
                parent[v] = u;
                q.push({D[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << D[i] << " ";
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> n >> m >> st;
        for(int i = 0; i <= n; i++) List[i].clear();
        for(int i = 1; i <= m; i++) {
            int u, v, w; cin >> u >> v >> w;
            List[u].push_back({w, v});
            List[v].push_back({w, u});
        }
        Dijkstra(st);
    }
    return 0;
}
