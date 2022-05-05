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
// Date: 07/03/22 10:30
// Program: Duyet cay 1
// -------------------  Your code STARTS here !!!---------------------------

int pos = 0;
inline void Print(int inorder[], int preorder[], 
    int l, int r, unordered_map<int, int> &mp){
    if(l <= r){
        int index = mp[preorder[pos++]];
        Print(inorder, preorder, l, index - 1, mp);
        Print(inorder, preorder, index + 1, r, mp);
        cout << inorder[index] << " ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int inorder[n], preorder[n];
        for(auto &x: inorder) cin >> x;
        for(auto &x: preorder) cin >> x;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) mp[inorder[i]] = i;
        pos = 0;
        Print(inorder, preorder, 0, n - 1, mp);
        cout << endl;
    }
    return 0;
}
