#include "PE.h"

int main(){
	cout << is_prime(121313) << endl;
	/*int m = 120303;
	for(int i = 1;i < 10;i++){
		if(is_prime(m)){
			cout << m << endl;
		}
		m += 10;
	}*/
	for(int i = 10;i < 1000000;i++){
		if(!is_prime(i)) continue;
		int n = 0;
		int tmp = i;
		int a[20];
		while(tmp > 0){
			a[++n] = tmp % 10;
			tmp /= 10;
		}
		reverse(a + 1,a + 1 + n);
		int ans = 0;
		for(int j = 0;j < (1 << n) - 1;j++){

			if(j & 1){
				int cnt = 0;
				for(int k = 1;k < 10;k++){
					int b = 0;
					for(int l = 1;l <= n;l++){
						if(j & (1 << (l - 1))){
							b = b * 10 + k;
						}else{
							b = b * 10 + a[l];
						}
					}
					if(is_prime(b)) cnt++;
				}
					if(cnt == 8){
						cout << i << endl;
						cout << n << endl;
						int y = j;
						while(y > 0){
							printf("%d",y & 1);
							y /= 2;
						}
						return 0;
					}
			}else{
				int cnt = 0;
				for(int k = 0;k < 10;k++){
					int b = 0;
					for(int l = 1;l <= n;l++){
						if(j & (1 << (l - 1))){
							b = b * 10 + k;
						}else{
							b = b * 10 + a[l];
						}
					}
					if(is_prime(b)) cnt++;
				}
					if(cnt == 8){
						cout << i << endl;
						cout << n << endl;
						int y = j;
						while(y > 0){
							printf("%d",y & 1);
							y /= 2;
						}
						return 0;
					}
			}
		}
	}
	return 0;
}

