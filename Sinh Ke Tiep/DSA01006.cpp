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
// Date: 09/02/22 19:26
// Program: Hoan vi nguoc
// -------------------  Your code STARTS here !!!---------------------------

int a[100], n, k, Istrue[100] = {};

void output(){
	for(int i = n; i >= 1; i --)
		cout << a[i] ;	
	cout << " ";
}

void Try(int i){
	for(int j = n; j >= 1 ; j --){
		if(Istrue[j] == 0){
			Istrue[j] = 1;
			a[i] = j;
			if(i == 1) output();
			else Try(i - 1);
			Istrue[j] = 0;
		}	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		cin >> n ;
		Try(n);
		cout << endl;
	}
	return 0;
}
