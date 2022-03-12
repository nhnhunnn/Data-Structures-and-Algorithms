#include <bits/stdc++.h>
using namespace std;
long long n,l,r;

string something(long long n){
    if(n==1) return "1";
	     string temp=something(n/2);
   return temp + char((n%2)+'0')+ temp;
}

main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>l>>r;
        string test=something(n); 
        long long count=0;
        for(int i=l;i<=r;i++)
            if(test[i]=='1') count++;
        cout<<count<<endl;
    }    
}
