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
// Date: 24/02/2022 12:02
// Program: Ghep chu cai
// -------------------  Your code STARTS here !!!---------------------------

char x[15] = {'0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char c;
int n, a[15];
bool ok;

void init(){
	cin >> c;
	n = c - 'A' + 1;
	for(int i = 1; i <= n; i ++) a[i] = i;
	ok = false;
}

bool check(){
	for(int i = 2; i < n; i ++){
		if(x[a[i]] == 'A' || x[a[i]] == 'E'){
			if((x[a[i - 1]] != 'A' && x[a[i - 1]] != 'E') && (x[a[i + 1]] != 'A' && x[a[i + 1]] != 'E'))
				return false;
		}
	}
	return true;
}

void next(){
	int i = n - 1;
	while(a[i] > a[i + 1]) --i;
	if(i == 0) ok = true;
	else{
		int j = n;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	while(!ok){
		if(check()){
			for(int i = 1; i <= n; i ++) cout << x[a[i]];
			cout << endl;
		}
		next();
	}
	return 0;
}
