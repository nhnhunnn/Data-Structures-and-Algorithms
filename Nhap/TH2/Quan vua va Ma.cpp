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
// Date: 18/03/22 12:40
// Program: Quan vua va ma
// -------------------  Your code STARTS here !!!---------------------------

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

const int dxx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dyy[] = {2, 1, -1, -2, -2, -1, 1, 2};

char a[105][105];
int n, m;
pair<int, int> king, horse;
map<pair<int, int>, int>  mp, mp2;
void King(){
    queue<pair<int, int> > q;
    q.push(king);
    mp.clear();
    mp[king] = 1;
    while(!q.empty()){
        int x = q.front().f, y = q.front().s;
        q.pop();
        for(int i = 0; i < 8; ++i){
            int u = x + dx[i], v = y + dy[i];
            if(a[u][v] == '.' && u <= n && v <= n && u >= 1 && v >= 1 && mp[{u, v}] == 0){
                q.push({u, v});
                mp[{u, v}] = mp[{x, y}] + 1;
            }
        }
    }
}

void Horse(){
   queue<pair<int, int>, int > q;
   q.push(horse);
   mp2[horse] = 1; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin >> a[i][j];
                if(a[i][j] == 'T') king = {i, j};
                if(a[i][j] == 'M') horse = {i, j};
            }
        }
    }
    return 0;
}