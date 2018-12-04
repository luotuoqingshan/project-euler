#include "PE.h"

int sqr(int a){
	return a * a;
}

int dis(int a,int b,int c,int d){
	return sqr(a - c) + sqr(b - d);
}

int main(){
	int cnt = 0;
	int cnt1 = 0;
	for(int x1 = 0;x1 <= 50;x1++){
		for(int x2 = 0;x2 <= 50;x2++){
			for(int y1 = 0;y1 <= 50;y1++){
				for(int y2 = 0;y2 <= 50;y2++){
					int len1 = dis(0,0,x1,y1);
					int len2 = dis(0,0,x2,y2);
					int len3 = dis(x1,y1,x2,y2);
					if(len1 == 0 || len2 == 0 || len3 == 0) continue;
					//if(len1 + len2 == len3 || len1 == len2 + len3) cnt++;
					if(len1 + len2 == len3) cnt++;
					if(len1 == len2 + len3) cnt1++;
				}
			}
		}
	}
	cout << cnt / 2 + cnt1 << endl;
	return 0;
}
