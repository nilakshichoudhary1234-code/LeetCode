class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Last element in nums1's initial part
        int j = n - 1;      // Last element in nums2
        int k = m + n - 1;  // Last position in nums1 total capacity

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If nums2 still has elements, copy them. 
        // If nums1 has elements left, they're already where they need to be.
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        
    }
};