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
// Date: 21/02/22 20:00
// Program: Gap doi day so
// -------------------  Your code STARTS here !!!---------------------------

ll Power(int n, ll k){
	if(k == 0) 
		return 1;
	if(k == 1) 
		return n;
	if(k % 2 == 0) 
		return Power(n, k / 2) * Power(n, k / 2);
	return n * Power(n, k / 2) * Power(n, k / 2);
} 

ll Solve(int n, ll k){
	if(k == Power(2, n - 1))
		return n;
	if(k < Power(2, n - 1)) 
		return Solve(n - 1, k);
	return Solve(n - 1, k - Power(2, n - 1));
} 

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int t; cin >> t;
	while(t--){
		int n; ll k;
		cin >> n >> k; 
		cout << Solve(n, k) << endl; 
	} 
	return 0;
}
