#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

typedef long double db;
const db eps = 1e-15;
const db pi = acos(-1);
int dcmp(db x){
	return x < -eps ? -1 : x > eps;
}

db X;

db cal(db rad){
	db x = 0;
	x += tan(rad) * (X - 50) / 2;
	rad = asin(9.0 / 10.0 * sin(rad));
	x += tan(rad) * 10;
	rad = asin(8.0 / 9.0 * sin(rad));
	x += tan(rad) * 10;
	rad = asin(7.0 / 8.0 * sin(rad));
	x += tan(rad) * 10;
	rad = asin(6.0 / 7.0 * sin(rad));
	x += tan(rad) * 10;
	rad = asin(5.0 / 6.0 * sin(rad));
	x += tan(rad) * 10;
	rad = asin(10.0 / 5.0 * sin(rad));
	x += tan(rad) * (X - 50) / 2;
	return x;
}

int main(){
	
	db l = 0,r = pi / 2 - eps;
	X = (db)50.0 * sqrt(2);
	for(int i = 1;i <= 100000;i++){
		db mid = (l + r) / 2;
		if(dcmp(cal(mid) - X) >= 0){
			r = mid;
		}else{
			l = mid;
		}
	}	
	db t = 0;
	t += ((X - 50) / 2) / cos(l) / 10.0;
	l = asin(9.0 / 10.0 * sin(l));
	t += 10 / cos(l) / 9.0; 
	l = asin(8.0 / 9.0 * sin(l));
	t += 10 / cos(l) / 8.0;
	l = asin(7.0 / 8.0 * sin(l));
	t += 10 / cos(l) / 7.0; 
	l = asin(6.0 / 7.0 * sin(l));
	t += 10 / cos(l) / 6.0; 
	l = asin(5.0 / 6.0 * sin(l));
	t += 10 / cos(l) / 5.0; 
	l = asin(10.0 / 5.0 * sin(l));
	t += ((X - 50) / 2) / cos(l) / 10.0;	
	printf("%.10Lf\n",t);
	return 0;
}
