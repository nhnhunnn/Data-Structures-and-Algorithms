#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i]; 
		} 
		sort(a,a+n);
		int mid=n/2+n%2-1;
		int i=n-1,j=mid;
		int dem=0;
		while(i>=mid&&j>=0){
			if(a[i]>=2*a[j]){
				dem++;
				i--;
				j--; 
			} 
			else j--; 
		} 
		cout<<dem+n-2*dem<<endl; 
	} 
	return 0; 
}
