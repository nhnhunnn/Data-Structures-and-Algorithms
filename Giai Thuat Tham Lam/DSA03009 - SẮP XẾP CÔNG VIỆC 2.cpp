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
// Date: 11/03/22 18:11
// Program: Sap xep cong viec 2
// -------------------  Your code STARTS here !!!---------------------------

struct job {
    int id;
    int d;
    int pr;
};

bool cmp(job a, job b) {
    return (a.pr > b.pr);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        job a[n];
        for(auto &x: a) cin >> x.id >> x.d >> x.pr;
        sort(a, a + n, cmp);
        int cnt = 0, res = 0;
        bool visited[n];
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = min(n, a[i].d) - 1; j >= 0; j--) {
                if (!visited[j]) {
                    cnt++;
                    res += a[i].pr;
                    visited[j] = true;
                    break;
                }
            }
        }
        cout << cnt << " " << res << endl;
    }
    return 0;
}
