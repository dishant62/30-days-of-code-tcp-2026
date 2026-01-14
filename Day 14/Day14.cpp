#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    string toBinary(int n){  
        string s="";  
        while(n>0){  
            char bit= (n%2)+'0';  
            s= bit + s;  
            n/=2;  
        }  
  
        return s;  
    }  

    int setBits(int n) {  
	  
        string a = toBinary(n);  
        int count=0;  

        for(int i=0; i<a.size(); i++){  
            if(a[i]-'0'==1){  
	            count++;  
            }  
        }  
  
        return count;  
      
    }

};
