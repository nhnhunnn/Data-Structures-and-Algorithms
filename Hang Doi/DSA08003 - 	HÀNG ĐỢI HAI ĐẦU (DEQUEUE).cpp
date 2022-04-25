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
// Program: Hang doi 2 dau
// -------------------  Your code STARTS here !!!---------------------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

 	int t; cin >> t;
    deque<int> dq;
    string s;
    int n;
	while(t--){
		cin >> s;
        if(s == "PUSHFRONT"){
            cin >> n;
            dq.push_front(n);
        }
        else if(s == "PRINTFRONT"){
            if(!dq.empty()) cout << dq.front() << endl;
            else cout << "NONE" << endl;
        }
        else if(s == "POPFRONT"){
            if(!dq.empty()) dq.pop_front();
        }
        else if(s == "PUSHBACK") {
            cin >> n;
            dq.push_back(n);
        }
        else if(s == "PRINTBACK"){
            if(!dq.empty()) cout << dq.back() << endl;
            else cout << "NONE" << endl;
        }
        else if(s == "POPBACK"){
            if(!dq.empty()) dq.pop_back();
        }
	}
	return 0;
}
