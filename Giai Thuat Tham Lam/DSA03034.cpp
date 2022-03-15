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
// Date: 01/03/22 16:51
// Program: Day con chung
// -------------------  Your code STARTS here !!!---------------------------

int n, m, k;
vector<ll> res;
void Solve(){
	cin >> n >> m >> k;
	ll a[n], b[m], c[k];
	int i = 0, j = 0, l = 0;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	for(int i = 0; i < k; i++) cin >> c[i];
	res.clear();
	while(i < n && j < m && l < k){
		if(a[i] == b[j] && b[j] == c[l]){
			res.push_back(a[i]);
			++ i;
			++ j;
			++ l;
		}
		else if(a[i] <= b[j] && a[i] <= c[l]){
			++ i;
		}
		else if(b[j] <= a[i] && b[j] <= c[l]){
			++ j;
		}
		else
			++ l;
	}
	if(res.size() == 0)
		cout << "NO";
	else
		for(int i = 0; i < res.size(); i++) 
			cout <<  res[i] << " ";
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t --){
		Solve();
		cout << endl;
	}
	return 0;
}