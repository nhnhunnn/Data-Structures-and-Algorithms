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
// Date: 22/02/22 17:15
// Program: Chia Mang
// -------------------  Your code STARTS here !!!---------------------------


int n, k, a[25];
int res, sum;
bool visited[100], mark;
void init(){
    cin >> n >> k;
    sum = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    memset(visited, false, sizeof(visited));
    mark = false;
}

void Try(int cnt, int S, int sum){
    if(mark) return;
    if(cnt == k){
        mark = true;
        return;
    }
    for(int i = 1; i <= n; i ++){
        if(!visited[i]){
            visited[i] = true;
            if(S < sum / k) 
                Try(cnt + 1, S + a[i], sum);
            else if(S == sum / k)
                Try(cnt, 0, sum);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        init();
        if(sum % k != 0) cout << 0;
        else{
            Try(0, 0, sum);
            if(mark) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    return 0;
}
