#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int maximm(vector<int>& arr){
        int largest = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]>largest){
                largest = arr[i];
            }
        }
        return largest;
    }
    
    int totalHour(vector<int>& arr, int hourly, int h){
        int totalH = 0;
        for(int i = 0; i < arr.size(); i++){
            totalH += (arr[i] - 1) / hourly + 1;

            if(totalH > h)
                return totalH;
        }
        return totalH;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high =maximm(piles);
        int mid= low+ (high-low)/2;
        
        while(low<=high){
            int mid= low+ (high-low)/2;
            int totalH= totalHour(piles,mid,h);
            if(totalH<= h){
                high=mid -1;
            } else{
                low = mid+1;
            }
        }
        return low;
    }
};

int main(){
    vector<int> arr1={3,6,7,11};
    vector<int> arr2={30,11,23,4,20};
    vector<int> arr3={30,11,23,4,20};
    Solution sol;
    
    cout<<"Min rate for arr1: "<<sol.minEatingSpeed(arr1,8)<<endl;
    cout<<"Min rate for arr2: "<<sol.minEatingSpeed(arr2,5)<<endl;
    cout<<"Min rate for arr3: "<<sol.minEatingSpeed(arr3,6);
    return 0;
}
