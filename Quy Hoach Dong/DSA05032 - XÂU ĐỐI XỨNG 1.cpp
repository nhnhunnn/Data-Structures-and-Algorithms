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
// Date: 11/03/22 09:00
// Program: Xau doi xung 1
// -------------------  Your code STARTS here !!!---------------------------

ll f[42][42];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        string a = s;
        reverse(a.begin(), a.end());
        int n = s.length();
        memset(f, 0, sizeof(f));
        for(int i = 0; i <= n; i ++) f[i][i] = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; j ++){
                if(s[i - 1] == a[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else 
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        cout << n - f[n][n] << endl;



        // string s; cin >> s;
        // memset(f, 0, sizeof(f));
        // int n = s.length();
        // for (int i = 0; i < n; i++) f[i][i] = 1;
        // for (int i = s.size() - 2; i >= 0; i--) {
        //     for (int j = i + 1; j < s.size(); j++) {
        //         if (s[i] == s[j]) 
        //             f[i][j] = f[i + 1][j - 1] + 2;
        //         else
        //             f[i][j] = max(f[i + 1][j], f[i][j - 1]);
        //     }
        // }
        // cout << n - f[0][s.size() - 1];
    }
    return 0;
}
