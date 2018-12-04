#include "PE.h"

double c[75][25];

double ans = 0;

void dfs(int n,int left,int color,double m){
	if(n == 8){
		if(left == 0){
			ans += color * m;
		}
		return;
	}
	dfs(n + 1,left,color,m);
	int mx = min(10,left);
	for(int i = 1;i <= mx;i++){
		dfs(n + 1,left - i,color + 1,m * c[10][i]);
	}
}

int main(){
	c[0][0] = 1;
	for(int i = 1;i <= 70;i++){
		c[i][0] = 1.0;
		c[i][i] = 1.0;
		for(int j = 1;j < i;j++){
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	dfs(1,20,0,1);
	printf("%.9lf\n",ans / c[70][20]);
	return 0;
}
