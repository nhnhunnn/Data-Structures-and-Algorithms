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
// Date: 01/03/22 16:51
// Program: Loai bo dau ngoac
// -------------------  Your code STARTS here !!!---------------------------

vector<string> res;
bool ktra(string s) {
	int x = 0, y = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			x++;
			y++;
		}
		if (s[i] == ')')x--;
		if (x < 0)return false;
	}
	if (y == 0&&s.length()==1)return false;
	return x == 0;
}
void BFS(string s) {
	if (!s.length())return;
	unordered_set<string> A;
	queue<string> B;
	A.insert(s);
	B.push(s);
	bool ok = false;
	while (B.size()) {
		string s = B.front();
		B.pop();
		if (ktra(s)&&s!="") {
			res.push_back(s);
			ok = true;
		}
		if (ok)continue;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == ')') {
				string a = s.substr(0, i) + s.substr(i + 1, s.length());
				if (A.find(a) == A.end()) {
					A.insert(a);
					B.push(a);
				}
			}

		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while (t--) {
		res.clear();
		string s; cin >> s;
		BFS(s);
		if (res.size() == 0)cout << -1;
		else {
			sort(res.begin(), res.end());
			for (auto s : res)cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}