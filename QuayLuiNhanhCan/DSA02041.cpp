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
// Date: 15/02/22 20:10
// Program: Bien doi ve 1
// -------------------  Your code STARTS here !!!---------------------------

int n;
vector<bool> visited;
pair<int, int> x;

void Try(){
    cin >> n;
    visited.clear();
    visited.resize(n + 5, false);
    visited[n] = true;
    queue<pair<int, int> > q;
    q.push ({n, 0});
    while (!q.empty()){
        x = q.front(); 
        q.pop();
        if (x.f == 1){
            cout << x.s << endl;
            return;
        }
        if (x.f % 3 == 0 && !visited[x.f / 3]){
            visited[x.f / 3] = true;
            q.push({x.f / 3, x.s + 1});
        }
        if (x.f % 2 == 0 && !visited[x.f / 2]){
            visited[x.f / 2] = true;
            q.push({x.f / 2, x.s + 1});
        }
        if (!visited[x.f - 1]){
            visited[x.f - 1] = true;
            q.push({x.f - 1, x.s + 1});
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t --){
        Try();
    }
    return 0;
}