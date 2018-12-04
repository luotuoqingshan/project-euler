#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int x[3],y[3];

int main(){
	freopen("p102_triangles.txt","r",stdin);
	long long ans = 0;
	while(scanf("%d,%d,%d,%d,%d,%d",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]) != EOF){
		int num[3] = {0};
		for(int i = 0;i < 3;i++){
			int j = (i + 1) % 3;
			int val = (x[j] - x[i]) * (0 - y[i]) - (0 - x[i]) * (y[j] - y[i]);
			if(val > 0) num[2]++;
			else if(val == 0) num[1]++;
			else num[0]++;
			if(num[2] == 3 || num[0] == 3) ans++;

		}
	}
	cout << ans << endl;
	return 0;
}
