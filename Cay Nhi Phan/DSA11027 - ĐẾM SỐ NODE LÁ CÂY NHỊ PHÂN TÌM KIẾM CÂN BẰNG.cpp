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
// Program: Dem so node la cua cay nhi phan tim kiem can bang
// -------------------  Your code STARTS here !!!---------------------------

typedef struct node{
    int data;
    node *left;
    node *right;
} *tree;

bool isLeft(tree root, int value){
    return value < root->data;
}
bool isRight(tree root, int value){
    return value > root->data;
}

tree Insert(tree root, int value){
    if(root == NULL){
        root = new node();
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(isLeft(root, value)){
        root->left = Insert(root->left, value);
    }
    else if(isRight(root, value)){
        root->right = Insert(root->right, value);
    }
    return root;
}

void MakeTree(tree &root, int l, int r, vector<int> v){
    if(l >= r) return;
    int m = (l + r) >> 1;
    root = Insert(root, v[m]);
    MakeTree(root, l, m, v);
    MakeTree(root, m + 1, r, v);
}

ll res = 0;
void countLeaf(tree root){
    if(root->left == NULL && root->right == NULL) 
        ++res;
    if(root->left) 
        countLeaf(root->left);
    if(root->right) 
        countLeaf(root->right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        tree root = NULL;
        int n; cin >> n;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        sort(a.begin(), a.end(), greater<int>());
        MakeTree(root, 0, n, a);
        res = 0;
        countLeaf(root);
        cout << res << endl;
    }
    return 0;
}
