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
// Date: 09/02/22 18:38
// Program: Sinh to hop
// -------------------  Your code STARTS here !!!---------------------------

int c[50], n, k;
bool ok = false;

void init(int k){
	for(int i = 1; i <= k; i ++)
		c[i] = i;
}
void next(){
	int i = k;
	while(c[i] == n - k + i) i--;
	if(i == 0) ok = true;
	else{
		c[i] ++;
		for(int j = i + 1; j <= k; j ++)
			c[j] = c[i] + j - i;
	}
}
void output(){
	for(int i = 1; i <= k; i ++) 
		cout << c[i];
	cout << " ";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		ok = false;
		init(k);
		while(!ok){
			output();
			next();
		}
		cout << endl;
	}
	return 0;
}
