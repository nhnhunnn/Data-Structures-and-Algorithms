#include <bits/stdc++.h>
using namespace std;
int a[20], n, k;
void Try(int i){
	for(int j = n - k + i; j > a[i - 1]; j--){
		a[i] = j;
		if(i == k){
			for(int x = 1; x <= k; ++x){
				cout << a[x] << " ";
			}
			cout << endl;
		}
		else Try(i + 1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		Try(1);
	}
}