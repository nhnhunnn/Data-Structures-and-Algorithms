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
// Date: 11/02/22 20:20
// Program: Day con tang dan
// -------------------  Your code STARTS here !!!---------------------------

int a[25], c[25], n, k;
vector<string> res;

void init(){
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
}

void solve(){
	string t = "";
	for(int i = 1; i <= k; i ++){
		t += (" " + to_string(a[c[i]]));
	}
	t.erase(0, 1);
	res.push_back(t);
}

bool check(){
	for(int i = 1; i < k; i ++){
		if(c[i] > c[i + 1])
			return false;
	}
	return true;
}

void Try(int i){
	for(int j = c[i - 1] + 1; j <= n - k + i; j ++){
		c[i] = j;
		if(i == k){
			if(check())
				solve();
		}
		else Try(i + 1);
	}
}

void output(){
	sort(res.begin(), res.end());
	for(int i = 0; i < res.size(); i ++)
		cout << res[i] << endl;
}

int main(){
	init();
	for(int l = 2; l <= n; l ++){
		k = l;
		memset(c, 0, sizeof(c));
		Try(1);
	}
	output();
	return 0;
}

