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
// Date: 16/03/22 00:15
// Program: Phan tu ben phai nho hon
// -------------------  Your code STARTS here !!!---------------------------

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n];
		for(auto &x: a) cin >> x;
		int fg[n], g[n];
		stack<int> s1, s2;
		for(int i = n - 1; i >= 0; i--){
			while(!s1.empty() && a[s1.top()] <= a[i])
				s1.pop(); 
			if(s1.empty()) fg[i] = -1; 
			else fg[i] = s1.top();
			s1.push(i); 
		}
		for(int i = n - 1; i >= 0; i--){
			while(!s2.empty() && a[s2.top()] >= a[i])
				s2.pop(); 
			if(s2.empty()) g[i] = -1; 
			else g[i] = s2.top();
			s2.push(i); 
		}
		for(int i=0;i<n;i++){
			if(fg[i] != -1 && g[fg[i]] != -1) 
				cout << a[g[fg[i]]] << " ";
			else 
				cout << -1 << " "; 
		} 
		cout << endl; 
	} 
	return 0;
} 
