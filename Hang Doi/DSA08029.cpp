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
// Date: 15/03/22 23:45
// Program: Quay hinh vuong
// -------------------  Your code STARTS here !!!---------------------------

int dl[] = {1, 5, 2, 4, 6, 3};
int dr[] = {4, 1, 3, 5, 2, 6};
string Drt(string s, int a[], int n){
    string res = "";
    for(int i = 0; i < n; ++i) res += s[a[i] - 1];
    return res;
}


void BFS(string s, string t){
    map<string, int> mp;
    mp.clear();
    queue<string> q;
    q.push(s);
    mp[s] = 1;
    while(!q.empty()){
        string c = q.front(); q.pop();
        if(c == t){
            cout << mp[c] - 1 << endl;
            return;
        }

        string a = Drt(c, dl, 6);
        if(mp[a] == 0){
            q.push(a);
            mp[a] = mp[c] + 1;
        }

        string b = DrtR(c, dr, 6);
        if(mp[b] == 0){
            q.push(b);
            mp[b] = mp[c] + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        string s = "", t = "";
        for(int i = 0; i < 6; ++i){ char x; cin >> x; s += x;}
        for(int i = 0; i < 6; ++i){ char x; cin >> x; t += x;}
        BFS(s, t);
    }
    return 0;
} 