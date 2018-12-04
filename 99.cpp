#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a,b;
	freopen("p099_base_exp.txt","r",stdin);
	int id = 0;
	double ans = 0;
	int cnt = 0;
	while(scanf("%d,%d",&a,&b) != EOF){
		cnt++;
		double tmp = b * log(a);
		if(tmp > ans){
			ans = tmp;
			id = cnt;
		}
	}
	cout << id << endl;
	return 0;
}
