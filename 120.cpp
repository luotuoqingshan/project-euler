#include "PE.h"

int cal(int a){
	int ans = 0;
	for(int i = 0;i <= a * a;i++){
		if(i & 1){
			ans = max(ans,2 * i * a % (a * a));
		}else ans = max(ans,2);
	}
	return ans;
}

int main(){
	int sum = 0;
	for(int i = 3;i <= 1000;i++){
		sum += cal(i);	
	}
	cout << sum << endl;
	return 0;
}
