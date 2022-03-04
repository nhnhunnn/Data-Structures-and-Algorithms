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
// Date: 22/02/22 16:00
// Program: Ngay dac biet
// -------------------  Your code STARTS here !!!---------------------------

string s;
vector<string> res;
int a[10], n = 8;
void init(){
	memset(a, 0, sizeof(a));
	res.clear();
	s = "00000000";
}
bool check(string x){
	if(x[2] == '2' || x[4] == '0')
		return false;
	if(x[1]  == '0' && x[0] == '0')
		return false;
	if(x[2] == '0' && x[2] == x[3])
		return false;
	return true;
}
void Solve(){
	for(int i = 1; i <= n; i ++ ){
		if(a[i] == 0) s[i - 1] = '0';
		else s[i - 1] = '2';
	}
	if(check(s)){
		string m = s;
		m.insert(2, "/");
		m.insert(5, "/");
		res.push_back(m);
		m.clear();
	}
	
}
void Try(int i){
	for(int j = 0; j <= 1; j ++){
		a[i] = j;
		if(i == n){
			Solve();
		}
		else Try(i + 1);
	}
}

int main(){
	init();
	Try(1);
	sort(res.begin(), res.end());
	for(auto x: res)
		cout << x << endl;
}
