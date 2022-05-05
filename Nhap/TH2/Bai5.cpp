#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dx[] = {0, 1};
const int dy[] = {1, 0};
int n, a[105][105];
ll dis[105][105];
priority_queue<pair<pair<int, int>, string>,
                vector<pair<pair<int, int>, string> >,
                greater<pair<pair<int, int>, string> > > q;
string res = "";
string Convert(string binary){
    ll d = 0;
    for(int i = 0; i < binary.size(); i ++)
        d = 2 * d + binary[i] - '0';
    stringstream st;
    st << hex << d;
    return st.str();
}
void bfs(){
    dis[1][1] = a[1][1];
    q.push({{1, 1}, to_string(a[1][1])});
    while(!q.empty()){
        pair<int, int> c = q.top().first;
        int x = c.first, y = c.second;
        string w = q.top().second;
        if(x == n && y == n){
            res = max(res, w);
        }
        q.pop();
        for(int i = 0; i < 2; ++i){
            int u = x + dx[i], v = y + dy[i];
            if(u <= n && v <= n){
                if(dis[u][v] > w * 10 + a[u][v]){
                    dis[u][v] = w * 10 + a[u][v];
                    q.push({{u, v}, dis[u][v]});
                }
            }
        }
    }
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
        res = a[1][1];
        bfs();
        cout << Convert(res) << endl;
    }
    return 0;
}
