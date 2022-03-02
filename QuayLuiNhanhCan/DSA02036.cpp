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
// Date: 20/02/22 14:20
// Program: Day con co tong le?
// -------------------  Your code STARTS here !!!---------------------------

int n, k, a[20], c[20];
vector<vector<int> > res;

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    memset(c, 0, sizeof(c));
    res.clear();
}

void Try(int i){
    for(int j = 0; j <= 1; j ++){
        c[i] = j;
        if(i == n){
            int sum = 0;
            vector<int> t;
            for(int i = 1; i <= n; i ++){
                if(c[i] == 1) {
                    t.push_back(a[i]);
                    sum += a[i];
                }
            }
            if(sum % 2 == 1)
                res.push_back(t);
        }
        else Try(i + 1);
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
        for(auto x: res){
            for(auto y: x)
                cout << y << " ";
            cout << endl;
        }
    }
    return 0;
}
