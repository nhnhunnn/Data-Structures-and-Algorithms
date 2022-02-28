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
// Date: 09/02/22 12:21
// Program: Cap so co tong bang K - ep thoi gian
// -------------------  Your code STARTS here !!!---------------------------

bool Binary_Search(vector<int> a, int l, int r, int x){
    while(l <= r){
        int m = (l + r)/2;
        if(a[m] == x) 
            return true;
        if(a[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		long n, k; cin >> n >> k;
	    unordered_map <long, long> fre;
	    vector<long> a(n);
	    for (long i = 0; i < n; i++){
	        cin >> a[i];
	        fre[a[i]]++;
	    }
	    long cnt = 0;
	    for (long i = 0; i < n; i++){
	        if (a[i] == k - a[i])
	            cnt += (fre[a[i]] - 1);
	        else
	            cnt += (fre[k - a[i]]);
		}
	 	cnt /= 2;
	    cout << cnt << endl;
	}
	return 0;
}

