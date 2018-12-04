#include "PE.h"

const int maxn = 105;

int sg[maxn];

int main(){
	sg[1] = 0;
	for(int i = 2;i <= 100;i++){
		bool vis[105] = {0};
		for(int j = 1;j < i;j++){
			if(i % j == 0){
				vis[sg[j]] = true;
			}
		}
		for(int j = 0;j < i;j++){
			if(!vis[j]){
				sg[i] = j;
				break;
			}
		}
		cout << i << " " << sg[i] << endl;
	}

	return 0;
}
