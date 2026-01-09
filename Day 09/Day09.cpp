#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size()-1; i >= 0; i--){
            if((num[i] - '0') % 2 == 1) {   
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};

int main(){
    string a="52";
    string b="4206";
    string c="35427";
    
    Solution sol;
    cout<<"string a: "<<sol.largestOddNumber(a)<<endl;
    cout<<"string b: "<<sol.largestOddNumber(b)<<endl;
    cout<<"string c: "<<sol.largestOddNumber(c)<<endl;
    
    return 0;
}

