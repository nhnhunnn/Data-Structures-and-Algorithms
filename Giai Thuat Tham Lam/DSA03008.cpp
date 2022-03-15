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
// Date: 02/03/22 14:08
// Program: Sap xep cong viec 1
// -------------------  Your code STARTS here !!!---------------------------

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<pair<int, int> > vp;
		for(int i = 0; i < n; i ++){
			int x; cin >> x;
			vp.push_back({x, 0});
		}
		for(int i = 0; i < n; i ++){
			int x; cin >> x;
			vp[i].s = x;
		}
		int cnt = 1, index = 0;
		sort(vp.begin(), vp.end(), cmp);
		for(int j = 1; j < n; j ++){
			if(vp[j].f >= vp[index].s) {
				++cnt;
				index = j;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}