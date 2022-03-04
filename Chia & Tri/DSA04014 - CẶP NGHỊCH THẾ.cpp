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
// Date: 21/02/22 11:01
// Program: Cap nghich the
// -------------------  Your code STARTS here !!!---------------------------

ll merge(ll a[], int l, int m, int r){
    vector<ll> x(a + l, a + m + 1);
    vector<ll> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    ll cnt = 0;
    while(i < x.size() && j < y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i];
            ++ l;
            ++ i;
        }
        else{
            cnt += x.size() - i;
            a[l] = y[j];
            ++ l;
            ++ j;
        }
    }
    while(i < x.size()){
        a[l] = x[i];
        ++ l;
        ++ i;
    }
    while(j < y.size()){
        a[l] = y[j];
        ++ l;
        ++ j;
    }
    return cnt;
}

ll merge_Sort(ll a[], int l, int r){
    ll cnt = 0;
    if(l < r){
        int m = (l + r) / 2;
        cnt += merge_Sort(a, l, m);
        cnt += merge_Sort(a, m + 1, r);
        cnt += merge(a, l, m, r);
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
	    ll a[n + 5];
	    for(int i = 0; i < n; i ++) cin >> a[i];
	    cout << merge_Sort(a, 0, n - 1)<< endl;
	}
    return 0;
}
