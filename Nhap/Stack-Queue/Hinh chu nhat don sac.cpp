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

ll Max_Area(vector<ll> a, int n){
	stack<ll> st;
	ll res = LLONG_MIN, k = 0;
	while(k < n){
		if(st.empty() || a[k] >= a[st.top()]){
			st.push(k);
			k++;
		}
		else{
			ll i = st.top();
			st.pop();
			if(st.empty()) res = max(res, k * a[i]);
			else res = max(res, a[i] * (k - st.top() - 1));
		}
	}
	while(!st.empty()){
		ll i = st.top();
		st.pop();
		if(st.empty()) res = max(res, k * a[i]);
		else res = max(res, a[i] * (k - st.top() - 1));
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	cout.tie(NULL);

	int n, m; cin >> m >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) b[i] = m - a[n - i - 1];
	reverse(b.begin(), b.end());
	ll ans = max(Max_Area(a, n), Max_Area(b, n));
	cout << ans << endl;
	return 0;
}