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
// Date: 08/03/22 13:30
// Program: Tim duong
// -------------------  Your code STARTS here !!!---------------------------

const char Direct[] = {'N', 'S', 'W', 'E'};
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int n, m;
char a[505][505];
bool visited[505][505];
bool check;
pair<int, int> st, en;

bool cmp(int u, int v, int m, int n){
    return (u > 0 && u <= m && v > 0 && v <= n);
}

void DFS(int x, int y, int cnt, char drt){
    if(check) return;
    visited[x][y] = true;
    if(x == en.f && y == en.s && cnt <= 3){
        check = true;
        cout << "YES";
        return;
    }
    if(cnt > 3 || a[x][y] == 'T'){
        visited[x][y] = false;
        return;
    }

    for(int i = 0; i < 4; i ++){
        int x1 = x + dx[i], y1 = y + dy[i];
        if(cmp(x1, y1, m, n) && a[x1][y1] != '*' && !visited[x1][y1]) {
            if(Direct[i] == drt)
                DFS(x1, y1, cnt, Direct[i]);
            else 
                DFS(x1, y1, cnt + 1, Direct[i]);
        }
    }
    visited[x][y] = false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> m >> n;
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                cin >> a[i][j];
                if(a[i][j] == 'S') st = {i, j};
                if(a[i][j] == 'T') en = {i, j};
            }
        }
        check = false;
        memset(visited, false, sizeof(visited));
        DFS(st.f, st.s, 0, 'F');
        
        if(!check) cout << "NO";
        cout << endl;
    }
    return 0;
}