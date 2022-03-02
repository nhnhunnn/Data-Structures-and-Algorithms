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
// Date: 11/02/22 21:45
// Program: Sap xep quan hau 2
// -------------------  Your code STARTS here !!!---------------------------

bool col[25], dwn[25], ops[25];
int a[100], x[100][100];
int n = 8, k, res;

void init(){
	ms(col, true);
	ms(dwn, true);
	ms(ops, true);
	res = -oo;
	ms(x, 0);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >> x[i][j];
}

void Solve(){
	int sum = 0;
	for(int i = 1; i <= n; i ++)
		sum += x[i][a[i]];
	res = max(res, sum);
}

void Try(int i){
	for(int j = 1; j <= n; j ++){
		if(col[j] && dwn[i - j + n] && ops[i + j - 1]){
			a[i] = j;
			col[j] = false;
			dwn[i - j + n] = false;
			ops[i + j - 1] = false;
			if(i == n) 
				Solve();
			else 
				Try(i + 1);
			col[j] = true;
			dwn[i - j + n] = true;
			ops[i + j - 1] = true;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		init();
		Try(1);
		cout << res << endl;
	}
	return 0;
}
