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
// Date: 12/02/22 08:02
// Program: Day so 1
// -------------------  Your code STARTS here !!!---------------------------

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for(auto &x: v) cin >> x;
		vector<string> res;
		string t = "[";
		for(int i = 0; i < v.size() - 1; i ++)
			t += " " + to_string(v[i]);
		t.erase(1, 1);
		t += " " + to_string(v[v.size() - 1]) + "]";
		if(v.size() == 1) t.erase(1, 1);
		res.push_back(t);
		while(n > 1){
			for(int i = 0; i < v.size() - 1; i ++)
				v[i] = v[i] + v[i + 1];
			v.pop_back();
			string t = "[";
			for(int i = 0; i < v.size() - 1; i ++)
				t += " " + to_string(v[i]);
			t.erase(1, 1);
			t += " " + to_string(v[v.size() - 1]) + "]";
			if(v.size() == 1) t.erase(1, 1);
			res.push_back(t);
			n--;
		}
		reverse(res.begin(), res.end());
		for(auto x: res) cout << x << " ";
		cout << endl;
	}
    return 0;
}
