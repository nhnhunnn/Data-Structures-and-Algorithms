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
// Date: 14/03/22 21:56
// Program: Sap xep vien bi
// -------------------  Your code STARTS here !!!---------------------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a; cin >> a;
    string b; cin >> b;
    int mp[3];
    memset(mp, 0, sizeof(mp));
    for(int i = 0; i < a; i ++){
        if(b[i] == 'X') mp[0] ++;
        if(b[i] == 'T') mp[1] ++;
        if(b[i] == 'D') mp[2] ++;
    }
    int res = 0;
    for(int i = 0; i < mp[0]; i ++){
        if (b[i] == 'T'){
            for(int j = mp[0]; j < a; j++){
                if (b[j] == 'X'){
                    swap(b[i], b[j]);
                    ++res;
                    break;
                }
            }
        }
        else if (b[i] == 'D'){
            for(int j = a - 1; j >= mp[0]; j--){
                if (b[j] == 'X'){
                    swap(b[i], b[j]);
                    ++res;
                    break;
                }
            }
        }
    }
    for(int i = mp[0]; i < mp[0] + mp[1]; i++){
        if (b[i] == 'D'){
            for(int j = mp[0] + mp[1]; j < a; j++){
                if (b[j] == 'T'){
                    swap(b[i], b[j]);
                    ++res;
                    break;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}