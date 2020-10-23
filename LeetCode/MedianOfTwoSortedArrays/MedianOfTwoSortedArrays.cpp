

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        uint16_t uiVector1Index = 0, uiVector2Index = 0;
        uint16_t uiNums1Size = nums1.size();
        uint16_t uiNums2Size = nums2.size();
        vector<int> mergedVectors;

        while (uiVector1Index < uiNums1Size && uiVector2Index < uiNums2Size)
        {
            if (nums1.at(uiVector1Index) < nums2.at(uiVector2Index))
            {
                mergedVectors.push_back(nums1.at(uiVector1Index++));
            }
            else if (nums1.at(uiVector1Index) == nums2.at(uiVector2Index))
            {
                mergedVectors.push_back(nums1.at(uiVector1Index++));
                mergedVectors.push_back(nums2.at(uiVector2Index++));
            }
            else
            {
                mergedVectors.push_back(nums2.at(uiVector2Index++));
            }
        }
        while (uiVector1Index < uiNums1Size)
        {
            mergedVectors.push_back(nums1.at(uiVector1Index++));
        }
        while (uiVector2Index < uiNums2Size)
        {
            mergedVectors.push_back(nums2.at(uiVector2Index++));
        }
        
        if (mergedVectors.size() % 2 == 0)
        {
            return (double)(mergedVectors.at(mergedVectors.size() / 2) + mergedVectors.at((mergedVectors.size() / 2) - 1)) / 2;
        }
        else
        {
            return mergedVectors.at(ceil(mergedVectors.size()) / 2);
        }
    }
};

int main()
{
    vector<int> input1 = { 1, 2 };
    vector<int> input2 = { 3, 4 };

    Solution test;
    double result = test.findMedianSortedArrays(input1, input2);

}


