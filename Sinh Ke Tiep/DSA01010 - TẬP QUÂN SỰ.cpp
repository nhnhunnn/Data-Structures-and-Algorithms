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
// Date: 10/02/22 16:19
// Program: Tap Quan Su
// -------------------  Your code STARTS here !!!---------------------------

int n, k, c[100];
bool ok;
set<int> s;

void init(){
	ok = false;
	s.clear();
	cin >> n >> k;
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		s.insert(c[i]);
	}
}

void next(){
	int i = k;
	while(i > 0 && n - k + i == c[i]) i--;
	if(i > 0){
		c[i] ++;
		for(int j = i + 1; j <= k; j ++ ){
			c[j] = c[i] - i + j;
			s.insert(c[j]);
		}
		s.insert(c[i]);
	}
	else ok = true;
}

void output(){
	for(int i = 1; i <= k; i ++)
		cout << c[i] << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		init();
		next();
		if(!ok) cout << s.size() - k;
		else cout << k;
		cout << endl;
	}
	return 0;
}


