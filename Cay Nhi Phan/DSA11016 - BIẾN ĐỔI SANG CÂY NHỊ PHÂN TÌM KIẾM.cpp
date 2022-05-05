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
// Program: Bien doi sang cay nhi phan tim kiem
// -------------------  Your code STARTS here !!!---------------------------

typedef struct node{
    int data;
    node *left;
    node *right;
} *tree;
int x, y;
char c;
tree MakeTree(int value){
    tree p = new node();
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;

}
bool isLeft(int cmp, int value){
    return value < cmp;
}
bool isRight(int cmp, int value){
    return value > cmp;
}
tree Insert(tree root, int value){
    if(root == NULL){
        root = MakeTree(value);
        return root;
    }
    if(isLeft(root->data, value)){
        root->left = Insert(root->left, value);
    }
    else if(isRight(root->data, value)){
        root->right = Insert(root->right, value);
    }
    return root;
}

void showInOrder(tree root){
    if (root == NULL) return;
    showInOrder(root->left);
    cout << root->data << " ";
    showInOrder(root->right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        tree root = NULL;
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int x, y; cin >> x >> y;
            char c; cin >> c;
            if(root == NULL){
                root = MakeTree(x);
            }
            root = Insert(root, y);
        }
        showInOrder(root);
        cout << endl;
    }
    return 0;
}
