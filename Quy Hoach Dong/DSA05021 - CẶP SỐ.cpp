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
// Date: 05/03/22 09:54
// Program: Cap So QHD
// -------------------  Your code STARTS here !!!---------------------------

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.f < b.f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int> > v;
        for(int i = 0; i < n; i ++){
            int x, y; cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> b(n + 1, 1);
        int res = 1;
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i; j ++)
                if(v[j].s < v[i].f) 
                    b[i] = max(b[i], b[j] + 1);
            res = max(res, b[i]);
        }
        cout << res << endl;
    }
    return 0;
}
