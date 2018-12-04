#include "PE.h"

bool cmp(int x,int y){
	int b[100],tot1 = 0;
	int c[100],tot2 = 0;
	while(x > 0){
		b[++tot1] = x % 10;
		x /= 10;
	}
	while(y > 0){
		c[++tot2] = y % 10;
		y /= 10;
	}
	sort(b + 1,b + 1 + tot1);
	sort(c + 1,c + 1 + tot2);
	if(tot1 != tot2) return 0;
	for(int i = 1;i <= tot1;i++){
		if(b[i] != c[i]) return 0;
	}
	return 1;
}

int main(){
	for(int i = 1;;i++){
		if(cmp(i,2 * i) && cmp(i,3 * i) && cmp(i,4 * i) && cmp(i,5 * i) && cmp(i,6 * i)){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
