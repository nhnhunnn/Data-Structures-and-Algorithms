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
// Program: Floyd
// -------------------  Your code STARTS here !!!---------------------------

int c[105][105], n, m;

void Floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(c[i][j] > c[i][k] + c[k][j])
                    c[i][j] = c[i][k] + c[k][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(i == j) c[i][j] = 0;
            else c[i][j] = 1e9;
        }
    for(int i = 1; i <= m; i++){
        int u, v, k; 
        cin >> u >> v >> k;
        c[u][v] = c[v][u] = k;
    }
    Floyd();
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        cout << c[u][v] << endl;
    }
    return 0;
}
