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
// Program: Khoang cach xau ky tu
// -------------------  Your code STARTS here !!!---------------------------

void BFS(string s, string t, int n){
    unordered_set<string> us;
    unordered_map<string, int> ump;
    for(int i = 0; i < n; i ++){
        string a; cin >> a; us.insert(a);
        ump[a] = 0;
    }
    queue<string> q;
    q.push(s);
    ump[s] = 1;
    while(!q.empty()){
        string a = q.front(); q.pop();
        if(a == t){
            cout << ump[t] << endl;
            return;
        }
        for(int i = 0; i < a.size(); ++i){
            string b = a;
            for(char x = 'A'; x <= 'Z'; ++x){
                b[i] = x;
                if(us.find(b) != us.end() && ump[b] == 0){
                    ump[b] = ump[a] + 1;
                    q.push(b);
                }
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
        int n; cin >> n;
        string s, t; cin >> s >> t;
        BFS(s, t, n);
    }
    return 0;
} 
