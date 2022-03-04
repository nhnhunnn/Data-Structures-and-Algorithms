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
// Date: 11/02/22 14:55
// Program: Dat ten - DSA02023
// -------------------  Your code STARTS here !!!---------------------------

int n, m, k, c[100];
vector<string> v;
string s;

void init(){
	cin >> m >> k;
	cin.ignore();
	getline(cin, s);
	stringstream ss(s);
	v.clear();
	string t;
	set<string> st;
	while(ss >> t){
		st.insert(t);
	}
	for(auto &x: st) v.push_back(x);
	n = st.size();
}

void output(){
	for(int i = 1; i <= k; i ++)
		cout << v[c[i] - 1] << " ";
	cout << endl;
}

void Try(int i){
	for(int j = c[i - 1] + 1; j <= n - k + i; j ++){
		c[i] = j;
		if(i == k) output();
		else Try(i + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	Try(1);
	return 0;
}
