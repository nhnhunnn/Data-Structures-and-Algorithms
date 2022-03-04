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
// Date: 03/03/22 15:00
// Program: Cap diem gan nhat
// -------------------  Your code STARTS here !!!---------------------------

vector<pair<int, int> > v;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.f < b.f;
}

double Distance(int i, int j){
	double dx = v[i].f - v[j].f;
	double dy = v[i].s - v[j].s;
	return (ld) sqrt(dx * dx + dy * dy);
}

double Nearest(int l, int r){
	if(r <= l)
		return oo;
	if(l == r - 1)
		return Distance(l, r);
	int m = (l + r) >> 1;
	double res = min(Nearest(l, m), Nearest(m + 1, r));
	vector<int> a;

	for(int i = m; i >= l && v[m].f - v[i].f <= res; --i) a.push_back(i);

	for(int i = m + 1; i <= r && v[m].f - v[i].f <= res; ++i) a.push_back(i);

	sort(a.begin(), a.end());
	int n = a.size();
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n && j < 8 + i; ++j){
			if(v[a[i]].s - v[a[j]].s > res)
				break;
			res = min(res, Distance(a[i], a[j]));
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		v.clear();
		for(int i = 0; i < n; i ++){
			int x, y; cin >> x >> y;
			v.push_back({x, y});
		}
		sort(v.begin(), v.end(), cmp);
		cout << setprecision(6) << fixed << Nearest(0, n - 1) << endl;
	}
	return 0;
}