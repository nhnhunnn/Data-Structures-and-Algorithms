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
// Date: 23/03/22 01:30
// Program: To mau do thi
// -------------------  Your code STARTS here !!!---------------------------

int color[15], n, m, k;
vector<int> adj[15];

bool check(int u, int c){
    for(auto v: adj[u]){
        if(c == color[v])
            return false;
    }
    return true;
}
bool DFS(int u){
    if(u == n + 1)
        return true;
    for(int c = 1; c <= k; ++c){
        if(check(u, c)){
            color[u] = c;
            if(DFS(u + 1)) return true;
            color[u] = 0;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        for(int i = 0; i < 15; i ++) adj[i].clear();
        memset(color, 0, sizeof(color));
        cin >> n >> m >> k;
        for(int i = 1; i <= m; i ++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        cout << (DFS(1) ? "YES" : "NO") << endl;
    }
    return 0;
}