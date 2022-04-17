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
// Date: 13/03/22 13:30
// Program: Chu Cuu xa cach
// -------------------  Your code STARTS here !!!---------------------------

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, k, cnt;
int a[105][105], r[105][105][4];
bool visited[105][105];
bool check;
vector<int> v;
pair<int, int> st, en;

int up(int n){ return 2 * n - 1;}

bool cmp(int u, int v, int m, int n){
    return (u > 0 && u <= m && v > 0 && v <= n);
}

void DFS(int x, int y){
    visited[x][y] = true;
    cnt += a[x][y];
    for(int i = 0; i < 4; i ++){
        int x1 = x + dx[i], y1 = y + dy[i];
        if(cmp(x1, y1, n, n) && !r[x][y][i] && !visited[x1][y1])
            DFS(x1, y1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cnt = 0;
    cin >> n >> k >> m;
    v.clear();
    int res = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= m; i ++){
        int x, y, z, t; cin >> x >> y >> z >> t;
        if(x == z)
            (t > y) ? r[x][y][3] = r[z][t][2] = 1 : r[x][y][2] = r[z][t][3] = 1;
        if(y == t)
            (x > z) ? r[x][y][0] = r[z][t][1] = 1 : r[x][y][1] = r[z][t][0] = 1;
    }
    for(int i = 1; i <= k; i ++) {
        int x, y; cin >> x >> y; a[x][y] = 1;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(!visited[i][j] && a[i][j]){
                DFS(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
        }
    }
    for(int i = 0; i < v.size() - 1; ++i){
        for(int j = i + 1; j < v.size(); ++j)
            res += v[i] * v[j];
    }
    cout << res << endl;
    return 0;
} 