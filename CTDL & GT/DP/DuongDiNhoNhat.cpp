#include <bits/stdc++.h> 
using namespace std;
int temp[1001][1001]; 
int a[1001][1001]; 
int Max(int n, int m){
	int t=1;
	temp[0][0]=0; 
	for(int i=1;i<=1001;i++){
		temp[0][i]=INT_MAX; 
	} 
	for(int i=1;i<=1001;i++){
		temp[i][0]=INT_MAX; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			temp[i][j]=a[i][j]+min(temp[i-1][j-1],min(temp[i-1][j],temp[i][j-1])); 
		}	
	}  
	 return temp[n][m]; 
} 
int main(){
	int t;cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j]; 
			} 
		}
		cout<<Max(n,m)<<endl; 
	} 
	return 0; 
}
