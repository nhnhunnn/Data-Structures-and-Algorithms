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
// Date:11/02/22 23:27
// Program: Doi tien - sinh ke tiep
// -------------------  Your code STARTS here !!!---------------------------

int n, k, c[100], a[100], S;
int res = 0;
bool mr;

void init(){
	cin >> n >> S;
	for(int i = 1; i <= n; i ++) cin >> a[i];
}

void next(int k){
	int i = k;
	while(i > 0 && c[i] == n - k + i) --i;
	if(i <= 0) mr = true;
	else{
		c[i] ++;
		for(int j = i + 1; j <= k; j++)
			c[j] = c[i] + j - i;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	for(int x = 1; x <= n; x++){
		k = x;
		mr = false;
		for(int j = 1; j <= k; j ++)
			c[j] = j;
		while(!mr){
			int sum = 0;
			for(int z = 1; z <= k; z ++)
				sum += a[c[z]];
			if(sum == S){
				cout << k;
				return 0;
			}
			next(k);
		}
	}
	cout << -1;
	return 0;
}

