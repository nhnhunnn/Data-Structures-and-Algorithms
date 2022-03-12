#include <bits/stdc++.h>
using namespace std;
#define R 1000000007 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[102][102];
		long long s[102];
		memset(s,0,sizeof(s)); 
		memset(a,0,sizeof(a));
		for(int i=1;i<=10;i++){
			a[2][i]=i;
		} 
		for(int i=1;i<=n+1;i++){
			a[i][1]=1; 
		} 
		for(int i=2;i<=n+1;i++){
			for(int j=2;j<=10;j++){
				a[i][j]=a[i-1][j]+a[i][j-1]; 
			} 
		}
		for(int i=1;i<=10;i++){
			s[n+1]=s[n+1]+a[n+1][i];
			s[n+1]%=R; 
		} 
		cout<<s[n+1]<<endl;
	} 
} 
