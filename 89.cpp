#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string s;
void replace(string a,string b){
    int pos;
    while((pos = (int)s.find(a)) != string::npos){
        s.replace(pos,a.length(),b);
    }
}

int main(){
	freopen("p089_roman.txt","r",stdin);
    int res = 0;
    while(cin >> s){
        res += s.length();
        int pos;
        replace("IIII","IV");
        replace("XXXX","XL");
        replace("CCCC","CD");
        replace("VIV","IX");
        replace("LXL","XC");
        replace("DCD","CM");
        res -= s.length();
    }
	cout << res << endl;
    return 0;
}
