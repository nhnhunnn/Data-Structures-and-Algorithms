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
// Date: 21/02/22 14:19
// Program: Phan tu khac nhau
// -------------------  Your code STARTS here !!!---------------------------

int Binary_Search(int a[], int b[], int n){
	int t = n; 
	int l = 0, r = n - 1;
	while(l <= r){
		int m = (l + r) / 2 ;
		if(a[m] == b[m]) l = m + 1;
		else{
			t = m;
			r = m - 1; 
		} 
	} 
	return t; 
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n], b[n - 1]; 
		for(auto &x: a) cin >> x;
		for(auto &x: b) cin >> x;
		cout << Binary_Search(a, b, n) + 1 << endl; 
	} 
	return 0;
}
