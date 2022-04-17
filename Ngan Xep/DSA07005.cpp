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
// Date: 19/03/22 22:00
// Program: Bieu thuc tuong duong
// -------------------  Your code STARTS here !!!---------------------------

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.length();
        stack<char> st, res;
        for(int i = 0; i < n; i ++){
            if(s[i] != ')')
                st.push(s[i]);
            else{
                while(!st.empty() && st.top() != '('){ res.push(st.top()); st.pop(); }
                st.pop();
                if(!st.empty() && st.top() == '-'){
                    while(!res.empty()){
                        if(res.top() == '+') st.push('-');
                        else if(res.top() == '-') st.push('+');
                        else st.push(res.top());
                        res.pop();
                    }
                }
                else while(!res.empty()){ st.push(res.top()); res.pop(); }
                
            }
        }
        while(!st.empty()){ res.push(st.top()); st.pop(); }
        while(!res.empty()){ cout << res.top(); res.pop(); }
        cout << endl;
    }
    return 0;
}