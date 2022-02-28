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
// Date: 09/02/22 21:17
// Program: Bo ba co tong = K
// -------------------  Your code STARTS here !!!---------------------------

int n, k, a[10005];
void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    
}
bool Binary_Search(int a[10005], int l, int r, int x) {
    if (l > r) 
		return false;
    int m = (l + r) / 2;
    if (a[m] == x) 
		return true;
    if (a[m] > x) 
		return Binary_Search(a, l, m - 1, x);
    return Binary_Search(a, m + 1, r, x);
}
void Solve() {
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Binary_Search(a, j + 1, n - 1, k - a[i] - a[j])) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t; cin >> t;
	while(t--){
		input();
		Solve();
	}
	return 0;
}
