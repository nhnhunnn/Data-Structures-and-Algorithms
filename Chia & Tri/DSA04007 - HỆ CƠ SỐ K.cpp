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
// Date: 21/02/22 18:03
// Program: He co so K
// -------------------  Your code STARTS here !!!---------------------------

string Summation(string a, string b, int k){
	string res = "";
	int tmp = 0;
	while(a.size() < b.size()) 
		a= "0" + a;
	while(a.size() > b.size()) 
		b= "0" + b;
	int len = a.size() - 1;
	for(int i = len; i >= 0; i--){
		
		int number = int(a[i] - '0') + int(b[i] - '0') + tmp;
		res = char(number % k + '0') + res;
		tmp = number / k;
	
	}
	if(tmp > 0) 
		res = char(tmp + '0') + res;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
    	int k; cin >> k;
    	string a, b; cin >> a >> b;
    	cout << Summation(a, b, k) << endl;
	}
	return 0;
}
