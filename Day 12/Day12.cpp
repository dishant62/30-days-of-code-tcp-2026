#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last  = -1;
        vector<int> temp;

        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                first = mid;
                r = mid - 1;   
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l = 0;
        r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                last = mid;
                l = mid + 1;   
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        temp.push_back(first);
        temp.push_back(last);

        return temp;
    }
};

int main(){
    vector<int> arr1={5,7,7,8,8,10};
    vector<int> arr2={5,7,7,8,8,10};
    vector<int> arr3={};
    Solution sol;
    
    vector<int> a1=sol.searchRange(arr1, 8);
    vector<int> a2=sol.searchRange(arr2, 6);
    vector<int> a3=sol.searchRange(arr3, 0);
    cout<<"arr1: ";
    for(int i=0;i<a1.size();i++){
        cout<<a1[i]<<' ';
    }
    cout<<endl;
    
    cout<<"arr2: ";
    for(int i=0; i<a2.size();i++){
        cout<<a2[i]<<' ';
    }
    cout<<endl;
    
    cout<<"arr3: ";
    for(int i=0; i<a3.size();i++){
        cout<<a3[i]<<' ';
    }
    
    
    return 0;
}
