#include <bits/stdc++.h>
// CODEFORCES
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pt;
 
template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
 
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;
 
ll n, k;
 
inline bool read() {
    return !!(cin >> n >> k);
}
 
const int mod = 1000 * 1000 * 1000 + 7;
 
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (!a) {
        x = 0, y = 1;
        return b;
    }
    ll xx, yy, g = gcd(b % a, a, xx, yy);
    x = yy - b / a * xx;
    y = xx;
    return g;
}
 
inline ll normal(ll n) {
    n %= mod;
    (n < 0) && (n += mod);
    return n;
}
 
inline ll inv(int a) {
    ll x, y;
    assert(gcd(a, mod, x, y) == 1);
    return normal(x);
}
 
inline ll add(ll a, ll b) { return a + b >= mod ? a + b - mod : a + b; }
inline ll sub(ll a, ll b) { return a - b < 0 ? a - b + mod : a - b; }
inline ll mul(ll a, ll b) { return int(a * 1ll * b % mod); }
inline ll _div(ll a, ll b) { return mul(a, inv(b)); }
 
inline ll binPow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}
 
ll calc(const vector<ll>& y, ll x) {
    ll ans = 0;
    ll k = 1;
    fore(j, 1, sz(y)) {
        k = mul(k, normal(x - j));
        k = _div(k, normal(0 - j));
    }
    forn(i, sz(y)) {
        ans = add(ans, mul(y[i], k));
        if (i + 1 >= sz(y)) break;
        k = mul(k, _div(normal(x - i), normal(x - (i + 1))));
        k = mul(k, _div(normal(i - (sz(y) - 1)), normal(i + 1)));
    }
    return ans;
}
 
inline ll solve() {
    vector<ll> y;
    ll sum = 0;
    y.pb(sum);
    forn(i, k + 1) {
        sum = add(sum, binPow(i + 1, k));
        y.pb(sum);
    }
    if (n < sz(y)) return y[n];
    return calc(y, n);
}
 
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << solve() << endl;
    }
    
    return 0;
}
