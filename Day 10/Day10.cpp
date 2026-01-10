#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int l= arr.size();
        int front=0;
        int back = l-1, i=0;
        
        while(i<=back){
            if(arr[i]==0){
                swap(arr[i],arr[front]);
                front++;
                i++;
            }else if(arr[i]==2){
                swap(arr[i],arr[back]);
                back--;
            }else {
                i++;
            }
        }
    }
};

int main(){
    vector<int> arr1={0,1,2,0,1,2};
    vector<int> arr2={0,1,1,0,1,2,1,2,0,0,0,1};
    
    Solution sol;
    sol.sort012(arr1);
    sol.sort012(arr2);
    
    cout<<"arr1: ";
    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<' ';
    }
    cout<<endl;
    
    cout<<"arr2: ";
    for(int i=0; i<arr2.size();i++){
        cout<<arr2[i]<<' ';
    }
    
    
    return 0;
}
