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
// Date: 04/03/22 08:45
// Program: Bien Doi S - T
// -------------------  Your code STARTS here !!!---------------------------

int Cnt_Change(int s, int t){
    int a[10000];
    for(int i = 0; i < 10000; i ++) a[i] = INT_MAX;
    queue<int> q;
    q.push(s);
    a[s] = 0;
    while(!q.empty()){
        int i = q.front();
        q.pop();
        if(a[t] != INT_MAX) 
            break;
        if(i - 1 > 0 && a[i - 1] == INT_MAX){
            a[i - 1] = min(a[i - 1], a[i] + 1);
            q.push(i - 1);
        }
        if(i * 2 < 10000 && a[i * 2] == INT_MAX){
            a[i * 2] = min(a[i * 2], a[i] + 1);
            q.push(i * 2);
        }
    }
    return a[t];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int s, t; cin >> s >> t;
        cout << Cnt_Change(s, t) << endl;
    }
    return 0;
}
