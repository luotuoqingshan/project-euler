#include "PE.h"


int cal(int p){
	int ans = 0;
	for(int i = 1;i <= p;i++){
		for(int j = i;j <= p;j++){
			int k = p - i - j;
			if(k < j) continue;
			if(i * i + j * j == k * k){
				ans++;
			}
		}
	}
	return ans;
}

int main(){
	int ans = 0;
	for(int i = 1;i <= 1000;i++){
		if(cal(i) == 8) cout << i << endl;
	}
	return 0;
}
