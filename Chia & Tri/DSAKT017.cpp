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
// Date: 21/02/22 19:40
// Program: Day xau nhi phan
// -------------------  Your code STARTS here !!!---------------------------

ll fb[100], k;
int n;

char fiboW(int n, ll k){
	if(n == 1) return '0';
	if(n == 2) return '1';
	if(k < fb[n - 2]) 
		return fiboW(n - 2, k);
	return fiboW(n - 1, k - fb[n - 2]);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	fb[0] = 0; fb[1] = 1;
	for(int i = 2; i <= 92; i ++)
		fb[i] = fb[i - 1] + fb[i - 2];
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		cout << fiboW(n, k - 1) << endl;
	}
	return 0;
}

