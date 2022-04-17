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
// Date: 07/03/22 14:40
// Program: So Loc phat 1
// -------------------  Your code STARTS here !!!---------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        queue<string> q;
        vector<string> v; 
        q.push("6");
        q.push("8");
        v.push_back("6");
        v.push_back("8");
        for(int i = 2; i <= n; i ++){
            for(int j = 1; j <= pow(2, i - 1); j ++){
                string top = q.front();
                q.pop();
                q.push(top + "6");
                q.push(top + "8");
                v.push_back(top + "6");
                v.push_back(top + "8"); 
            } 
        }
        //cout << v.size() << endl;
        reverse(v.begin(), v.end());
        for(auto x: v) cout << x << " ";
        cout << endl; 
    }
    return 0;
}