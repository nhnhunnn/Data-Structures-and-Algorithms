#include <bits/stdc++.h>
using namespace std;
int a[101][101]; 
int length(string s){
	int l=s.size(); 
	for(int i=1;i<=l;i++){
		for(int j=1;j<=l;j++){
			if(i!=j&&s[i-1]==s[j-1]) a[i][j]=a[i-1][j-1]+1;
			else a[i][j]=max(a[i-1][j],a[i][j-1]); 
		} 
	}
	return a[l][l]; 
} 
int main(){
	int t;cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s; 
		cout<<length(s)<<endl; 
	} 
}
