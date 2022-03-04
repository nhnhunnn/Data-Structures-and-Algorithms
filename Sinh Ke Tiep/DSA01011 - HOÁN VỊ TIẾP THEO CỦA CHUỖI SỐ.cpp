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
// Date: 06/02/22 11:56
// Program: Hoan vi tiep theo cua chuoi so
// -------------------  Your code STARTS here !!!---------------------------

int n, test;
int a[1000];
bool mark;
string s = "";

void init(){
	mark = false;
	cin >> test;
	cin >> s;
	n = s.length();
	for(int i = 1; i <= n; i ++)
		a[i] = s[i - 1] - '0';
} 

void next(){
	int j = n - 1;
	while(j > 0 && a[j] >= a[j + 1])
		j--; 
	if(j > 0){
		mark = false;
		int k = n;
		while(a[j] >= a[k]){
			k --; 
		}
		swap(a[j], a[k]);
		int r = j + 1; 
		int s = n; 
		while(r <= s){
			swap(a[r], a[s]);
			r ++;
			s --; 
		} 
	}
	else
		mark = true;
}

void output(){
	for(int i = 1; i <= n; i ++) cout << a[i];
	cout << endl;
}

int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){ 
		init(); 
		next();
		cout << test << " ";
		if(mark) cout << "BIGGEST" << endl;
		else output();	
	}
	return 0; 
}
