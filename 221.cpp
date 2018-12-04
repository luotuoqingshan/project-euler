#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long LL;
map<LL,int> mp;
const int maxn = 1000000 + 5;
vector<int> d[maxn];
int main(){
	for(int i = 1;i < maxn;i++){
		for(int j = i;j < maxn;j += i){
			d[j].push_back(i);
		}
	}
	for(int p = 1;p < maxn;p++){
		for(int i = 1;1LL * i * i <= 1LL * p * p + 1;i++){
			if((1LL * p * p + 1) % i == 0){
				LL q = (1LL * p * p + 1) / i + p;
				LL r = p + i;
				mp[q * r * p]++;
			}
		}
	}
	cout << mp.size() << endl;
	return 0;
}
