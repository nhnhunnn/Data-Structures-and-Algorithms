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
// Date: 08/04/22 15:45
// Program: Cau truc du lieu hang doi 1
// -------------------  Your code STARTS here !!!---------------------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

 	int t; cin >> t;
	while(t--){
		int query; cin >> query;
		queue<int> q;
		int n, m;
		while(query--){
			cin >> n;
			if(n == 1){
				cout << q.size() << endl;
			}
			else if(n == 2) {
				if(!q.empty()) cout << "NO" << endl;
				else cout << "YES" << endl;
			}
			else if(n == 3){
				cin >> m;
				q.push(m);
			}
			else if(n == 4){
				if(!q.empty()) q.pop();
			}
			else if(n == 5){
				if(!q.empty()) cout << q.front() << endl;
				else cout << -1 << endl;
			}
			else if(n == 6) {
				if(!q.empty())
					cout << q.back() << endl;
				else cout << -1 << endl;
			}
		}
	}
	return 0;
}