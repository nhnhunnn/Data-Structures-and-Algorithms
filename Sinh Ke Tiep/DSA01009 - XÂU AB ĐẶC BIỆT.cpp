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
// Date: 09/02/22 22:18
// Program: Xau AB dac biet
// -------------------  Your code STARTS here !!!---------------------------

// m bit 1 lien tiep
int n, k , a[100] = {};
bool ok = false;
vector<string> res;
bool check(vector<int> &a, int n, int m){
    int mark = 0;
    for(int i = 0; i < n; i ++){
        int cnt = 0;
        if(a[i] == 1){
            for(int j = i; j < m + i && j < n; j ++)
                if(a[i] == a[j]) cnt ++;
        }
        if(cnt == m) mark ++;
    }
    if(mark == 1) 
        return true;
    return false;
}

void outp(){
    vector<int> c;
    for(int i = 1; i <= n; i ++) c.push_back(a[i]);
    if(check(c, n, k)){
        string tmp = "";
        for(int j = 0; j < n; j ++){
            if(c[j] == 1) tmp = tmp + "A";
            else tmp = tmp + "B";
        }
        res.push_back(tmp);
    }
}

void next(){
    int i = n;
    while(a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) ok = true;
    else a[i] = 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> n >> k;
    while(!ok){
        outp();
        next();    
    }
    sort(res.begin(), res.end());
    int len = res.size();
    cout << len << endl;
    for(int i = 0; i < len; i ++){
        int x = res[i].size();
        for(int j = 0; j < x; j ++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
