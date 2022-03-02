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
// Date: 23/02/2022 14:24
// Program: So xa cach
// -------------------  Your code STARTS here !!!---------------------------

int n, a[15], b[15];
bool visited[15];

bool check(vector<int> c, int n){
	for(int i = 0; i < n; i ++)
		if(c[i] - c[i + 1] == 1 || c[i] - c[i + 1] == -1)
			return false;
	return true;
}
void init(){
	cin >> n;
	for(int i = 1; i <= n; i ++)
		b[i] = i;
	memset(visited, false, sizeof(visited));
	memset(a, 0, sizeof(a));
}

void Solve(){
	vector<int> c;
	for(int i = 1; i <= n; i ++)
		c.push_back(b[a[i]]);
	if(check(c, n - 1)){
		for(int i = 0; i < n; i ++)
			cout << c[i];
		cout << endl;
	}	
}
void Try(int i){
	for(int j = 1; j <= n; j ++){
		if(!visited[j]){
			a[i] = j;
			visited[j] = true;
			if(i == n) Solve();
			else Try(i + 1);
			visited[j] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		init();
		Try(1);
		cout << " " << endl;
	}
	return 0;
}
