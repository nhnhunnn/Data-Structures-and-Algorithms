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
// Date: 07/04/22 17:09
// Program: Day con tang dai nhat hai chieu
// -------------------  Your code STARTS here !!!---------------------------

ll n;
pair<int, int> a;
set<pair<int, int> > st[100005];

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.f < b.f && a.s < b.s;
}
bool check(set<pair<int, int> >& s) {
	for (auto x: s)
		if (cmp(x, a)) return true;
		else if (x.f >= a.f) break;
	return false;
}
ll binary_Search(ll l, ll r) {
	while (l < r) {
		ll m = (l + r) / 2;
		if (check(st[m]))
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> n;
	for (ll i = 0; i < n; i ++) {
		cin >> a.f >> a.s;
		ll index = binary_Search(0, n);
		if (index < n) {
			set<pair<int, int> >::iterator it = ++st[index].insert(a).f;
			while (it != st[index].end()) {
				if(cmp(a, *it))
					st[index].erase(it++);
				else it++;
			}
		}
	}
	ll res = 0;
	while (res < n && !st[res].empty())
		res++;
	cout << res << endl;
	return 0;
}
