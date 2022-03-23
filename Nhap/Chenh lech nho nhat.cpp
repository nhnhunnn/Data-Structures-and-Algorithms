#include <bits/stdc++.h>
using namespace std;
int n, k, a[10];
vector<string> v;
long long res;
bool ok;
void sinhketiep(){
	int i = k - 1;
	while(a[i] > a[i + 1] && i >= 1) --i;
	if(i == 0) ok = true;
	else{
		int j = k;
		while(a[i] > a[j]) --j;
		swap(a[i], a[j]);
		for(int h = 0; h < n; h ++)
			swap(v[h][i - 1], v[h][j - 1]);
		reverse(a + i + 1, a + k + 1);
		for(int h = 0; h < n; h ++){
			reverse(v[h].begin() + i, v[h].end());
		}
	}
}
int main(){
	cin >> n >> k;
	v.clear();
	for(int i = 0; i < n; i ++){
		string x; cin >> x; v.push_back(x);
	}
	for(int i = 1; i <= k; i ++) a[i] = i;
	res = 1e9;
	ok = false;
	while(!ok){
		vector<string> s = v;
		sort(s.begin(), s.end());
		res = min(res, stoll(s.back()) - stoll(s.front()));
		s.clear();
		sinhketiep();
	}
	cout << res << endl;
	return 0;
}
