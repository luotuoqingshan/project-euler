#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int mod = 1e8 + 7;

struct matrix{
	int a[512][512];
	matrix(){
		memset(a,0,sizeof(a));
	}
	matrix operator * (matrix b){
		matrix c;
		for(int i = 0;i < 512;i++){
			for(int j = 0;j < 512;j++){
				for(int k = 0;k < 512;k++){
					c.a[i][k] = (c.a[i][k] + 1LL * a[i][j] * b.a[j][k] % mod) % mod;
				}
			}
		}
	}
	matrix operator ^ (int n){
		matrix c;

	}
	matrix operator - (int n){

	}
}


int main(){
	memset(vis,0,sizeof(vis));	

	return 0;
}
