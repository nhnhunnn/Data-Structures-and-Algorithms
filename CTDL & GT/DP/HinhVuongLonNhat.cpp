#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int a[1000][1000]; 
int dem(int n,int m){
	int Max=0; 
	for(int i=0;i<n;i++){
		arr[i][0]=a[i][0]; 
	}
	for(int i=0;i<m;i++){
		arr[0][i]=a[0][i];
	}
	
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(a[i][j]==1){
				arr[i][j]=min(min(arr[i-1][j]+1,arr[i][j-1]+1),arr[i-1][j-1]+1); 
			}
			else arr[i][j]=0; 
			Max=max(Max,arr[i][j]);
		}
	} 
	return Max; 
} 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m; 
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}  
		}
		cout<<dem(n,m)<<endl; 
	} 
}
