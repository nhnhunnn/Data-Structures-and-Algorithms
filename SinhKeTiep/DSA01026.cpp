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
// Date: 24/02/2022 10:47
// Program: Phat Loc
// -------------------  Your code STARTS here !!!---------------------------

int a[30], n;
bool ok;

void init(){
	cin >> n;
	for(int i = 1; i <= n; i ++) a[i] = 6;
	ok = false;
}

bool check(){
	for(int i = 1; i <= n; i ++){
		if(a[1] == 6 || a[n] == 8)
			return false;
		else if(a[i] == 8 && a[i + 1] == 8)
			return false;
		else if(a[i] == 6 && a[i + 1] == 6 && a[i + 2] == 6 && a[i + 3] == 6)
			return false; 
	}
	return true;
}

void next(){
	int i = n;
	while(i >= 1 && a[i] == 8){
		a[i] = 6;
		--i;
	}
	if(i == 0) ok = true;
	else a[i] = 8;
}

void output(){
	for(int i = 1; i <= n; i ++) cout << a[i];
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();	
	while(!ok){
		if(check())
			output();
		next();
	}
	return 0;
}