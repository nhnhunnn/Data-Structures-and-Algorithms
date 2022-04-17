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
// Program: Kiem tra day ngoac dung
// -------------------  Your code STARTS here !!!---------------------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t; cin >> t; 
	cin.ignore();
	while(t--){
		string str; getline(cin, str);
		stack <char> stk;
		bool ok = true;
		for(int i = 0; i < str.size(); i ++){
			if(str[i] == '{' || str[i] == '[' || str[i]=='(') 
				stk.push(str[i]);
			else if(str[i]=='}'){
				if(stk.empty()) ok = false;
				else if(stk.top()=='{') stk.pop();
				
			}
			else if(str[i]==']'){
				if(stk.empty()) ok = false;
				else if(stk.top()=='[') stk.pop();
			}
			else if(str[i]==')'){
				if(stk.empty()) ok = false;
				else if(stk.top()=='(') stk.pop();
			}
		}
		if(stk.size() > 0) 
			ok = false;
		if(ok) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}