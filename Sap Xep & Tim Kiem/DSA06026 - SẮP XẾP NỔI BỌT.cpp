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
// Date: 08/02/22 16:26
// Program: Sap xep noi bot
// -------------------  Your code STARTS here !!!---------------------------

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<int> a;
	int b, c = 0;
	for(int i = 0; i < n; i ++){
		int x; cin >> x;
		a.push_back(x);
	}
	for(int i = n - 1; i > 0; i --){
		int max = a[i];
		b = 0;
		for(int j = i - 1; j >= 0; j --){
			if(a[j] > max){
				max = a[j];
				b ++;
			}
		}
		if(b == 0)
			continue;
		for(int j = 0; j < n - 1; j ++){
			if(a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
		cout << "Buoc " << c + 1 << ": ";
		for(int j = 0; j < n; j ++)
			cout << a[j] << " ";
		cout << endl;
		c++;
	}
	return 0;
}
