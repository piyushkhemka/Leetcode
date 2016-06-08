class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict){
        dict.insert(end);
        dict.insert(start);
        int count = 1;
        queue<string> q;
        q.push(start);
        string source = start;
       while(!q.empty()) {
           int n = q.size(); 
           for(int i = 0;i<n;i++) {
               string top = q.front();
               q.pop();
               if(top == end) {
                   return count;
               }
               processwords(top,end,dict,q);
           }
           count++;
       }
        return 0;
   
    }
    
    void processwords(string source, string end, unordered_set<string> &dict, queue<string> &q ) {
        
        dict.erase(source);
        int n = source.length();
        for(int i = 0;i<n;i++) {
            char p = source[i];
            for(int j = 0 ;j<=26;j++) {
                source[i] = 'a' + j;
                if(dict.find(source)!=dict.end())
                    q.push(source);
                    dict.erase(source);
            }
            source[i] = p;
        }
    }
};