#include <bits/stdc++.h>
using namespace std;
long long tinh(long long a,long long b, char c){
	if(c=='+') return a+b; 
	if(c=='-') return a-b;
	if(c=='*') return a*b;
	if(c=='/') return a/b;
} 
long long val(string s){
	int a=s.length();
	stack<long long>t;
	for(int i=0;i<a;i++){
		if(isdigit(s[i])) t.push(s[i]-48);
		else{
			long long a1=t.top();t.pop();
			long long a2=t.top();t.pop();
			long long v=tinh(a2,a1,s[i]); t.push(v); 
		}  
	} 
	return t.top(); 
} 
int main(){
	int t;cin>>t;
	cin.ignore(); 
	while(t--){
		string s;
		cin>>s; 
		cout<<val(s)<<endl; 
	} 
}
