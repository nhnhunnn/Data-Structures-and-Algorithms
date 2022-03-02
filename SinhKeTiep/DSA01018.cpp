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
// Date: 09/02/22 18:27
// Program: Tap con lien ke phia truoc
// -------------------  Your code STARTS here !!!---------------------------

int n, k;
int a[1000];
void init(){
	cin >> n >> k;
	for(int i = 1; i <= k; i++)
		cin >> a[i];
} 
void before(){
	int i = k - 1;
	while(i >= 1 && a[i] == a[i + 1] - 1)
		i --;
	if(i == 0 && a[1] == 1){
		for(int j = 1; j <= k; j ++)
			a[j] = n - k + j;
	}	
	else{
		a[1 + i] -= 1;
		for(int j = i + 2; j <= k; j ++)
			a[j] = n - k + j;
	} 

} 
void output(){
	for(int i = 1; i <= k; i ++)
		cout << a[i] << " ";
	cout << endl;
}
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){ 
		init();
		before();	
		output();	
	}
	return 0; 
}

