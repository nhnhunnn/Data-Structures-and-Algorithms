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
// Date: 09/02/22 19:00
// Program: Xau nhi phan ke tiep
// -------------------  Your code STARTS here !!!---------------------------

int n, k, a[100], b[100];
int cnt = 0; 

void init(){
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	memset(b, 0, sizeof(b));
}

void output(){
	for(int i = 1; i <= n; i ++)
		if(b[i] != 0) 
			cout << a[i] << " "; 
	cout << endl; 
} 

void Try(int i){
	for(int j = 0;j <= 1; j ++){
		b[i] = j;
		if(i == n){
			int sum = 0;
			for(int l = 1; l <= n; l ++)
				sum += a[l] * b[l]; 
				
			if(sum == k) {
				cnt++;
				output(); 
			} 
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
