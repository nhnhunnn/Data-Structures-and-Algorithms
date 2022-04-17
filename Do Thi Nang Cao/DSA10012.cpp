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
// Program: Duong di trung binh
// -------------------  Your code STARTS here !!!---------------------------

vector<int> adj[1005];
int n, m;
bool visited[1005];

int bfs(int u, int v){
    memset(visited, false, sizeof(visited));
    visited[u] = true;
    queue<pair<int, int> > q;
    q.push({u, 0});
    while(!q.empty()){
        pair<int, int> tmp = q.front(); q.pop();
        if(tmp.f == v) 
            return tmp.s;
        for(auto x: adj[tmp.f]){
            if(!visited[x]){
                q.push({x, tmp.s + 1});
                visited[x] = true;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        for(int i = 0; i < 1005; ++i) adj[i].clear();
        cin >> n >> m;
        for(int i = 1; i <= m; ++i){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }
        int sum = 0, cnt = 0;
        for(int u = 1; u <= n; ++u){
            for(int v = 1; v <= n; ++v){
                if(u != v && bfs(u, v)){
                    sum += bfs(u, v);
                    ++cnt;
                }
            }
        }
        cout << fixed << setprecision(2) << 1.0 * sum / cnt << endl;
    }
    return 0;
}