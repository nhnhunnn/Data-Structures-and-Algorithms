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
// Date: 01/03/22 16:27
// Program: Nham chu so
// -------------------  Your code STARTS here !!!---------------------------

string change(string x, int n1, int n2){
	for(int i = 0; i < x.size(); i ++){
		if(x[i] - 48 == n1)
			x[i] = (char) n2 + 48;
	}
	return x;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	string a, b; cin >> a >> b;
	cout << stoll(change(a, 6, 5)) + stoll(change(b, 6, 5)) 
	<< " " << stoll(change(a, 5, 6)) + stoll(change(b, 5, 6)) << endl;
	return 0;
}
