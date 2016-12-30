class Solution {
public:
    int compareVersion(string v1, string v2) {

        int n = v1.length();
        int m = v2.length();

        int i = 0;
        int j = 0;

        while(i<n || j<m) {

            string prev1 = "";
            string prev2 = "";


            while(i<n && v1[i]!='.')
                prev1 += v1[i++];


            while(j<m && v2[j]!='.')
                prev2 += v2[j++];

            int predec1 = 0;
            int predec2 = 0;

            if(!prev1.empty())
                predec1 = stoi(prev1);

            if(!prev2.empty())
                predec2 = stoi(prev2);

            if (predec1 > predec2)
                return 1;
            else if (predec1 < predec2)
                return -1;

            i++;
            j++;

        }

        return 0;

    }

};
