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
// Program: Bien doi Tien to -> Hau to
// -------------------  Your code STARTS here !!!---------------------------
bool isOperator(char c){
	return c == '+' || c == '-' || c == '/' || c == '*';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

 	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.length();
		stack<string> st;
		for(int i = n - 1; i >= 0; --i){
			if(isOperator(s[i])) {
				string s1 = st.top(); st.pop();
				string s2 = st.top(); st.pop();
				string tmp = s1 + s2 + s[i];
				st.push(tmp);
			}
			else st.push(string(1, s[i]));
		}
		cout << st.top() << endl;
	}
	return 0;
 }