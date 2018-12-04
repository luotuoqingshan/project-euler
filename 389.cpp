#include "PE.h"

const int maxn = 4 * 6 * 8 * 12 * 20 + 5;

typedef double db;

db f[2][maxn],g[maxn];
db ans[maxn];
int cal(int n,int d){
	for(int i = 1;i <= n;i++){
		g[i] = ans[i];
	}	
	memset(f,0,sizeof(f));
	memset(ans,0,sizeof(ans));
	for(int i = 1;i <= n;i++){
		f[0][0] = g[i];
		for(int j = 1;j <= i;j++){

		}	
	}
}

int main(){
	int n;
	n = 1;
	return 0;
}
