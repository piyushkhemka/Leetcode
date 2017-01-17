class Twitter {

    unordered_map<int, vector<int> > followlist;
    deque<pair<int, int> > alltweets;


public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {

        alltweets.push_front ({userId, tweetId});

    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {

        vector<int> result;
        int count = 0;
        for(auto i : alltweets) {
            if ( (i.first == userId) ||
                ( (followlist.find(userId)!=followlist.end()) &&
                  find(followlist[userId].begin(), followlist[userId].end(), i.first) != followlist[userId].end())) {

                      result.push_back(i.second);
                      count++;

                      if (count >= 10)
                        break;

                  }
        }

        return result;

    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {

        if (followlist.find(followerId)!= followlist.end())
            followlist[followerId].push_back(followeeId);
        else {
            followlist.insert({followerId, vector<int> ()});
            followlist[followerId].push_back(followeeId);
        }

    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {

        if (followlist.find(followerId)!= followlist.end()) {

            auto it = find(followlist[followerId].begin(), followlist[followerId].end(), followeeId);

            if (it!= followlist[followerId].end()) {
                swap(*it, followlist[followerId].back());
                followlist[followerId].pop_back();
            }
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
