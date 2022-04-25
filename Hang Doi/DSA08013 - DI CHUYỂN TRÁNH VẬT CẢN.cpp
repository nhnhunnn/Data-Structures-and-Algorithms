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
// Date: 18/03/22 22:30
// Program: Di chuyen tranh vat can
// -------------------  Your code STARTS here !!!---------------------------

char a[101][101];
int vs[101][101], n;

bool check(int x, int y, int n, int m){
    if(x >= n || y >= m || x < 0 || y < 0 || a[x][y] == 'X')
        return false;
    return true;
}
void BFS(pair<int, int> b){
    memset(vs, -1, sizeof(vs));
    queue<pair<int, int> > q;
    q.push(b);
    vs[b.f][b.s] = 0;
    while(!q.empty()){
        pair<int, int> t = q.front(); q.pop();
        int x = t.f, y = t.s;

        for(int j = y + 1; j < n; ++j){
            if(check(x, j, n, n) && vs[x][j] == -1){
                vs[x][j] = vs[x][y] + 1;
                q.push({x, j});
            }
            else break;
        }
        for(int j = y - 1; j >= 0; --j){
            if(check(x, j, n, n) && vs[x][j] == -1){
                vs[x][j] = vs[x][y] + 1;
                q.push({x, j});
            }
            else break;
        }
        for(int j = x + 1; j < n; ++j){
            if(check(j, y, n, n) && vs[j][y] == -1){
                vs[j][y] = vs[x][y] + 1;
                q.push({j, y});
            }
            else break;
        }
        for(int j = x - 1; j >= 0; --j){
            if(check(j, y, n, n) && vs[j][y] == -1){
                vs[j][y] = vs[x][y] + 1;
                q.push({j, y});
            }
            else break;
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++) cin >> a[i][j];
        pair<int, int> st, en;
        cin >> st.f >> st.s >> en.f >> en.s;
        BFS(st);
        cout << vs[en.f][en.s] << endl;
    }
    return 0;
} 
