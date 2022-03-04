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
// Date: 20/02/22 12:36
// Program: Tu Dien
// -------------------  Your code STARTS here !!!---------------------------

const int mx = 3;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<vector<string> > a;
vector<string> res;
map<string, int> mp;
int k, n, m;
bool ok, visited[15][15];

void init(){
    cin >> k >> m >> n;
    mp.clear(); a.clear(); res.clear();
    while(k--){
        string s; cin >> s;
        mp[s] = 1;
    }
    for(int i = 1; i <= m; i ++){
        vector<string> t;
        for(int j = 1; j <= n; j ++){
            string s; cin >> s;
            t.push_back(s);
        }
        a.push_back(t);
        t.clear();
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int x, int y, string s){
    if(mp[s] >= 1) 
        res.push_back(s);
    for(int k = 0; k < 8; k ++){
        int i = x + dx[k];
        int j = y + dy[k];
        if(!visited[i][j] && i >= 0 && i < m && j < n && j >= 0){
            visited[i][j] = true;
            DFS(i, j, s + a[i][j]);
            visited[i][j] = false;
        }
    }
}
void Solve(){
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            visited[i][j] = true;
            DFS(i, j, string(a[i][j]));
            visited[i][j] = false;
        }
    }
    if(res.size() == 0) cout << -1;
    else{
        for(auto z: res) cout << z << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        init();
        Solve();
    }
    return 0;
}
