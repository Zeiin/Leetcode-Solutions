#include <stdio.h> 
#include <stdlib.h> 
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int i, j, k;
        int lsize = mid - left + 1;
        int rsize = right - mid;
        vector<int> L;
        vector<int> R;
        for (i = 0; i < lsize; i++)
            L.push_back(arr[left + i]);
        for (j = 0; j < rsize; j++)
            R.push_back(arr[mid + 1 + j]);
        i = 0;
        j = 0;
        k = left;
        while (i < lsize && j < rsize) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < lsize) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < rsize) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        mergeSort(nums, 0, nums.size() - 1);
        int i = 0;
        int j = nums.size() - 1;
        while (i < nums.size() && j > -1) {
            if (nums[i] + nums[j] == target)
                return (vector<int> {i, j});
            else if (nums[i] + nums[j] > target)
                j--;
            else
                i++;
            if (i > j)
                break;
        }
        return (vector<int> {-1, -1});
    }
};

int main() {
    Solution TwoSum = Solution();
    vector<int> input{ 2,7,11,15 };
    vector<int> solution = TwoSum.twoSum(input, 9);
    cout << solution[0] << " " << solution[1];
    return 0;
}