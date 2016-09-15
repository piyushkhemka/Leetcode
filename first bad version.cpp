// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 0;
        int j = n;
        while(i<j) {
            int mid = i+(j-i)/2;
            if(isBadVersion(mid) && mid == 0 ) {
                return mid;
            }
            else if(isBadVersion(mid) && !isBadVersion(mid-1)) {
                return mid;
            }
            else if(isBadVersion(mid)) {
                j = mid;
            }
            else {
                i = mid+1;
            }
        }
        return i;
    }
};
