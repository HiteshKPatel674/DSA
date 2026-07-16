class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        int total = n + m;

        int target1 = (total - 1) / 2;
        int target2 = total / 2;

        int i = 0, j = 0;
        int index = 0;

        int prev = 0, curr = 0;

        while (i < n || j < m) {

            prev = curr;

            if (j == m || (i < n && nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            }
            else {
                curr = nums2[j++];
            }

            if (index == target2)
                break;

            index++;
        }

        if (total % 2 == 1)
            return curr;

        return (prev + curr) / 2.0;
    }
};