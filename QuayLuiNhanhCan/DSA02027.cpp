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
// Date: 11/02/22 19:48
// Program: Nguoi du lich - nhanh can
// -------------------  Your code STARTS here !!!---------------------------

int n, visited[100];
long c[20][20], x[100], s = 0, res = 1e7, cmin = 1e7;

void init(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			cin >> c[i][j];
			cmin = min(cmin, c[i][j]);
		}
	}
	memset(visited, 1, sizeof(visited));
	visited[1] = 0;
	x[1] = 1;
}
void Try(int i){
	if(s + cmin * (n - i + 1) >= res) 
		return;
	for(int j = 1; j <= n; j ++){
		if(visited[j]){
			x[i] = j;
			visited[j] = 0;
			s += c[x[i - 1]][j];
			if(i == n){
				if(s + c[x[n]][x[1]] < res)
					res = s + c[x[n]][x[1]];
			}
			else Try(i + 1);
			visited[j] = 1;
			s -= c[x[i - 1]][j];
		}

	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	Try(2);
	cout << res << endl;
	return 0;
}

