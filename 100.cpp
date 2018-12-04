#include "PE.h"
typedef long long LL;
LL x[105],y[105];

int main(){
	x[0] = 1,y[0] = 1;
	for(int i = 1;;i++){
		x[i] = (3 * x[i - 1] + 4 * y[i - 1]);
		y[i] = (2 * x[i - 1] + 3 * y[i - 1]); 
		LL m = (x[i] + 1) / 2;
		LL n = (y[i] + 1) / 2;
		if(m + n > 1e12){
			cout << n << endl;
			break;
		}
	}
	return 0;
}
