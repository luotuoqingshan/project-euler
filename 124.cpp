#include "PE.h"

struct node{
	int n;
   	int rad;	
	bool operator < (const node & rhs) const{
		if(rad == rhs.rad) return n < rhs.n;
		else return rad < rhs.rad;
	}
};

node a[100005];

int main(){
	for(int i = 1;i <= 100000;i++){
		int tmp = i;
		a[i].rad = 1;
		a[i].n = i;
		for(int j = 2;j * j <= i;j++){
			if(tmp % j) continue;
			while(tmp % j == 0){
				tmp /= j;
			}
			a[i].rad *= j;
		}
		a[i].rad *= tmp;
	}	
	sort(a + 1,a + 1 + 100000);
	cout << a[10000].n << endl;
	return 0;
}
