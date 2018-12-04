#include "PE.h"

int main(){
	int ans = 0;
	for(int i = 3;i <= 1001;i += 2){
		ans += 4 * i * i - 6 * i + 6;
	}	
	cout << ans + 1 << endl;
	return 0;
}
