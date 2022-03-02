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
// Date: 19/02/22 21:02
// Program: Duong di dai nhat
// -------------------  Your code STARTS here !!!---------------------------

int n, m, res;
bool visited[30][30];

void init(){
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < m; i ++){
        int u, v; cin >> u >> v;
        visited[u][v] = true;
        visited[v][u] = true;
    }
}

void DFS(int u, int dis){
    res = max(res, dis);
    for(int v = 0; v < n; v++){
        if(visited[u][v]){
            visited[u][v] = false;
            visited[v][u] = false;
            DFS(v, dis + 1);
            visited[u][v] = true;
            visited[v][u] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        init();
        res = -oo;
        for(int u = 0; u < n; u ++)
            DFS(u, 0);
        cout << res << endl;
    }
    return 0;
}