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
// Date: 14/02/22 20:29
// Program: So nho nhat co N uoc so
// -------------------  Your code STARTS here !!!---------------------------

vector<int> eratosthenes_sieve(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = true;
    for(ll i = 2; i * i <= limit; ++i)
        if(is_prime[i])
            for (ll j = i * i; j <= limit; j += i) is_prime[j] = false;
    vector<int> prime;
    for(ll i = 2; i <= limit; ++i)
        if(is_prime[i]) 
            prime.push_back(i);
    return prime;
}

const vector<int> prime = eratosthenes_sieve(31);

int n, cnt;
ll res;

void init(){
    cin >> n;
    res = (ll) 1e18;
}

void Try(int i, ll b, int cnt){
    if(cnt > n) return;
    if(cnt == n){
        res = min(res, b);
        return;
    }
    for(int j = 1; ; j++){
        if(b * prime[i] > res)
            break;
        b = b * prime[i];
        Try(i + 1, b, cnt * (j + 1));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while(t--){
        init();
        Try(0, 1, 1);
        cout << res << endl;
    }
    return 0;
}
