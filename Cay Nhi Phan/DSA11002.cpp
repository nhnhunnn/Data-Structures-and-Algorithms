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
// Date: 07/03/22 10:30
// Program: Cay bieu thuc 2
// -------------------  Your code STARTS here !!!---------------------------

bool isOperator(string x){
	return (x == "+" || x == "-" || x == "*" || x == "/");
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<string> s(n);
		for(auto &x: s) cin >> x;
		queue<ll> q;
		for(int i = n - 1; i >= 0; i--){
			if(isOperator(s[i])){
				ll a = q.front(); q.pop();
				ll b = q.front(); q.pop();
				if (s[i] == "-") q.push(b - a);
				else if (s[i] == "+") q.push(b + a);
				else if (s[i] == "*") q.push(b * a);
				else if (s[i] == "/") q.push(b / a);
			}
			else q.push(stoll(s[i]));
		}
		cout << q.front() << endl;
	}
	return 0;
}
