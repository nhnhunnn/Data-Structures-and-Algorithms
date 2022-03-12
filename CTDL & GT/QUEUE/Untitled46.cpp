#include <bits/stdc++.h>
using namespace std;


int main(){
	vector<long long>v; 
	queue<long long>q;
	q.push(9);
	for(int i=1;i<=101;i++){
		long long s1=q.front();
		q.pop();
		v.push_back(s1);
		long long s2=s1; 
		q.push(s1*10);
		q.push(s2*10+9); 
	} 
	int t;cin>>t;
	while(t--){
		int n; 
		cin>>n; 
		for (int i = 0; i < v.size(); i++) {
            if (v[i] % n == 0) {
                cout << v[i] << endl;
                break;
            }
        }
	} 
} 
