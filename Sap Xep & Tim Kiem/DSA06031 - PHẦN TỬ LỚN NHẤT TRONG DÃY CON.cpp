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
// Date: 09/02/22 12:19
// Program: Phan tu lon nhat trong day con
// -------------------  Your code STARTS here !!!---------------------------

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[n + 5], res[n + 5];
		for(int i = 1; i <= n; i ++) cin >> a[i];

		deque<int> dq;
		while(dq.size()) dq.pop_front();
		for(int i = 1; i <= n; i ++){
			while(dq.size() && a[dq.back()] <= a[i])
				dq.pop_back();
			dq.push_back(i);
			if(dq.front() + k <= i) dq.pop_front();
			if(i >= k) res[i] = a[dq.front()];
		}	
		for(int i = k; i <= n; i ++) 
			cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}
