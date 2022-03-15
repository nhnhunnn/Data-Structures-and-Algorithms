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
// Date: 02/03/22 20:40
// Program: Tim day so
// -------------------  Your code STARTS here !!!---------------------------

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int a[n];
	int m = +oo, res = 0;
	for(auto &x: a) {
		cin >> x;
		m = min(x, m);
	}
	for(int i = m; i >= 1; --i){
		bool ck = true;
		for(int j = 0; j < n; ++j){
			int r = a[j] / i;
			if(a[j] / r == i){
				while(r && a[j] / r == i) 
					r --;
				res += (r + 1);
			}
			else {
				res = 0;
				ck = false;
				break;
			}
		}
		if(ck){
			cout << res;
			return 0;
		}
	}
}