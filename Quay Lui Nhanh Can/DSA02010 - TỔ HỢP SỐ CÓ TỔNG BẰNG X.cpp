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
// Date: 13/02/22 16:48
// Program: To hop so co tong = x, Quay lui
// -------------------  Your code STARTS here !!!---------------------------

int n, S, k, a[25];
vt res;

void init(){
	cin >> n >> S;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	res.clear();
}

void Try(int i, int sum, vector<int> v){
	if(sum > S)
		return;
	if(sum == S){
		res.push_back(v);
		return;
	}
	for(int j = i; j <= n; j ++){
		if(sum + a[j] <= S){
			v.push_back(a[j]);
			Try(j, sum + a[j], v);
			v.pop_back();
		}
	}
}

void output(){
	if(res.size() == 0) cout << -1;
	else{
		for(auto x: res){
			cout << "[";
			int l = x.size();
			for(int i = 0; i < l - 1; i ++)
				cout << x[i] << " ";
			cout << x.back() << "]";
		}
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		init();
		vector<int> v;
		v.clear();
		Try(1, 0, v);
		output();
	}
	return 0;
}
