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
// Date: 27/02/22 18:25
// Program: Dem so bit 1 
// -------------------  Your code STARTS here !!!---------------------------

ll Solve(ll n, ll index, ll cnt){
	if(index % 2 == 1) 
		return 1;
	if(index == cnt)
		return (n % 2);
	if(index > cnt)
		return Solve(n / 2, index - cnt, cnt / 2);
	return Solve(n / 2, index, cnt / 2);
}

int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		ll n, l, r, res = 0;
		cin >> n >> l >> r;
		ll cnt = pow(2, (ll)log2(n));
		for(ll i = l; i <= r; i ++)
			res += Solve(n, i, cnt);
		cout << res << endl;
	}
	return 0;
}
