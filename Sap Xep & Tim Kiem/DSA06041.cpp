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
// Date:
// Program:
// -------------------  Your code STARTS here !!!---------------------------


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		int n, a[100005], b[100005];
	    cin >> n;
	    for (int i=0; i<n; ++i) cin >> a[i];
	    sort(a, a + n);
		for (int i = a[0]; i <= a[n - 1]; ++i) 
			b[i]=0;
		for (int i=0; i<n; ++i) 
			b[a[i]]+=1;
		
		int max2=0, z;
		for (int i=0; i<n; ++i) {
			if (max2<b[a[i]]) {
				max2=b[a[i]];
				z=a[i];
			}
		}
		if(max2 > n/2)
			cout << z;
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
