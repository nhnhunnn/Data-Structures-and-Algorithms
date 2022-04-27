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
// Date:
// Program: 
// -------------------  Your code STARTS here !!!---------------------------
bool check(string s){
    int n = s.length();
    int cnt = 0;
    for(int i = 0; i < n; ++i) if(s[i] == '2') ++cnt;
    return (cnt > n / 2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	cout.tie(NULL);
	
    
    int t; cin >> t;
    while (t--) {
    	int n; cin >> n;
        queue<string> q;
        q.push("1");
        q.push("2");
        int cnt = 0;
        while(cnt < n){
            string s = q.front();
            q.pop();
            if(check(s)) {
                cout << s << " ";
                ++cnt;
            }
            q.push(s + "0");
            q.push(s + "1");
            q.push(s + "2");
        }
        cout << endl;
    }
    return 0;
}
