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
// Date: 18/02/22 14:51
// Program: Bieu thuc toan hoc
// -------------------  Your code STARTS here !!!---------------------------

int num[10], res;
bool visited[100];

void Try(int i, int x){
    if(res) return;
    if(i == 5 && x == 23){
        res = 1;
        return;
    }
    for(int j = 0; j < 5; ++j){
        if(!visited[j]){
            visited[j] = true;
            Try(i + 1, x + num[j]);
            Try(i + 1, x - num[j]);
            Try(i + 1, x * num[j]);
            visited[j] = false;
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	int t; cin >> t;
	while(t--){
	    memset(visited, false, sizeof(visited));
		for(int i = 0; i < 5; i ++) cin >> num[i];
		res = 0;
		for(int i = 0; i < 5; i ++){
		    visited[i] = true;
		    Try(1, num[i]);
		    visited[i] = false;
		}
		if(res) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}
