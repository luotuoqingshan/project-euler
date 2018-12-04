#include "PE.h"
int a[85][85];
int dp[85][85];
int b[85][85];
int c[85][85];
int pre[85],suf[85];
int main(){
	freopen("p082_matrix.txt","r",stdin);
	
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
	int ans = 1e9;
	for(int j = 1;j <= 80;j++){
		for(int i = 1;i <= 80;i++){
			if(i == 1){
				b[i][j] = dp[i][j - 1] + a[i][j];
			}else{
				b[i][j] = min(dp[i][j - 1],b[i - 1][j]) + a[i][j];
			}
		}
		for(int i = 80;i >= 1;i--){
			if(i == 80){
				c[i][j] = dp[i][j - 1] + a[i][j];
			}else{
				c[i][j] = min(dp[i][j - 1],c[i + 1][j]) + a[i][j];
			}
		}
		for(int i = 1;i <= 80;i++){
			dp[i][j] = min(c[i][j],b[i][j]);
			if(j == 80) ans = min(ans,dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}
/*
   131 673 234 103 18
201 96 342 965 150
630 803 746 422 111
537 699 497 121 956
805 732 524 37 331
*/
