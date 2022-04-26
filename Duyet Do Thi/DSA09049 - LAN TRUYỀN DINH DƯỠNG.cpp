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
// Program: Lan truyen dinh duong
// tham khao Nguyen Duc Anh B20DCCN056
// -------------------  Your code STARTS here !!!---------------------------

bool visited[200005];
vector<int> adj[200005];
vector<ll> res;
vector<ll> cnt;

void DFS(int u){
    visited[u] = true;
    for(auto v: adj[u]){
        if(!visited[v])
            DFS(v);
        cnt[u] += (cnt[v] + 1);
        res[u] += res[v];
    }
    res[u] += cnt[u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while(t--){
        for(int i = 0; i < 200005; i ++) adj[i].clear();
        int n; cin >> n;
        memset(visited, false, sizeof(visited));
        for(int i = 2; i <= n; i ++){
            int u; cin >> u;
            adj[u].push_back(i);
        }
        res.resize(n + 1, 1);
        cnt.resize(n + 1, 0);
        DFS(1);
        for(int u = 1; u <= n; ++u) cout << res[u] << " ";
        cout << endl;
    }
    return 0;
}
