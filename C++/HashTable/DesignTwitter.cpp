// https://leetcode.com/problems/design-twitter/


class Twitter {
private:
    unordered_map<int, unordered_set<int>> fo;
    vector<pair<int, int>> tweets;

public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        fo[userId].insert(userId);
        vector<int> res;
        int count = 0, n = tweets.size(), x, y;
        for (int i = n - 1; i >= 0; i --) {
            x = tweets[i].first;
            y = tweets[i].second;
            if (fo[userId].find(x) != fo[userId].cend()) {
                res.push_back(y);
                count++;
            }
            if (count == 10) break;
        }
        return res;

    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        fo[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
