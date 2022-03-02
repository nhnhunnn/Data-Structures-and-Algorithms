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
// Date: 11/02/22 22:04
// Program: May ATM
// -------------------  Your code STARTS here !!!---------------------------

int n, S, a[35], res, cnt;

void init(){
	cin >> n >> S;
	res = oo;
	for(int i = 0; i < n; i ++) cin >> a[i];
	
}

void Try(int i, int sum, int cnt){
	if(sum > S || cnt > n)
		return;
	if(i == n){
		if(sum == S) 
			res = min(res, cnt);
		return;
	} 
	Try(i + 1, sum, cnt);
	Try(i + 1, sum + a[i], cnt + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		init();
		Try(0, 0, 0);
		if(res == oo) cout << -1 << endl;
		else cout << res << endl;
	}
	return 0;
}
