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
// Program: Cay nhi phan bang nhau
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
tree Search(tree t, int x){
    if(t == NULL) return NULL;
    if(t->data == x) return t;
    tree p = Search(t->left, x);
    if(p == NULL) p = Search(t->right, x);
    return p;
}
void addLeft(tree &t, int u, int v){
    tree p = Search(t, u), q;
    if(p == NULL) return;
    if(p->left == NULL) {
        q = MakeRoot(v);
        p->left = q;
    }
}

void addRight(tree &t, int u, int v){
    tree p = Search(t, u), q;
    if(p == NULL) return;
    if(p->right == NULL) {
        q = MakeRoot(v);
        p->right = q;
    }
}
bool compareTree(tree a, tree b){
    if(a == NULL || b == NULL){
        if(a == b)
            return true;
        return false;
    }
    if(a->data != b->data) 
        return false;
    return compareTree(a->left, b->left) && compareTree(a->right, b->right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n;
        tree root1 = NULL;
        tree root2 = NULL;
        for(int i = 0; i < n; ++i){
            int u, v; char x; 
            cin >> u >> v >> x;
            if(root1 == NULL){
                root1 = MakeRoot(u);
            }
            if(x == 'L') addLeft(root1, u, v);
            else addRight(root1, u, v);
        }
        cin >> m;
        if(n != m){
            cout << "0" << endl;
            continue;
        }
        for(int i = 0; i < m; ++i){
            int u, v; char x; 
            cin >> u >> v >> x;
            if(root2 == NULL){
                root2 = MakeRoot(u);
            }
            if(x == 'L') addLeft(root2, u, v);
            else addRight(root2, u, v);
        }
        if(compareTree(root1, root2)) cout << "1";
        else cout << "0";
        cout << endl;
    }
    return 0;
}