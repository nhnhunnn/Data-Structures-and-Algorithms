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
// Date: 09/02/22 21:45
// Program: Day con tang dan bac K
// -------------------  Your code STARTS here !!!---------------------------

int n, k, a[100];
int b[100];
int cnt = 0; 

void init(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	b[0] = 0; 
} 

bool check(){
	for(int i = 2; i <= k; i++)
		if(a[b[i]] < a[b[i - 1]]) 
			return false; 
	return true; 
} 

void Try(int i){
	for(int j = b[i - 1] + 1; j <= n - k + i; j++){
		b[i] = j;
		if(i == k){
			 if(check()) 
			 	cnt++; 
		}
		else Try(i + 1);
	} 
} 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	Try(1);
	cout << cnt << endl;
	return 0;
}
