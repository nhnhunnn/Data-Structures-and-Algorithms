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
// Date: 04/03/22 19:59
// Program: Xem Phim
// -------------------  Your code STARTS here !!!---------------------------

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int k, n; cin >> k >> n;
	int a[n + 2];
	ll L[n+ 2][25005];
	memset(L, 0, sizeof(L));
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= k; j ++){
			if(j >= a[i] && L[i - 1][j - a[i]] + a[i] > L[i - 1][j]) 
				L[i][j] = L[i - 1][j - a[i]] + a[i];
			else 
				L[i][j] = L[i - 1][j]; 
		} 
	} 
	cout << L[n][k] << endl;
	return 0;
}