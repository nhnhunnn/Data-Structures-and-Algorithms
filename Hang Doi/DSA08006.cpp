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
// Date: 08/04/22 15:45
// Program: So 0 va 9
// -------------------  Your code STARTS here !!!---------------------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<string> q;
    vector<string> v;
    q.push("9");
    v.push_back("9");
    while(v.size() <= 10000){
        string s = q.front();
        q.pop();
        q.push(s + "0");
        v.push_back(s + "0");
        q.push(s + "9");
        v.push_back(s + "9");
    }
 	int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 0; i < v.size(); ++i){
            if(stoll(v[i]) % n == 0){
                cout << stoll(v[i]) << endl;
                break;
            }
        }
    }
    return 0;
}