#include <bits/stdc++.h>
using namespace std;
int a[10], b[10], n;
bool ok, ok1;
void CHL(){
	bool x = false;
	for(int i = n; i > 0; --i){
		if(a[i] != n){
			a[i] ++;
			for(int j = i + 1; j <= n; j ++) a[j] = 1;
			x = true;
			break;
		}
	}
	if(!x) ok = true;
}
void Next(){
	int i = n - 1;
	while(i >= 1 && b[i] > b[i + 1]) --i;
	if(i == 0) ok1 = true;
	else{
		int j = n;
		while(b[i] > b[j]) --j;
		swap(b[i], b[j]);
		reverse(b + i + 1, b + 1 + n);
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		b[i] = i;
		a[i] = 1;
	}
	ok1 = false;
	while(!ok1){
		ok = false;
		while(!ok){
			for(int i = 1; i <= n; i ++) cout << char(b[i] + 64);
			for(int i = 1; i <= n; i ++) cout << a[i];
			cout << endl;
			CHL();
		}
		for(int i = 1; i <= n; i ++) a[i] = 1;
			Next();
	}
	return 0;
}