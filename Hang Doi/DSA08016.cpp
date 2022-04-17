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
// Date: 18/03/22 12:40
// Program: Hexgame
// -------------------  Your code STARTS here !!!---------------------------

int dlx[] = {4, 1, 3, 8, 5, 2, 7, 9, 6, 10};
int drx[] = {1, 5, 2, 4, 9, 6, 3, 8, 10, 7};

int dln[] = {2, 6, 3, 1, 5, 9, 7, 4, 8, 10};
int drn[] = {1, 3, 7, 4, 2, 6, 10, 8, 5, 9};

string Drt(string s, int b[], int n){
    string res = "";
    for(int i = 0; i < n; i ++) res += s[b[i] - 1];
    return res;
}
map<string, int> v, u;
void BFS(string s){
    v.clear();
    queue<string> q;
    q.push(s);
    v[s] = 1;
    while(!q.empty()){
        string c = q.front(); q.pop();
        string a = Drt(c, dln, 10);
        if(v[a] == 0){
            q.push(a);
            v[a] = v[c] + 1;
        }

        string b = Drt(c, drn , 10);
        if(v[b] == 0){
            q.push(b);
            v[b] = v[c] + 1;
        }
        if(v[q.back()] >= 15) break;
    }
}

void BFS2(string s){
    u.clear();
    queue<string> q;
    q.push(s);
    u[s] = 1;
    while(!q.empty()){
        string c = q.front(); q.pop();
        if(v[c]){
            cout << u[c] + v[c] - 2 << endl;
            return;
        }
        string a = Drt(c, dlx, 10);
        if(u[a] == 0){
            q.push(a);
            u[a] = u[c] + 1;
        }

        string b = Drt(c, drx, 10);
        if(u[b] == 0){
            q.push(b);
            u[b] = u[c] + 1;
        }
        if(u[q.back()] >= 15) break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        string s = "";
        BFS("1238004765");
        for(int i = 0; i < 10; i ++) { char x; cin >> x; s += x; }
        BFS2(s);
    }
    return 0;
}