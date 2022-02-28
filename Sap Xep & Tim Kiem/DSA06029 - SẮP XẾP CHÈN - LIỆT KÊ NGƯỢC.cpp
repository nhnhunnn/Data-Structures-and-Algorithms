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
// Date: 08/02/22 16:18
// Program: Sap xep chen nguoc
// -------------------  Your code STARTS here !!!---------------------------

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<int> a(n);
	for(auto &x: a) cin >> x;
	
	vector<string> res;
	for(int i = 0; i < n; i ++){
		string r = "Buoc " + to_string(i) + ": ";
		for(int j = 0; j < i; j ++){
			for(int k = j + 1; k <= i; k ++)
				if(a[j] > a[k])
					swap(a[j], a[k]);
		}
		for(int j = 0; j <= i; j ++)
			r = r + to_string(a[j]) + " ";
		res.push_back(r);
	}
	reverse(res.begin(), res.end());
	for(auto x: res) cout << x << endl;
	return 0;
}
