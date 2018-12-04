#include "PE.h"

int main(){
	int a[4];
	for(int i = 1000;i < 10000;i++){
		for(int j = i + 1;j < 10000;j++){
			int k = 2 * j  - i;
			if(k < 1000 || k >= 10000){
				continue;
			}
			if(!is_prime(i)) continue;
			if(!is_prime(j)) continue;
			if(!is_prime(k)) continue;
			//cout << i << " " << j << " " << k << endl;
			int a[10] = {0};
			int tmp = i;
			for(int l = 0;l < 4;l++){
				a[tmp % 10]++;
				tmp /= 10;
			}
			tmp = j;

			for(int l = 0;l < 4;l++){
				a[tmp % 10]++;
				tmp /= 10;
			}
			tmp = k;
			for(int l = 0;l < 4;l++){
				a[tmp % 10]++;
				tmp /= 10;
			}
			bool flag = true;
			for(int l = 0;l < 10;l++){
				if(a[l] % 3) flag = false;
			}	
			if(flag) cout << i << " " << j << " " << k << endl;
		}
	}
	return 0;
}
