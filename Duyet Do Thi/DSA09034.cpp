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
// Date: 09/03/22 19:55
// Program: Dem so ao
// -------------------  Your code STARTS here !!!---------------------------

const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int a[101][101];
int n, m;

void DFS(int x, int y){
    a[x][y] = 0;
    for(int i = 0; i < 8; i ++){
        int x1 = x + dx[i], y1 = y + dy[i];
        if(a[x1][y1] && x1 > 0 && x1 <= n && y1 > 0 && y1 <= m){
            DFS(x1, y1);
            a[x1][y1] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j) {
                char x; cin >> x;
                if(x == 'W') a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(a[i][j]){
                    ++cnt;
                    DFS(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}