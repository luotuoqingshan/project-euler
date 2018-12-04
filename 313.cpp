#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include "PE.h"
using namespace std;
const int maxn = 1005;
int s[maxn][maxn][2];
const int INF = 0x3f3f3f3f;
bool vis[maxn];
void init(){
	memset(s,INF,sizeof(s));
	s[2][2][0] = s[2][2][1] = 5;
	for(int i = 2;i <= 1000;i++){
		for(int j = 2;j <= 1000;j++){
			if(i == 2 && j == 2) continue;
			s[i][j][0] = min(s[i][j][0],6 + s[i][j - 1][0]);
			s[i][j][0] = min(s[i][j][0],4 + s[i][j - 1][1]);
			s[i][j][1] = min(s[i][j][1],6 + s[i - 1][j][1]);
			s[i][j][1] = min(s[i][j][1],4 + s[i - 1][j][0]);
		}
	}
	int cnt = 0;
	for(int i = 2;i <= 10;i++){
		for(int j = 2;j <= 10;j++){
			printf("dp[%d][%d] = %d\n",i,j,min(s[i][j][0],s[i][j][1]));
			//int tmp = min(s[i][j][0],s[i][j][1]);
			//int x = sqrt(tmp);
			//if(x * x == tmp && x < 100 && vis[x] == 0){
		//		cout << i << " " << j << " " << x << endl;
		//	}
		}
	}
	cout << cnt << endl;
}

void cal(int n){
	vector<int> p = get_primes(n);
	long long cnt = 0;
	for(int i = 0;i < p.size();i++){
		int m = p[i];
		if((1LL * m * m + 11) % 8 == 0){
			cnt++;
		}
	}
	for(int i = 0;i < p.size();i++){
		long long m = (1LL * p[i] * p[i] + 7) / 8;
		long long j = (1LL * p[i] * p[i] + 13) / 6;
		long long ii = (1LL * p[i] * p[i] + 13 - 6 * j) / 2;	
		if(ii < 2) ii += 3;
		if(ii > m) continue;
		cnt += (m - ii + 3) / 3 * 2;
	}
	cout << cnt << endl;
}

int main(){
	/*vis[1] = 1;
	for(int i = 1;i <= 1000;i++){
		if(vis[i] == 0){
			for(int j = i * i;j <= 1000;j += i){
				vis[j] = 1;
			}
		}
	}*/
//	init();
	cal(1000000);	
	return 0;
}
