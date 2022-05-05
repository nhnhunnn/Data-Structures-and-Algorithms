#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dx[] = {0, 1};
const int dy[] = {1, 0};
int n, a[105][105];
string res = "";
string Convert(string binary){
	ll d = 0;
	for(int i = 0; i < binary.size(); i ++)
        d = 2 * d + binary[i] - '0';
    stringstream st;
    st << hex << d;
    return st.str();
}

void dfs(int x, int y, string s){
    s += to_string(a[x][y]);
    if(x == n && y == n){
    	res = max(res, s);
    	return;
    }
    for(int i = 0; i < 2; ++i){
        int u = x + dx[i], v = y + dy[i];
        if(u <= n && v <= n)
            dfs(u, v, s);
    }
    s.pop_back();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j)
                cin >> a[i][j];
        }
        res.clear();
        dfs(1, 1, "");
        cout << Convert(res) << endl;
    }
    return 0;
}
