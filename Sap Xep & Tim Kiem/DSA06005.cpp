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
// Date: 08/02/22 21:00
// Program: Hop va giao hai day so 2
// -------------------  Your code STARTS here !!!---------------------------


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> a(n);
		set<int> st, sm;
		for(int i = 0; i < n; i ++){
			cin >> a[i];
			st.insert(a[i]);
		}
		int k = 0;
		for(int i = 1; i <= m; i ++){
			int x; cin >> x;
			st.insert(x);
			if(n + i - st.size() - k != 0){
				sm.insert(x);
				k++;
			}
		}
		for(auto x: st) cout << x << " ";
		cout << endl;
		for(auto x: sm) cout << x << " ";
		cout << endl;
	}
	return 0;
}
