#include "PE.h"


int nums[1500005];

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a % b);
}


int main(){
	for(int i = 2;i * i <= 1500000;i++){
		for(int j = 1;j < i;j++){
			int A = i * i - j * j;
			int B = 2 * i * j;
			int C = i * i + j * j;
			if((i - j) & 1 && gcd(i,j) == 1){
				for(int k = 1;;k++){
					int A1 = A * k;
					int B1 = B * k;
					int C1 = C * k;
					if(A1 + B1 + C1 <= 1500000){
						nums[A1 + B1 + C1]++;
					}else break;
				}
			}
		}
	}	
	int ans = 0;
	for(int i = 1;i <= 1500000;i++){
		ans += (nums[i] == 1);
	}
	cout << ans << endl;
	return 0;
}
