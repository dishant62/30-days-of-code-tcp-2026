#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (int num : nums) {
            s.insert(num);
        }

        int longest = 0;

        for (int num : s) {
            if (s.count(num - 1) == 0) {
                int current = num;
                int length = 1;

                while (s.count(current + 1)) {
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }

        return longest;
    }
};

int main(){
    vector<int> arr1={100,4,200,1,3,2};
    vector<int> arr2={0,3,7,2,5,8,4,6,0,1};
    vector<int> arr3={1,0,1,2};
    
    Solution sol;
    cout<<"For arr1: "<<sol.longestConsecutive(arr1)<<endl;
    cout<<"For arr2: "<<sol.longestConsecutive(arr2)<<endl;
    cout<<"For arr3: "<<sol.longestConsecutive(arr3)<<endl;
    
    return 0;
}    
