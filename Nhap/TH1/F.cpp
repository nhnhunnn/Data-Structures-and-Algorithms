#include <bits/stdc++.h>
using namespace std;
int n, a[15], k;
vector<string> v;
long long res;
bool ok;
void Next(){
	int i = k - 1;
	while(a[i] > a[i + 1] && i >= 1) --i;
	if(i == 0) ok = true;
	else{
		int j = k;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		for(int x = 0; x < n; ++x){
			swap(v[x][i - 1], v[x][j - 1]);
		}
		reverse(a + i + 1, a + k + 1);
		for(int x = 0; x < n; ++x){
			reverse(v[x].begin() + i, v[x].end());
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	v.clear();
	for(int i = 0; i < n; i ++){
		string s; cin >> s; v.push_back(s);
	}
	for(int i = 1; i <= k; ++i) a[i] = i;
	res = 1e9;
	ok = false;
	while(!ok){
		vector<string> t = v;
		sort(t.begin(), t.end());
		res = min(res, stoll(t.back()) - stoll(t.front()));
		t.clear();
		Next();
	}
	cout << res << endl;
	return 0;
}