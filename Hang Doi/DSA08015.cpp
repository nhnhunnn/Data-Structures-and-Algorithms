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
// Date: 03/03/22 20:35
// Program: Di chuyen trong khong gian
// -------------------  Your code STARTS here !!!---------------------------

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
int a, b, c;
char pos[31][31][31];
bool vs[31][31][31];
bool ok;
struct Space{
    int x, y, z;
};

bool check(int x, int y, int z, int a, int b, int c){
    if(x >= a || y >= b || z >= c || x < 0 || y < 0 || z < 0 || pos[x][y][z] == '#')
        return false;
    return true;
}

int BFS(Space st, Space en){
    queue<pair<Space, int> > q;
    memset(vs, false, sizeof(vs));
    q.push({st, 0});
    pos[st.x][st.y][st.z] = '#';
    vs[st.x][st.y][st.z] = true;
    while(!q.empty()){
        Space u = q.front().f;
        int v = q.front().s; q.pop();
        if(u.x == en.x && u.y == en.y && u.z == en.z) return v; 
        for(int i = 0; i < 6; ++i){
            int m = u.x + dx[i], n = u.y + dy[i], l = u.z + dz[i];
            if(check(m, n, l, a, b, c) && !vs[m][n][l]){
                q.push({{m, n, l}, v + 1});
                vs[m][n][l] = true;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> a >> b >> c;
        Space st, en;
        for(int i = 0; i < a; ++i){
            for(int j = 0; j < b; ++j){
                for(int k = 0; k < c; ++k){
                    cin >> pos[i][j][k];
                    if(pos[i][j][k] == 'S') st = {i, j, k};
                    if(pos[i][j][k] == 'E') en = {i, j, k};
                }
            }
        }
        cout << BFS(st, en) << endl;
    }
    return 0;
}