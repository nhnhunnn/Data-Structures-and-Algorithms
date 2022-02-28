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
// Date: 08/02/2022 9:49
// Program: Sap xep theo so lan xuat hien
// -------------------  Your code STARTS here !!!---------------------------

struct dta{
    int value, key;
};

bool cmp(dta a, dta b){
    if(a.key == b.key) 
        return a.value < b.value;
    return a.key > b.key;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[10005] = {};
        dta arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i].value;
            a[arr[i].value] ++;
        }
        for(int i = 0; i < n; i++)
            arr[i].key = a[arr[i].value];
        sort(arr, arr + n, cmp);
        for(int i = 0; i < n; i++)
            cout << arr[i].value << " ";
        
        cout << endl;
    }
    return 0;
}