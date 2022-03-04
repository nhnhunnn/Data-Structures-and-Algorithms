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
// Date:
// Program:
// -------------------  Your code STARTS here !!!---------------------------

vector<int> eratosthenes_sieve(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = true;
    for(ll i = 2; i * i <= limit; ++i)
        if(is_prime[i])
            for (ll j = i * i; j <= limit; j += i) is_prime[j] = false;
    vector<int> prime;
    for(ll i = 2; i <= limit; ++i)
        if(is_prime[i]) prime.push_back(i);
    return prime;
}

vector<int> prime = eratosthenes_sieve(1000);

int n, P, S, k;
int a[100], c[100];
bool visited[100];
vector<int> b;
vt res;

void init(){
	cin >> k >> P >> S;
	b.clear();
	res.clear();
	ms(c, 0);
	ms(visited, false);
		
	auto x = upper_bound(prime.begin(), prime.end(), P);
	int index = distance(prime.begin(), x);
	
	for(int i = index; i < prime.size(); i ++){
		if(prime[i] < S)
			b.push_back(prime[i]);
	}
	n = b.size();
}

void Solve(){
	int sum = 0;
	vector<int> t;
	for(int i = 1; i <= k; i ++){
		sum += b[c[i] - 1];
		t.push_back(b[c[i] - 1]);
	}
	if(sum == S)
		res.push_back(t);
}

void Try(int i){
	for(int j = c[i - 1] + 1; j <= n - k + i; j ++){
		c[i] = j;
		if(i == k) Solve();
		else Try(i + 1);
	}
}

void output(){
	cout << res.size() << endl;
	for(auto x: res){
		for(auto y: x) 
			cout << y << " ";
		cout << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		init();
		Try(1);
		output();
	}
	return 0;
}

