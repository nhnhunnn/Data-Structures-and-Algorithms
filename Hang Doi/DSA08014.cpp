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
// Date: 15/03/22 22:54
// Program: Gieo Mam
// -------------------  Your code STARTS here !!!---------------------------

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int res;
int a[505][505], n, m;

void BFS(){
    cin >> n >> m;
    queue<pair<pair<int, int>, int> > q;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> a[i][j];
            if(a[i][j] == 2) q.push({{i, j}, 0});
        }
    }
    while(!q.empty()){
        pair<int, int> idx = q.front().f;
        int cnt = q.front().s;
        q.pop();
        res = max(res, cnt);
        for(int i = 0; i < 4; ++i){
            int x = idx.f + dx[i], y = idx.s + dy[i];
            if(x >= 0 && y >= 0 && x < n && y < m && a[x][y] == 1){
                q.push({{x, y}, cnt + 1});
                a[x][y] = 2;
            }
        }
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            if(a[i][j] == 1){
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        BFS();
    }
    return 0;
}