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
// Date: 16/03/22 08:27
// Program: Hinh chu nhat 0 - 1
// -------------------  Your code STARTS here !!!---------------------------

int n, m, a[501][501];
int max_of_area(int x[]){
	int res = 0, i = 0;
	stack<int> st;
	while(i < m){
		if(st.empty() || x[i] >= x[st.top()]) 
			st.push(i++);
		else{
			int top = st.top(); st.pop();
			if(st.empty())
				res = max(res, i * x[top]);
			else
				res = max(res, x[top]* (i - st.top() - 1));
		}
	}
	while(!st.empty()){
		int top = st.top(); st.pop();
		if(st.empty())
			res = max(res, i * x[top]);
		else
			res = max(res, x[top] * (i - st.top() - 1));
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) cin >> a[i][j];
		
		int r[n][m];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(i == 0) r[i][j] = a[i][j];
				else if(a[i][j]) r[i][j] = r[i - 1][j] + 1;
				else r[i][j] = 0;
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans = max(ans, max_of_area(r[i]));
		cout << ans << endl;
	}
	return 0;
}
