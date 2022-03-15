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
// Date: 11/03/22 16:12
// Program: So man man
// -------------------  Your code STARTS here !!!---------------------------

void Solve(int n) {
    vector<int> a;
    while(n >= 4){
        if(n % 7 == 0){
            a.push_back(7);
            n -= 7;
            continue;
        }
        if(n >= 4){
            a.push_back(4);
            n -= 4;
            continue;
        }
    }
    if(n != 0) cout << -1 << endl;
    else {
        for(auto x: a) cout << x;
        cout << endl;
    }
    // int x = n / 7;
    // n %= 7;
    // while(n % 4 != 0 && n <= 28){
    //     n += 7;
    //     x--;
    // }
    // if(n % 4 != 0 || x < 0){
    //     cout << "-1";
    //     return;
    // }
    // n /= 4;
    // for(int i = 0; i < n; ++i) cout << "4";
    // for(int i = 0; i < x; ++i) cout << "7";
    // cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        Solve(n);
    }
    return 0;
}