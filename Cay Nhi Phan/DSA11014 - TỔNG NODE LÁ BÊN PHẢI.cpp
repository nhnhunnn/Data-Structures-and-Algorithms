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
// Program: Tong Node la ben phai
// -------------------  Your code STARTS here !!!---------------------------

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *tree;

tree MakeRoot(int value){
    tree p = new node();
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void addTree(tree &t, int u, int v, char c){
    if(!t){
        t = MakeRoot(u);
        if(c == 'L') t->left = MakeRoot(v);
        else t->right = MakeRoot(v);
    }
    else{
        if(t->data == u){
            if(c == 'L') t->left = MakeRoot(v);
            else t->right = MakeRoot(v);
        }
        else{
            if(t->left) addTree(t->left, u, v, c);
            if(t->right) addTree(t->right, u, v, c);
        }
    }
}
tree MakeTree(int n){
    map <int, tree> mp;
    tree root = NULL;
    while(n--){
        int a, b; char c;
        cin >> a >> b >> c;
        tree parent = NULL;
        if(mp.find(a) == mp.end()){
            parent = MakeRoot(a);
            mp[a] = parent;
            if(root == NULL) root = parent;
        }
        else parent = mp[a];
        tree child = MakeRoot(b);
        if(c == 'L') parent->left = child;
        else if(c == 'R') parent->right = child;
        mp[b] = child;
    }
    return root;
}
int Sum_LeafRight(tree t){
    if(t == NULL) 
        return 0;
    queue <pair<tree, int> > q;
    q.push({t, 0});
    int res = 0;
    while(!q.empty()){
        pair<tree, int> tmp = q.front(); q.pop();
        tree cur = tmp.f;
        if(cur->left == NULL && cur->right == NULL){
            if(tmp.s == 2)
                res += cur->data;
        }
        if(cur->left) q.push({cur->left, 1});
        if(cur->right) q.push({cur->right, 2});
    }
    return res;
}

// bool isLeaf(tree t) {
//     if(!t) 
//         return false;
//     if (!t->left && !t->right)
//         return true;
//     return false;
// }
// int Sum_Leaf_Right(tree t) {
//     if (!t)
//         return 0;
//     int res = 0;
//     if (isLeaf(t->right))
//         res = t->right->data;
//     if (t->right)
//         res += Sum_Leaf_Right(t->right);
//     if (t->left && !isLeaf(t->left))
//         res += Sum_Leaf_Right(t->left);
//     return res;
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        // tree root = NULL;
        // for(int i = 0; i < n; ++i){
        //     int u, v; char x; 
        //     cin >> u >> v >> x;
        //     addTree(root, u, v, x);
        // }
        tree root = MakeTree(n);
        cout << Sum_LeafRight(root) << endl;
    }
    return 0;
}
