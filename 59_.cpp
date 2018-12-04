#include <iostream>  
#include <fstream>  
#include <string>  
#include <vector>  
using namespace std;  
  
int main()  
{  
    ifstream input;  
    input.open("p059_cipher.txt");  
    string src;  
    input >> src;  
    vector<char> asc;  
    int a = 0;  
    for (int i = 0; i < src.length(); i++)  
    {  
        if (src[i] == ',')  
        {  
            asc.push_back(a);  
            a = 0;  
        }  
        else  
        {  
            int b = src[i] - '0';  
            a = a * 10 + b;  
        }  
    }  
    asc.push_back(a);  
    vector<char> msg = asc;  
	cout << asc.size() << endl;
    char key[3];  
    bool the = false, And = false, to = false;  
    int sum = 0;  
    for (int x = 'a'; x <= 'z'; x++)  
    {  
        for (int y = 'a'; y <= 'z'; y++)  
        {  
            for (int z = 'a'; z <= 'z'; z++)  
            {  
                key[0] = x;  
                key[1] = y;  
                key[2] =  z;  
  
                for (int i = 0; i < asc.size(); i++)  
                {  
                    msg[i] = asc[i] ^ key[i % 3];  
                    if (i >= 2)  
                    {  
                        the = (msg[i - 2] == 't'&&msg[i - 1] == 'h'&&msg[i] == 'e') || the;  
                        And = (msg[i - 2] == 'a'&&msg[i - 1] == 'n'&&msg[i] == 'd') || And;  
                        to = (msg[i - 1] == 't'&&msg[i] == 'o') || to;  
                    }  
                    sum += msg[i];  
                }  
                if (the&&And&&to)  
                {  
                    cout << sum << endl;  
                    for (int j = 0; j < msg.size(); j++)  
                        cout << msg[j];  
                    cout << endl;  
                }  
                the = false;  
                And = false;  
                to = false;  
                sum = 0;  
            }  
        }  
    }  
  
    return 0;  
}  
