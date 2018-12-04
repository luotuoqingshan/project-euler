#include "PE.h"


int main(){
	for(int i = 1;i <= 1000000;i++){
		int tmp = i;
		int x = 1;
		for(int j = 2;j * j <= i;j++){
			int cnt = 0;
			while(tmp % j == 0){
				tmp /= j;
				cnt++;
			}
			x = x * (cnt * 2 + 1);
		}
		if((x + 1) / 2 > 1000){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
