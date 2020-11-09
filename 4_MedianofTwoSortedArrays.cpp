#include <stdio.h>
#include <vector>

using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

class Solution
{
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = static_cast<int>(nums1.size());
        int size2 = static_cast<int>(nums2.size());
        
        if (size1 == 1 && size2 == 1)
        {
            return (nums1[0] + nums2[0]) * 0.5;
        }
        else if (size1 == 0 && size2 == 0)
        {
            return 0.0;
        }
        else if (size1 == 0)
        {
            int half = size2 / 2;
            return size2 % 2 == 1 ? nums2[half] : (nums2[half - 1] + nums2[half]) * 0.5;
        }
        else if (size2 == 0)
        {
            int half = size1 / 2;
            return size1 % 2 == 1 ? nums1[half] : (nums1[half - 1] + nums1[half]) * 0.5;
        }
        
        if (size1 > size2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int lIndex = 0;
        int rIndex = size1;
        int length = size1 + size2;
        int index1 = 0;
        int index2 = 0;
        
        double result = 0.0f;
        
        while (lIndex <= rIndex)
        {
            index1 = lIndex + (rIndex - lIndex) / 2;
            index2 = (length + 1) / 2 - index1;
            
            const int l1 = index1 == 0     ? INT_MIN : nums1[index1 - 1];
            const int r1 = index1 == size1 ? INT_MAX : nums1[index1];
            const int l2 = index2 == 0     ? INT_MIN : nums2[index2 - 1];
            const int r2 = index2 == size2 ? INT_MAX : nums2[index2];
            
            if (l1 > r2)
            {
                rIndex = index1 - 1;
            }
            else if (l2 > r1)
            {
                lIndex = index1 + 1;
            }
            else
            {
                if (length % 2 != 0)
                {
                    result = max(l1, l2);
                }
                else
                {
                    result = (max(l1, l2) + min(r1, r2)) * 0.5;
                }
                
                break;
            }
        }
        
        return result;
    }
};

int main(int argc, char *argv[])
{
    {
        vector<int> nums1 = { };
        vector<int> nums2 = { 1 };

        Solution solution;
        double ret = solution.findMedianSortedArrays(nums1, nums2);
        printf("result = %f\n", ret);
    }

    {
        vector<int> nums1 = { 1 };
        vector<int> nums2 = { };

        Solution solution;
        double ret = solution.findMedianSortedArrays(nums1, nums2);
        printf("result = %f\n", ret);
    }

    {
        vector<int> nums1 = { 1 };
        vector<int> nums2 = { 2 };

        Solution solution;
        double ret = solution.findMedianSortedArrays(nums1, nums2);
        printf("result = %f\n", ret);
    }
    
    {
        vector<int> nums1 = { 1 };
        vector<int> nums2 = { 2, 3 };
        
        Solution solution;
        double ret = solution.findMedianSortedArrays(nums1, nums2);
        printf("result = %f\n", ret);
    }
    
    {
        vector<int> nums1 = { 1, 3 };
        vector<int> nums2 = { 2, 4 };
        
        Solution solution;
        double ret = solution.findMedianSortedArrays(nums1, nums2);
        printf("result = %f\n", ret);
    }
    
    {
        vector<int> nums1 = { 1, 3 };
        vector<int> nums2 = { 2, 4, 5 };
        
        Solution solution;
        double ret = solution.findMedianSortedArrays(nums1, nums2);
        printf("result = %f\n", ret);
    }
    
    return 0;
}
