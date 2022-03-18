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
// Date: 09/03/22 14:08
// Program: Lua chon tham lam
// -------------------  Your code STARTS here !!!---------------------------

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long m, s; cin >> m >> s;
	if(s == 0 || s > 9 * m){
		cout << "-1 -1";
		return 0;
	}
	if(s == 0 && m == 1){
		cout << "0 0";
		return 0;
	}
	else{
		int a[m], b[m];
		for(int i = 0; i < m; ++i){
			if(s > 9){
				a[i] = b[i] = 9;
				s -= 9;
			}
			else{
				a[i] = b[i] = s;
				s = 0;
			}
		}
		if(b[m - 1] == 0){
			b[m - 1] = 1;
			for(int i = m - 2; i >= 0; --i){
				if(b[i] != 0){
					--b[i];
					break;
				}
			}
		}
		reverse(b, b + m);
		for(auto x: b) cout << x;
		cout << " ";
		for(auto x: a) cout << x;
	}
	return 0;
}
