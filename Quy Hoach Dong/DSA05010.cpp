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
// Date: 12/03/22 10:30
// Program: Day con lien tiep co tong chia het cho K
// -------------------  Your code STARTS here !!!---------------------------

vector<vector<int> > f;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<int> a;
		int sum = 0;
		for(int i = 0; i < n; i ++){
			int x; cin >> x;
			x %= k;
			if(x){
				a.push_back(x);
				sum += x;
				sum %= k;
			}
		}
		if(a.size() < 2)
			cout << n - a.size();
		
		else{
			int l = a.size();
			f.clear();
			f.resize(l + 1);
			for(int i = 0; i < l + 1; i ++) f[i].resize(k, k);
			f[0][0] = 0;
			for(int i = 1; i <= l; i ++){
				for(int j = 0; j < k; j ++){
					if(j - a[i - 1] >= 0)
						f[i][j] = min(f[i - 1][j], f[i - 1][j - a[i - 1]] + 1);
					else
						f[i][j] = min(f[i - 1][j], f[i - 1][k - j + a[i - 1]] + 1);
				}
			}
			cout << n - f[l][sum] << endl;
		}
		cout << endl;
	}
	return 0;
}