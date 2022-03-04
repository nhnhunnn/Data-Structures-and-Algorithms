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
// Date: 12/02/22 18:26
// Program: Di chuyen trong me cung 2
// -------------------  Your code STARTS here !!!---------------------------

int a[20][20], b[20][20], n, k;
bool mr;
vector<string> res;

void init(){
	cin >> n;
	res.clear();
	ms(b, 0);
	b[1][1] = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			cin >> a[i][j];
	mr = false;
}

void Try(int i, int j, string s){
	if(i == 1 && j == 1 && !a[i][j]){
		mr = false;
		return;
	}
	if(i == n && j == n && a[i][j]){
		res.push_back(s);
		mr = true;
		return;
	}
	if(i < n && a[i + 1][j] && !b[i + 1][j]){
		b[i + 1][j] = 1;
		Try(i + 1, j, s + "D");
		b[i + 1][j] = 0;
	}
	if(j < n && a[i][j + 1] && !b[i][j + 1]){
		b[i][j + 1] = 1;
		Try(i, j + 1, s + "R");
		b[i][j + 1] = 0;
	}
	if(i > 1 && i <= n && a[i - 1][j] && !b[i - 1][j]){
		b[i - 1][j] = 1;
		Try(i - 1, j, s + "U");
		b[i - 1][j] = 0;
	}
	if(j > 1 && j <= n && a[i][j - 1] && !b[i][j - 1]){
		b[i][j - 1] = 1;
		Try(i , j - 1, s + "L");
		b[i][j - 1] = 0;
	}
	if((i < n && j < n && !a[i][j]) || i > n || j > n || i < 1 || j < 1)
		return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		init();
		Try(1, 1, "");
		if(!mr) cout << -1;
		else{
			sort(res.begin(), res.end());
			for(auto x: res) cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
