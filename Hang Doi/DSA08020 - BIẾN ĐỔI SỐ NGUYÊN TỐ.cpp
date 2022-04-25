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
// Date: 14/03/22 21:10
// Program: Bien doi so nguyen to
// -------------------  Your code STARTS here !!!---------------------------

vector<bool> eratosthenes_sieve(ll limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i * i <= limit; ++i)
        if(is_prime[i])
            for (ll j = i * i; j <= limit; j += i) is_prime[j] = false;
    return is_prime;
}

const vector<bool> prime = eratosthenes_sieve(9999);

void BFS(string s, string t){
    queue<string> q;
    q.push(s);
    int visited[9999];
    memset(visited, -1, sizeof(visited));
    visited[stoi(s)] = 0;
    while(!q.empty()){
        string c = q.front(); q.pop();
        for(int index = 0; index < 4; ++index){
            string a = c;
            int init, id;
            (index == 0 || index == 3) ? init = 1: init = 0;
            (index == 3) ? id = 2 : id = 1;
            for(int i = init; i <= 9; i = i + id){
                if(a[index] - '0' != i){
                    a[index] = char(i + '0');
                    if(prime[stoi(a)]){
                        string b = a;
                        if(visited[stoi(b)] == -1){
                            visited[stoi(b)] = visited[stoi(c)] + 1;
                            q.push(b);
                        }
                    }
                }
            }
        }
    }
    cout << visited[stoi(t)] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        string s, t; cin >> s >> t;
        BFS(s, t);
    }
    return 0;
} 
