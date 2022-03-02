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
// Date: 11/02/22 20:42
// Program: Day con co tong = K
// -------------------  Your code STARTS here !!!---------------------------

int n, c[15], a[15], k, S;
vt res;

void init(){
	cin >> n >> S;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
}

void Try(int i){
	for(int j = 0; j <= 1; j ++){
		c[i] = j;
		if(i == n){
			vector<int> t;
		    int sum = 0;
		    for(int i = 1; i <= n; i ++){
		        if(c[i] == 1){
		            t.push_back(a[i]);
		            sum += a[i];
		        }
		    }
		    if(sum == S) res.push_back(t);
		}
		else Try(i + 1);
	}
}

void output(){
	if(res.size() != 0){
		reverse(res.begin(), res.end());
		for(int i = 0; i < res.size(); i ++){
			cout << "[";
			for(int j = 0; j < res[i].size() - 1; j ++)
				cout << res[i][j] << " ";
			cout << res[i][res[i].size() - 1] << "] ";
		}
	}
	else
		cout << -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		res.clear();
		init();
		Try(1);
		output();
		cout << endl;
	}
	return 0;
}

