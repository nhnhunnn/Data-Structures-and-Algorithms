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
// Date: 07/03/22 14:30
// Program: Di chuyen trong ma tran - queue
// -------------------  Your code STARTS here !!!---------------------------

int a[1001][1001], c[1001][1001], n, m;
void BFS(){
    queue <pair<int, int> > q;
    memset(c, -1, sizeof(c));
    q.push({1, 1});
    c[1][1] = 0;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first, j = p.second;
        if(c[i + a[i][j]][j] == -1){
            q.push({i + a[i][j], j});
            c[i + a[i][j]][j] = c[i][j] + 1;
        }
        if(c[i][j + a[i][j]] == -1){
            q.push({i, a[i][j] + j});
            c[i][j + a[i][j]] = c[i][j] + 1;
        }
        if(c[n][m] != -1) break;
    }
    cout << c[n][m] << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++) cin >> a[i][j];
        BFS();
    }
    return 0;
}
