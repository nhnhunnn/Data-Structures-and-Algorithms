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
// Date: 07/03/22 22:10
// Program: Liet ke Canh cau
// -------------------  Your code STARTS here !!!---------------------------

bool visited[1005];
vector<int> adj[1005];
int n, m, connect;

bool cmp(int u, int v, int a, int b){
    if ((u == a &&  v == b ) || (v == a && u == b)) 
        return false;
    return true;
}

void BFS(int u, int a, int b){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int v = q.front(); q.pop();
        visited[v] = true;
        for (auto x: adj[v]){
            if (!visited[x] && cmp(v, x, a, b)){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

void Bridge(int u, int v){
    memset (visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        if (!visited[i]){
            ++cnt;
            BFS(i, u, v);
        }
    }
    if (cnt > connect) cout << u << " " << v << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--){
        for(int i = 0; i <= 1005; i ++) adj[i].clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i ++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        memset(visited, false, sizeof(visited));
        connect = 0;
        for (int i = 1; i <= n; ++i){
            if(!visited[i]){
                ++connect;
                BFS(i, -1, -1);
            }
        }
        for (int u = 1; u <= n; ++u){
            for (auto v: adj[u]){
                if(u > v) 
                    continue;
                else 
                    Bridge(u, v);
            }
        }
        cout << endl;
    }
    return 0;
}
