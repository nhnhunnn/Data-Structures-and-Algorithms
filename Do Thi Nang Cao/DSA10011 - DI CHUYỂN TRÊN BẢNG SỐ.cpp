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
// Program: Di chuyen tren bang so
// -------------------  Your code STARTS here !!!---------------------------

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n, m;
int dis[505][505], a[505][505];
priority_queue <pair<pair<int, int>, int>, 
                vector<pair<pair<int, int>, int> >,
                greater<pair<pair<int, int>, int> > > q;

bool check(int x, int y){ return (x <= n && y <= m && x >= 1 && y >= 1);}
void Dijkstra(){
    dis[1][1] = a[1][1];
    while(!q.empty()) q.pop();
    q.push({{1, 1}, dis[1][1]});
    while(!q.empty()){
        pair<int, int> c = q.top().f;
        int x = c.f, y = c.s, w = q.top().s;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int u = x + dx[i], v = y + dy[i];
            if(check(u, v)){
                if(dis[u][v] > a[u][v] + w){
                    dis[u][v] = a[u][v] + w;
                    q.push({{u, v}, dis[u][v]});
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j) cin >> a[i][j], dis[i][j] = oo;
        Dijkstra();
        cout << dis[n][m] << endl;
    }
    return 0;
}
