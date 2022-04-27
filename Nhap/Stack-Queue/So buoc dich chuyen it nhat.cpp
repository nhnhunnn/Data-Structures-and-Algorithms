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
// Date:
// Program: 
// -------------------  Your code STARTS here !!!---------------------------

int a[1005][1005], b[1005][1005];
int n, m;

void bfs() {
    queue<pair<int, int> > q;
    q.push({1, 1});
   	b[1][1] = 0;
    while (!q.empty()) {
        int x = q.front().f, y = q.front().s;
        q.pop();
        if (x == n && y == m) {
            cout << b[x][y] << endl;
            return;
        }
        if (x + 1 <= n) {
            int i = x + abs(a[x][y] - a[x + 1][y]), j = y;
            if (i <= n && b[i][j] == oo) {
                b[i][j] = b[x][y] + 1;
                q.push({i, j});
            }
        }
        if (y + 1 <= m) {
            int i = x, j = y + abs(a[x][y] - a[x][y + 1]);
            if (j <= m && b[i][j] == oo) {
                b[i][j] = b[x][y] + 1;
                q.push({i, j});
            }
        }
        int i = x + abs(a[x][y] - a[x + 1][y + 1]), j = y + abs(a[x][y] - a[x + 1][y + 1]);
        if (i <= n && j <= m && b[i][j] == oo) {
            b[i][j] = b[x][y] + 1;
            q.push({i, j});
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	cout.tie(NULL);
	
    int t; cin >> t;
    while (t--) {
    	cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) cin >> a[i][j];
    	for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) b[i][j] = oo;
		bfs();
    }
    return 0;
}
