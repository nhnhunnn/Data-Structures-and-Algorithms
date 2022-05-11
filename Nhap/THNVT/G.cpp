#include <bits/stdc++.h>
using namespace std;
bool ktra(string s){
	map<char, int> cnt;
	for(int i = 0; i < s.size(); i++) 
		++cnt[s[i]];
	return (cnt['2'] != 0 && cnt['3'] != 0 && cnt['5'] != 0 && cnt['7'] != 0);
}
int main(){
	queue<string> q;
	vector<string> v;
	q.push("2"); q.push("3"); q.push("5"); q.push("7");
	while(!q.empty()){
		string t = q.front();
		q.pop();
		if(t.size() >= 10) break;
		else if(ktra(t) && t[t.size() - 1] != '2') 
			v.push_back(t);
		q.push(t + "2");
		q.push(t + "3");
		q.push(t + "5");
		q.push(t + "7");
	}
	int n; cin >> n;
	for(int i = 0; i < v.size(); i++) 
		if(v[i].size() <= n)
			cout << v[i] << endl;
}
