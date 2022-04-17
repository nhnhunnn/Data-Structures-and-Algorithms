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
// Date: 23/03/22 01:30
// Program: Xoa dau ngoac
// -------------------  Your code STARTS here !!!---------------------------

string s;
int a[25], b[25], x[25], cnt_cl, cnt_op;
int c[25], len;
bool vs[205];
set<string> res;

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        c[i] = j;
        if (i == cnt_cl){
            for (int i = 0; i < len; i++) vs[i] = true;    
            for (int i = 1; i <= cnt_cl; i++) {
                if (!c[i]) {
                    vs[a[i]] = false;
                    vs[b[i]] = false;
                }
            }
            string tp = "";
            for (int i = 0; i < len; i++)
                if (vs[i]) tp += s[i];
            if(tp != s) res.insert(tp);
        }    
        else Try(i + 1);
    }
}
int main() {
    cin >> s;
    cnt_op = 0, cnt_cl = 0;
    len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            cnt_op++;
            x[cnt_op] = i;
        }
        else if (s[i] == ')') {
            cnt_cl++;
            a[cnt_cl] = x[cnt_op];
            b[cnt_cl] = i;
            cnt_op--;
        }
    }
    Try(1);
    for(auto x: res) cout << x << endl;
    return 0;
}