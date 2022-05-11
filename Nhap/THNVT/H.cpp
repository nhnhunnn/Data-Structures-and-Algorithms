#include <bits/stdc++.h>
using namespace std;
const map<string, string> m = { {"0000", "0"}, {"0001", "1"}, {"0010", "2"}, {"0011", "3"},
								{"0100", "4"}, {"0101", "5"}, {"0110", "6"}, {"0111", "7"},
								{"1000", "8"}, {"1001", "9"}, {"1010", "A"}, {"1011", "B"},
								{"1100", "C"}, {"1101", "D"}, {"1110", "E"}, {"1111", "F"}
};
string f[105][105];
char a[105][105];
int n;
string BinToOct(string binz){
	string res = "";
	while(binz.size() % 4 != 0) binz = "0" + binz;
	for(int i = 0; i < binz.size(); i += 4){
		string t = binz.substr(i, 4);
		if(m.find(t) != m.end())
			res += (m.find(t)->second);
	}
	while(res[0] == '0') res.erase(res.begin());
	return res;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) cin >> a[i][j];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(i == 1 || j == 1){
				if(i == 1){
					if(j != 1) f[i][j] = f[i][j - 1] + a[i][j];
					else f[i][j] = a[i][j];
				}
				if(j == 1){
					if(i != 1) f[i][j] = f[i - 1][j] + a[i][j];
					else f[i][j] = a[i][j];
				}
			}else{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				f[i][j] += a[i][j];
			}
		}
	}
	cout << BinToOct(f[n][n]) << endl;
}
