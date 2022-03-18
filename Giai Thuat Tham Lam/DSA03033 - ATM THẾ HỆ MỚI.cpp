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
// Date: 14/03/22 21:56
// Program: ATM the he moi
// -------------------  Your code STARTS here !!!---------------------------

ll power(ll a, ll b){
	if (b == 0) return 1;
	if (b == 1) return a;
	ll x = power(a, b / 2);
	return (b & 1) ?  x * x * a : x * x;
}	

void Solution(ll a, ll c){
	ll cash = 0;
	ll total = 1;
	while (c-- && a)
	{
		if (a % 10 == 1 || a % 10 == 2 || a % 10 == 3 || a % 10 == 5)
		{
			cash++;
		}
		else if (a % 10 == 4 || a % 10 == 6)
		{
			cash += 2;
			total *= 2;
		}
		else if (a % 10 == 7)
		{
			cash += 2;
		}
		else if (a % 10 == 8)
		{
			cash += 2;
		}
		else if (a % 10 == 9)
		{
			cash += 3;
			total *= 3;
		}
		a /= 10;
	}
	if (a)
	{
		ll x = a;
		cash += x / 5;
		ll x1 = x % 5;
		if (x1 == 4) cash += 2;
		else if (x1 == 0) cash += 0;
		else cash++;
		if (x1 == 1 && x > 1 || x == 4) total *= 2;
		if (x1 == 4 && x > 4) total *= 3;
	}
	cout << cash << ' ' << total << endl;
}

void Proceed(ll a, ll c)
{
	if (a % 1000)
	{
		cout << 0 << endl;
		return;
	}
	a /= 1000;
	Solution(a, c);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		ll a;
		cin >> a;
		ll c;
		cin >> c;
		Proceed(a, c);
	}
	return 0;
}
