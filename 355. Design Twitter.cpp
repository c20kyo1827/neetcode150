class Twitter {
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        userToTimeAndTweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        std::vector<int> res;
        std::priority_queue<std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            greater<std::pair<int, int>>> top10;
        for (auto id : userTofollwers[userId]) {
            for (auto timeAndTweets : userToTimeAndTweets[id]) {
                if (top10.size() > 0 && top10.top().first > timeAndTweets.first && top10.size() > 10)
                    break;
                top10.push(timeAndTweets);
                if (top10.size() > 10)
                    top10.pop();
            }
        }
        while (!top10.empty()) {
            res.insert(res.begin(), top10.top().second);
            top10.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        userTofollwers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userTofollwers[followerId].erase(followeeId);
    }
    int time;
    std::unordered_map<int, std::unordered_set<int>> userTofollwers;
    std::unordered_map<int, std::vector<std::pair<int, int>>> userToTimeAndTweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
