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
// Date: 09/02/22 22:10
// Program: HAHAHA
// -------------------  Your code STARTS here !!!---------------------------

char a[20];
const string r = "AH";
int n;

bool check(){
	for(int i = 0; i < n; i ++){
		if(a[0] == 'A' || a[n - 1] == 'H') 
			return false;
		else if(a[i] == a[i + 1] && a[i + 1] == 'H') 
			return false;
	}
	return true;
}

void output(){
	for(int i = 0; i < n; i ++) cout << a[i];
	cout << endl;
}

void Try(int i){
	for(int j = 0; j <= 1; j ++){
		a[i] = r[j];
		if(i == n - 1){
			if(check())
				output();
		}
		else Try(i + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		cin >> n;
		Try(0);
	}
	return 0;
}

