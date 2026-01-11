#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    void merge(vector<int>& arr,int l,int mid, int r){
        vector<int> temp;
        int left= l;
        int right= mid+1;
        
        while(left<=mid && right<=r){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
            
        while(right<=r){
            temp.push_back(arr[right]);
            right++;
        }
            
        for(int i=l; i<=r; i++){
            arr[i]= temp[i-l];
        }
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l>=r){
            return;
        }
        int mid = (l+r)/2;
        mergeSort(arr,l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr,l,mid,r);
    }
};

int main(){
    vector<int> arr1={4, 1, 3, 9, 7};
    vector<int> arr2={10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    Solution sol;
    sol.mergeSort(arr1,0,4);
    sol.mergeSort(arr2,0,9);
    
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
