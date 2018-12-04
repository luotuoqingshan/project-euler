#include "PE.h"

const int maxn = 305;

int f[maxn];

int sz[8] = {1,2,5,10,20,50,100,200};

int main(){
	memset(f,0,sizeof(f));
	f[0] = 1;
	for(int i = 0;i < 8;i++){
		for(int j = sz[i];j <= 200;j++){
			f[j] += f[j - sz[i]];
		}
	}
	cout << f[200] << endl;
	return 0;
}
