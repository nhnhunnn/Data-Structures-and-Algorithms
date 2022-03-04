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
// Date: 11/02/22 21:21
// Program: Tap con cua xau ky tu
// -------------------  Your code STARTS here !!!---------------------------

int n, k, c[20];
string s;
vector<string> res;

void init(){
	cin >> n >> s;
}

void Try(int i){
	for(int j = c[i - 1] + 1; j <= n - k + i; j ++){
		c[i] = j;
		if(i == k){
			string t = "";
			for(int g = 1; g <= k; g ++)
				t += s[c[g] - 1];
			res.push_back(t);
		}
		else Try(i + 1);
	}
}

void output(){
	sort(res.begin(), res.end());
	for(auto x: res)
		cout << x << " ";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		init();
		res.clear();
		for(int z = 1; z <= n; z++){
			k = z;
			memset(c, 0, sizeof(c));
			Try(1);
		}
		output();
		cout << endl;
	}
	return 0;
}
