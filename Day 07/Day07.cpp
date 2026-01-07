#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
    int largestNum(int a){    //function to create a new number with largest digits only
        int x=a;
        int l=0;
        int newNum= 0;
        while (x) {
            int r = x%10;
            if(r>l)
                l=r;
            x=x/10;   
        }
        x=a;
        int place= 1;
        while (x){
            newNum= newNum+l * place;
            place= place *10;
            x=x/10;
        }
        return newNum;
    }

    int sumOfEncintryptedInt(vector<int>& nums){
        int l= nums.size();
        int sum=0;
        //replace every number with new number and calculate sum
        for(int i =0; i<l;i++){
            nums[i]=largestNum(nums[i]);
            sum= sum + nums[i];
        }
        return sum;
    }   
};

int main(){
    vector<int> arr1={1,2,3};
    vector<int> arr2={10,21,31};
    
    Solution sol;
    cout<<"sum of arr1: " <<sol.sumOfEncintryptedInt(arr1)<<endl;
    cout<<"sum of arr2: " <<sol.sumOfEncintryptedInt(arr2);
    
    return 0;
}    
