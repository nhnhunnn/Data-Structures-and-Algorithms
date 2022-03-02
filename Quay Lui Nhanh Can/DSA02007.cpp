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
// Date: 13/02/22 20:43
// Program: Doi cho cac chu so
// -------------------  Your code STARTS here !!!---------------------------

void Try(string s, int k, string &mx){
    if(k == 0)
        return;
    for(int i = 0; i < s.size() - 1; i ++){
        for(int j = s.size() - 1; j > i; j --){
            if(s[i] < s[j]){
                swap(s[i], s[j]);
                mx = max(mx, s);
                Try(s, k - 1, mx);
                swap(s[j], s[i]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        string s; cin >> s;
        string mx = s;
        Try(s, k, mx);
        cout << mx << endl;
    }
    return 0;
}
