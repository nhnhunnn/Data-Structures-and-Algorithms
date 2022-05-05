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
// Program: Duyet cay 2
// -------------------  Your code STARTS here !!!---------------------------

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *tree;

int Search(int a[], int n, int x){
    for(int i = 0; i < n; ++i) 
        if(a[i] == x) 
            return i;
    return -1;
}

tree MakeRoot(int value){
    tree p = new node();
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void MakeTree(tree &root, int *a, int *b, int n){
    root = MakeRoot(b[0]);
    int x = Search(a, n, b[0]);
    int l = 0, r = 0;
    int L[10005], R[10005];
    for(int i = 1; i < n; ++i){
        if(Search(a, n, b[i]) < x) 
            L[l++] = b[i];
        else 
            R[r++] = b[i];
    }
    if(x > 0) MakeTree(root->left, a, L, x);
    if(n - 1 - x > 0) MakeTree(root->right, a + x + 1, R, n - 1 - x);
}

void showPostOrder(tree root){
    if(root->left) showPostOrder(root->left);
    if(root->right) showPostOrder(root->right);
    cout << root->data << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        tree root = NULL;
        int a[n], b[n];
        for(auto &x: a) cin >> x;
        for(auto &y: b) cin >> y;
        MakeTree(root, a, b, n);
        showPostOrder(root);
        cout << endl;
    }
    return 0;
}