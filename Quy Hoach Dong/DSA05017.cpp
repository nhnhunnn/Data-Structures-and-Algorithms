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
// Date: 03/03/22 16:48
// Program: Day so bitonic
// -------------------  Your code STARTS here !!!---------------------------

int n, a[105];
int f1[105], f2[105];
int res;

void Solve() {
    for (int i = 2; i <= n; i ++) 
        for (int j = 1; j < i; j ++) 
            if (a[j] < a[i] && f1[j] + a[i] > f1[i])
                f1[i] = f1[j] + a[i];
    for (int i = n - 1; i >= 1; i --) 
        for (int j = n; j > i; j --) 
            if (a[i] > a[j] && f2[j] + a[i] > f2[i])
                f2[i] = f2[j] + a[i];
    for (int i = 1; i <= n; i ++)
        res = max(res, f1[i] + f2[i] - a[i]);
    cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
            f1[i] = f2[i] = a[i];     
        }
        res = 0;
        Solve();
    }
    return 0;
}