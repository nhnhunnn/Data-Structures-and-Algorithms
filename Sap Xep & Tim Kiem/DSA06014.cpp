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
// Date: 05/02/22 21:37
// Program:
// -------------------  Your code STARTS here !!!---------------------------

vector<bool> eratosthenes_sieve_with_bool(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = true;
    for(ll i = 2; i * i <= limit; ++i)
        if(is_prime[i])
            for (ll j = i * i; j <= limit; j += i) is_prime[j] = false;
    return is_prime;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);              
    cout.tie(0);
    
	vector<bool> N = eratosthenes_sieve_with_bool(1000005);
	
	int t; cin >> t;
	while(t--){
		ll a; cin >> a;
		bool mark = 0;
		for(ll i = 2; i <= a/2; i ++){
			if(N[i] && N[a - i]){
				cout << i << " " << a - i;
				mark = true;
				break;
			}
		}
		if(!mark) cout << -1;
		cout << endl;
	}
	return 0;
}
