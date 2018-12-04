#include "PE.h"

set<int> s;

void dfs(vector<double> now){
	if(now.size() == 1){
		int x = (now[0] + 1e-5);
		if(x <= 0) return;
		if(fabs(x - now[0]) < 1e-4){
			s.insert(x);
		}
		return;
	}
	for(int i = 0;i < now.size();i++){
		for(int j = 0;j < now.size();j++){
			if(i != j){
				double p = now[i],q = now[j];
				vector<double> temp = vector<double>();
				for(int k = 0;k < now.size();k++){
					if(k != i && k != j){
						temp.push_back(now[k]);
					}
				}	
				vector<double> temp1 = temp;
				temp1.push_back(p + q);
				dfs(temp1);
				vector<double> temp2 = temp;
				temp2.push_back(p - q);
				dfs(temp2);
				vector<double> temp3 = temp;
				temp3.push_back(p * q);
				dfs(temp3);
				vector<double> temp4 = temp;
				if(q != 0){
					temp4.push_back(p / q);
					dfs(temp4);
				}
			}
		}
	}
}

int main(){
	int ans = 0;
	for(int a = 1;a < 10;a++){
		for(int b = a + 1;b < 10;b++){
			for(int c = b + 1;c < 10;c++){
				for(int d = c + 1;d < 10;d++){
					vector<double> now = vector<double>();
					now.push_back(a);
					now.push_back(b);
					now.push_back(c);
					now.push_back(d);
					s.clear();
					dfs(now);
					int pre = 0;
					for(auto x : s){
						if(x != pre + 1){
							if(pre == 51){
								cout << a << b << c << d << endl;
							}
							break;
						}else{
							pre = pre + 1;
						}
					}
				}
			}
		}
	}
	return 0;
}
