#include "PE.h"
int a[85][85];
int dp[85][85];
int main(){
	freopen("p081_matrix.txt","r",stdin);
	
	for(int i = 1;i <= 80;i++){
		for(int j = 1;j <= 80;j++){
			int d = 0;
			char c;
			while(true){
				c = getchar();
				if(c == ',' || c == EOF || c == '\n') break;
				d = d * 10 + c - '0';
			}
			a[i][j] = d;
		}
	}
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0][1] = 0;
	dp[1][0] = 0;
	for(int i = 1;i <= 80;i++){
		for(int j = 1;j <= 80;j++){
			dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + a[i][j];
		}
	}
	cout << dp[1][1] << endl;
	cout << dp[2][1] << endl;
	cout << a[2][1] << endl;
	cout << dp[80][80] << endl;
	return 0;
}
