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
// Date: 09/02/22 22:29
// Program: Tap Hop
// -------------------  Your code STARTS here !!!---------------------------


int n, k, s, t, ck = false;
int cnt = 0;
int a[21];

void init(){
	for(int i = 1; i <= k; i ++)
		a[i] = i;
}

void sum(){
	int tmp = 0;
	for(int i = 1; i <= k; i ++){
		tmp += a[i];
	}
	if(tmp == s) cnt++;
}

void next(){
	sum();
	int i = k;
	while(a[i] == n - k + i && i >= 1) i--;
	if(i == 0) ck = true;
	else{
		a[i] ++;
		for(int j = i + 1; j <= k; j ++)
			a[j] = a[i] + j - i;
		
	} 
}

void solve(){
	while(!ck)
		next();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(1){
		cin >> n >> k >> s;
		if(n == 0 && k == 0 && s == 0) break;
		else if(n < k) cout << 0 << endl;
		else{
			init();
	    	solve();
	    	cout << cnt << endl;
			ck = false;
			cnt = 0;	
		}
	}
	return 0;
}

