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
// Date: 18/02/22 14:51
// Program: Chia deu
// -------------------  Your code STARTS here !!!---------------------------

int a, b, c, d, e;
int per[10], x[10], y[10];
int res;
bool visited[100];

void init(){
	cin >> a >> b >> c >> d >> e;
	memset(visited, false, sizeof(visited));
	res = 0;
}

bool Solve(){
	int ans = 0;
	switch(y[1]){
		case 1:{
			ans = per[1] + per[2];
			break;
		}
		case 2:{
			ans = per[1] - per[2];
			break;
		}
		case 3:{
			ans = per[1] * per[2];
			break;
		}
	}
	for(int i = 2; i <= 4; i ++){
		switch(y[i]){
			case 1:{
				ans += per[i + 1];
				break;
			}
			case 2:{
				ans -= per[i + 1];
				break;
			}
			case 3:{
				ans *= per[i + 1];
				break;
			}
		}
	}
	return ans == 23;
}


void make_per(){
	for(int i = 1; i <= 5; i ++){
		switch(x[i]){
			case 1: {
	            per[i] = a;
	            break;
	        }
	        case 2: {
	            per[i] = b;
	            break;
	        }
	        case 3: {
	            per[i] = c;
	            break;
	        }
	        case 4: {
	            per[i] = d;
	            break;
	        }
	        case 5: {
	            per[i] = e;
	            break;
	        }
        }
	}
}

void Try_with_expr(int j){
	if(res > 0)
		return;
	for(int i = 1; i <= 3; i ++){
		y[j] = i;
		if(j == 4){
			if(Solve())
				res++;
			if(res > 0)
				return;
		} 
		else Try_with_expr(j + 1);
	}
}

void Try_with_per(int i){
	if(res > 0)
		return;
	for(int j = 1; j <= 5; j ++){
		if(!visited[j]){
			visited[j] = true;
			x[i] = j;
			if(i == 5){
				make_per();
				Try_with_expr(1);
			}
			else 
				Try_with_per(i + 1);
			visited[j] = false;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		init();
		Try_with_per(1);
		if(res > 0) 
			cout << "YES";
		else 
			cout << "NO";
		cout << endl;
	}
	return 0;
}
