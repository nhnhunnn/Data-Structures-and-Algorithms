#include <bits/stdc++.h>
using namespace std;
int a[41]; 
int dem(string s){
	int l=s.size();
	if(s[0]=='0') return 0;
	else a[1]=1;
	a[0]=1;
	for(int i=2;i<=l;i++){
		a[i]=0;
		if(s[i-1]!='0') a[i]+=a[i-1];
		if(s[i-2]=='1'||s[i-2]=='2'&&s[i-1]<='6') a[i]+=a[i-2]; 
	} 
	return a[l]; 
} 
int main(){
	int t;cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<dem(s)<<endl; 
	} 
}
