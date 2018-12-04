#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;


LL c[27][27];

LL cal(int n){
	LL ans = c[26][n];
	LL tmp = 1LL << n;
	tmp -= 2;
	tmp -= (n - 1);
	ans = ans * tmp;
	return ans;
}

int main(){
	c[0][0] = 1;
	for(int i = 1;i <= 26;i++){
		c[i][0] = c[i][i] = 1;
		for(int j = 1;j < i;j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	LL ans = 0;
	for(int i = 2;i <= 26;i++){
		ans = max(ans,cal(i));
	}
	cout << ans << endl;
	return 0;
}
