#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x = abs(a - c);
	int y = abs(b - d);
	if(x == y) 
		cout << x;
	else 
		cout << min(x, y) + abs(x - y);
	
	return 0;
}
