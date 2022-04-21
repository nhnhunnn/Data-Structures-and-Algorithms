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
// Date: 08/03/22 12:30
// Program: Duong di va chu trinh Euler tren do thi co huong
// -------------------  Your code STARTS here !!!---------------------------

bool visited[1005];
vector<int> adj[1005];
int n, m, cnt;
void BFS(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int v = q.front(); q.pop();
        visited[v] = true;
        for(auto x: adj[v]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            cout << "0";
            return;
        }
    }
    cout << cnt;
}

void check(){ // vo huong
    memset(visited, false, sizeof(visited));
    cnt = 0;
    for(int u = 1; u <= n; ++u){
        if(adj[u].size() % 2 == 1) cnt++;
    }
    if(cnt == 0) cnt = 2;
    else if(cnt != 2) {
        cout << "0";
        return;
    }
    else cnt = 1;
    BFS(1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        for(int i = 0; i <= 1005; i ++) adj[i].clear();
        cin >> n >> m;


        // co huong
        vector<pair<int, int> > v(n + 5);
        for(int i = 1; i <= m; i ++){
            int x, y; cin >> x >> y;
            v[x].s ++;  // ban bac vao
            v[y].f ++;  // ban bac ra
        }
        bool ok = false;
        for(int u = 1; u <= n; ++u){
            if(v[u].f != v[u].s){
                cout << 0;
                ok = true;
                break;
            }
        }
        if(!ok) cout << 1;
        cout << endl;
    }
    return 0;
}
