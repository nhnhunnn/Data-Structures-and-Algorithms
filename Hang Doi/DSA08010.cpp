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
// Date: 15/03/22 13:30
// Program: Bien doi so tu nhien
// -------------------  Your code STARTS here !!!---------------------------

void BFS(int n){
    set<int> vs;
    queue<pair<int ,int> > q;
    q.push({n, 0});
    vs.insert(n);
    while(!q.empty()){
        pair<int, int > a = q.front(); q.pop();
        if(a.f == 1){
            cout << a.s << endl;
            return;
        }
        if(a.f == 2){
            cout << a.s + 1 << endl;
            return;
        }
        for(int i = sqrt(a.f); i >= 2; --i){
            if(a.f % i == 0){
                if(vs.find(a.f / i) == vs.end()){
                    q.push({a.f / i, a.s + 1});
                    vs.insert(a.f / i);
                }
            }
        }
        if(vs.find(a.f - 1) == vs.end()){
            q.push({a.f - 1, a.s + 1});
            vs.insert(a.f - 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        BFS(n);
    }
    return 0;
}