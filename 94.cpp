#include "PE.h"



int main(){
	long long sum1 = 0;
	for(int i = 3;i <= 400000000;i += 2){
		long long n2 = (3LL * i + 1) * (i - 1);
		long long root = sqrt(n2);
		if(root * root == n2){
			cout << i << endl;
			sum1 += 3LL * i + 1;
		}
	}
	for(int i = 3;i <= 400000000;i += 2){
		long long n2 = (3LL * i - 1) * (i + 1);
		long long root = sqrt(n2);
		if(root * root == n2){
			cout << i << endl;
			sum1 += 3LL * i - 1;
		}
	}
	cout << sum1 << endl;
	long long sum = 0;
	for(long long i = 1;;i++){
		long long p = 4 * i * i - 1;
		if(p > 1000000000LL) break;
		long long q = 3 * p - 1;
		long long j = sqrt(q);
		if(j * j == q){
			cout << p << endl;
			long long perimeters = 2 * p + p - 1;
			if(perimeters > 1000000000LL) break;
			sum += perimeters;
		}
	}
	for(long long i = 1;;i += 2){
		long long p = 2 * i * i - 1;
		if(p > 1000000000LL) break;
		long long q = 3 * p - 1;
		long long j = sqrt(q / 2);
		if(j * j == q / 2){
			cout << p << endl;
			long long perimeters = 2 * p + p - 1;
			if(perimeters > 1000000000LL) break;
			sum += perimeters;
		}
	}
	cout << sum << endl;	
	for(long long i = 1;;i += 2){
		long long p = 2 * i * i + 1;
		if(p > 1000000000LL) break;
		long long q = 3 * p + 1;
		long long j = sqrt(q / 2);
		if(j * j == q / 2){
			cout << p << endl;
			long long perimeters = 2 * p + p + 1;
			if(perimeters > 1000000000LL) break;
			sum += perimeters;
		}
	}
	for(long long i = 1;;i++){
		long long p = 4 * i * i + 1;
		if(p > 1000000000LL) break;
		long long q = 3 * p + 1;
		long long j = sqrt(q);
		if(j * j == q){
			cout << p << endl;
			long long perimeters = 2 * p + p + 1;
			if(perimeters > 1000000000LL) break;
			sum += perimeters;
		}
	}
	cout << sum << endl;
	return 0;
}
