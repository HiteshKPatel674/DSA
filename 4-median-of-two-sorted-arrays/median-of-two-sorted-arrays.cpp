class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        int total = n + m;
        int target = total / 2;

        int prev = 0, curr = 0;
        int counter = 0;

        int i = 0, j = 0;

        while (i < n || j < m) {

            prev = curr;

            if (j == m || (i < n && nums1[i] <= nums2[j])) {
                curr = nums1[i++];
            }
            else {
                curr = nums2[j++];
            }

            if (counter == target)
                break;

            counter++;
        }

        if (total % 2)
            return curr;

        return (prev + curr) / 2.0;
    }
};