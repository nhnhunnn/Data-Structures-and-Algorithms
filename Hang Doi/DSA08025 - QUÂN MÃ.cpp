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
// Date: 07/03/22 08:30
// Program: Quan Ma
// -------------------  Your code STARTS here !!!---------------------------

const int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
const int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};

bool visited[8][8];
pair<int, int> st, en;

void Try(){
	string a, b;
	cin >> a >> b;
	st = {int(a[0] - 'a'), a[1] - 49};
	en = {int(b[0] - 'a'), b[1] - 49};
	memset(visited, false, sizeof(visited));
	queue< pair <pair <int, int>, int > > q;

	q.push({st, 0});
	pair<int, int> t;
	int x, y;
	while(!q.empty()){
		t = q.front().f;
		if(t.f == en.f && t.s == en.s){
			cout << q.front().s << endl;
			return;
		}
		for(int i = 0; i < 8; ++i){
			x = t.f + dx[i]; y = t.s + dy[i];
			if(x < 0 || y < 0 || x > 7 || y > 7 || visited[x][y])
				continue;
			visited[x][y] = true;
			q.push({{x, y}, q.front().s + 1});
		}
		q.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int t; cin >> t;
	for(int i = 0; i < t; ++i){
		Try();
	}
	return 0;
}
