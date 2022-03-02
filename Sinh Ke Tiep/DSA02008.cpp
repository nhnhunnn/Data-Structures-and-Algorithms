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
// Date: 10/02/22 16:17
// Program: Chon so tu ma tran vuong
// -------------------  Your code STARTS here !!!---------------------------

int n, k, a[12];
int x[105][105];
bool ok;
vt res;

void init(){
	ok = false;
	cin >> n >> k;
	res.clear();
	ms(a, 0);
	ms(x, 0);
	For(i, 1, n) a[i] = i;
	For(i, 1, n){
		For(j, 1, n)
			cin >> x[i][j];
	}
	
}

void check(){
	int sum = 0;
	For(i, 1, n)
		sum += x[i][a[i]];
	if(sum == k){
		vector<int> t;
		For(i, 1, n)
			t.push_back(a[i]);
		res.push_back(t);
	}
}

void next(){
	int i = n - 1;
	while(a[i] > a[i + 1]) i--;
	if(i == 0) ok = true;
	else{
		int j = n;
		while(a[j] < a[i]) j--;
		swap(a[i], a[j]);
		int d = i + 1, c = n;
		while(d < c){
			swap(a[d], a[c]);
			d ++;
			c --;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	while(!ok){
		check();
		next();
	}
	cout << res.size() << endl;
	For(i, 0, res.size() - 1){
		For(j, 0, res[i].size() - 1)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
