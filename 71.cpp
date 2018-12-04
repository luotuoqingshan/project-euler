#include "PE.h"
const int maxn = 1000005;
int ans[maxn];

int main(){
	for(int i = 1;i <= 1000000;i++){
		ans[i] = 3 * i / 7;
		if(ans[i] * 7 == 3 * i) ans[i]--;
	}	
	double ret = 0;
	double id = 0;
	for(int i = 1;i <= 1000000;i++){
		if(ans[i] * 1.0 / i > ret){
			ret = ans[i] * 1.0 / i;
			id = ans[i];
		}
	}
	cout << id << endl;
	return 0;
}
