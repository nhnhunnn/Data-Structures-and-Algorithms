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
// Program: Bien doi Trung to -> Hau to
// -------------------  Your code STARTS here !!!---------------------------

int Priority(char c){
	if(c == '+' || c == '-') 
		return 1;
	if(c == '*' || c == '/') 
		return 2;
	if(c == '^') 
		return 3;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t; cin >> t;
	cin.ignore();
	while(t--){
		string s; getline(cin, s);
		int n = s.length();
		stack<char> st;
		string res = "";
		for(int i = 0; i < n; i ++){
			if(isalpha(s[i]))
				res += s[i];
			else if(s[i] == '(') st.push(s[i]);
			else if(s[i] == ')'){
				while(!st.empty() && st.top() != '('){
					char c = st.top(); st.pop();
					res += c;
				}
				if(st.top() == '(') st.pop();
			}
			else {
				while(!st.empty() && Priority(s[i]) <= Priority(st.top())){
					char c = st.top(); st.pop();
					res += c;
				}
				st.push(s[i]);
			}
		}
		while(!st.empty() && st.top() != '('){
			char c = st.top(); st.pop();
			res += c;
		}
		cout << res << endl;
	}
	return 0;
}
 