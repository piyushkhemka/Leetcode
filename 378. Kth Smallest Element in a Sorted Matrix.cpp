class Solution {
public:

struct mycomp {
    bool operator() (pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b) {
        return a.first > b.first;
    }
};

    int kthSmallest(vector<vector<int>>& matrix, int k) {

        priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int>> >, mycomp > pq;
        int n = matrix.size();
        for(int i = 0;i<n;i++){
            pq.push({matrix[0][i],{0,i}});
        }

        int i,j,val;
        while(k && !pq.empty()) {

             j = pq.top().second.second;
             i = pq.top().second.first;
             val = pq.top().first;
            pq.pop();
            k--;
            i++;

            if(i < n)
                pq.push({matrix[i][j],{i,j}});



        }
        return val;

    }
};
