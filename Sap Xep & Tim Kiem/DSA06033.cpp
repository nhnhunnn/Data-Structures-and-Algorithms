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
// Date: 15/02/22 20:48
// Program: Khoang Cach xa nhat
// -------------------  Your code STARTS here !!!---------------------------


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;cin >> t;
	while (t--){
		int n; cin >> n;
		vector<pair<int, int> > a;
		for (int i = 0; i < n; i++){
			int x; cin >> x;
			a.push_back({x, i});
		}
		sort(a.begin(), a.end());
		int index = a[0].s, tmp = a[0].first;
		int res = -1;
		for (int i = 1; i < n; i++){
			if (a[i].f > tmp)
				res = max(res, a[i].s - index);
			if (index> a[i].s){
				index = a[i].s;
				tmp = a[i].f;
			}
		}
		cout << res << endl;
	}
	return 0;
}