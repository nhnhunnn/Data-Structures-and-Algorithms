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
// Date: 11/02/22 09:12
// Program: Tim Boi So
// -------------------  Your code STARTS here !!!---------------------------

int n, idx, a[100];
bool ok;
ll res;

void init(){
	cin >> n;
	memset(a, 0, sizeof(a));
	res = 1e18;
	ok = false;
	idx = 1;
}

void Try(int i){
	for(int j = 0; j <= 1; j ++){
		a[i] = j;
		if(i == idx){
			ll x = 0;
			for(int k = 1; k <= idx; k ++)
				x = 10 * x + a[k];
			x *= 9;
			if(x % n == 0 && x >= n){
				res = min(res, x);
				ok = true;
			}
		}
		else Try(i + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		init();
		while(idx < 18 && !ok){
			Try(1);
			idx++;
		}
		cout << res << endl;
	}
	return 0;
}
