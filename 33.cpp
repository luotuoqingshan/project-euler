#include "PE.h"



int main(){
	for(int i = 10;i < 100;i++){
		int a = i / 10, b = i % 10;
		for(int j = i + 1;j < 100;j++){
			int c = j / 10, d = j % 10;
			if(a * j == d * i || b * j == c * i){
				if(a == b && c == d) continue;
				cout << j << " " << i << endl;
			}
		}
	}	


	return 0;
}
