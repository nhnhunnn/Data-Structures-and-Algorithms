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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	cout.tie(NULL);
	
    int t = 1;
    while (t--) {
    	int n; cin >> n;
        int a[n + 1], b[n + 1], c[n + 1];
        for(int i = 1; i <= n; ++i) cin >> a[i];
        stack<int> st;
        for(int i = n; i >= 1; --i){
            while(!st.empty() && a[st.top()] <= a[i]) st.pop();
            if(!st.empty()) b[i] = st.top();
            st.push(i);
        }
        for(int i = 1; i <= n; ++i) cout << b[i] << " ";
        cout << endl;
        stack<int> st1;
        for(int i = 1; i <= n; ++i){
            while(!st1.empty() && a[st1.top()] >= a[i]) st1.pop();
            if(!st1.empty()) c[i] = st1.top();
            st1.push(i);
        }
        for(int i = 1; i <= n; ++i) cout << c[i] << " ";
        cout << endl;
        ll res = 0;
        for(int i = 1; i <= n; ++i){
            if(c[i] == 0 || b[i] == 0) ++res;
        }
        cout << res + n - 1 << endl;
    }
    return 0;
}
