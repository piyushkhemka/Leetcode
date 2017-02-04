class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int k;
        int i = m+n-1;
        int j = 0;

        for(k = m-1; k>=0; --k) {
            nums1[i--] = nums1[k];
        }

        k = 0;
        i = n;

        while(i<m+n && j<n) {

            if (nums1[i] < nums2[j])
                nums1[k++] = nums1[i++];

            else
                nums1[k++] = nums2[j++];

        }

        while(i<m+n)
            nums1[k++] = nums1[i++];

        while(j<n)
          nums1[k++] = nums2[j++];

    }
};
