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
// Date: 24/02/2022 12:51
// Program: Hoan vi cac chu so
// -------------------  Your code STARTS here !!!---------------------------

int n, k, a[10];
vector<string> v;
ll res;
bool ok;

void init(){
	cin >> n >> k;
	v.clear();
	for(int i = 0; i < n; i ++){
		string s; cin >> s;
		v.push_back(s);
	}
	for(int i = 1; i <= k; i ++) a[i] = i;
	res = mod;
	ok = false;
}

void update(){
	vector<string> s = v;
	sort(s.begin(), s.end());
	res = min(res, stoll(s.back()) - stoll(s.front()));
	s.clear();
}

void next(){
	int i = k - 1;
	while(a[i] > a[i + 1] && i >= 1) --i;
	if(i == 0) ok = true;
	else{
		int j = k;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		for(int h = 0; h < n; h ++){
			swap(v[h][i - 1], v[h][j - 1]);
		}
		reverse(a + i + 1, a + k + 1);
		for(int h = 0; h < n; h ++){
			reverse(v[h].begin() + i, v[h].end());
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	while(!ok){
		update();
		next();
	}
	cout << res << endl;
	return 0;
}