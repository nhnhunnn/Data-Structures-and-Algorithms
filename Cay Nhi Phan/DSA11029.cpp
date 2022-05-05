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
// Program: Duong di toi node la
// -------------------  Your code STARTS here !!!---------------------------
int n;
vector<int> adj[1005];
bool visited[1005];
vector<string> res;

void dfs(int u, string a){
    if(adj[u].empty()) 
        res.push_back(a);
    visited[u] = true;
    for(auto v: adj[u]){
        if(!visited[v])
            dfs(v, a + " " + to_string(v));
    }
}
bool cmp(string a, string b){
    int x = a.find_last_of(" ");
    int y = b.find_last_of(" ");
    string m = a.substr(x, a.size() - x);
    string n = b.substr(y, b.size() - y);
    return stoi(m) < stoi(n);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < 1005; ++i) adj[i].clear();
        cin >> n;
        if(n == 1) {
            cout << 1 << endl;
            continue;
        }
        for(int i = 1; i < n; ++i){
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }
        res.clear();
        dfs(1, "1");
        sort(res.begin(), res.end(), cmp);
        for(auto x: res){
            cout << x << endl;
        }
    }
    return 0;
} 