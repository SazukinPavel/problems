
#include "iostream"
#include "vector"
#include <algorithm>
#include <bits/stdc++.h>
#include <list>
#include <map>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

struct Post {
public:
  int owner_id;
  int id;
  int priritet;
  Post(int owner_id, int id, int priritet) {
    this->id = id;
    this->owner_id = owner_id;
    this->priritet = priritet;
  }
  bool operator>(const Post &str) const { return (priritet > str.priritet); }
};

struct PostHitory {
public:
  list<Post *> *history;
  PostHitory() { history = new list<Post *>(); }
};

struct User {
public:
  int id;
  set<int> followed_ids;

  User(int id) {
    this->id = id;
    followed_ids.insert(id);
  }
};

class Twitter {
private:
  map<int, User *> users;
  map<int, PostHitory *> tweets;
  int prioretet{0};

public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    this->createUserIfNotExist(userId);

    if (this->tweets[userId] == nullptr) {
      this->tweets[userId] = new PostHitory();
    }

    this->addPost(userId, tweetId);
  }

  vector<Post *> getNewsFeed(int userId) {
    this->createUserIfNotExist(userId);

    vector<Post *> news{};

    auto followeeIds = this->users[userId]->followed_ids;

    for (auto id : followeeIds) {
      if (tweets[id] == nullptr || tweets[id]->history == nullptr) {
        continue;
      }

      for (const auto &tweet : *tweets[id]->history) {
        news.push_back(tweet);
      }
    }

    std::sort(news.begin(), news.end(), greater<Post *>());

    return news;
  }

  void follow(int followerId, int followeeId) {
    this->createUserIfNotExist(followeeId);
    this->createUserIfNotExist(followerId);
    this->users[followerId]->followed_ids.insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    this->createUserIfNotExist(followeeId);
    this->createUserIfNotExist(followerId);
    this->users[followerId]->followed_ids.erase(followeeId);
  }

private:
  void addPost(int userId, int tweetId) {
    this->tweets[userId]->history->push_front(
        new Post(userId, tweetId, this->prioretet));

    prioretet++;
  }
  void createUserIfNotExist(int userId) {
    if (this->users.find(userId) == this->users.end()) {
      this->users[userId] = new User(userId);
    }
  }
};

int main() {
  Twitter *tweeter = new Twitter();
  cout << " post tweet [1,5]"
       << "\n";
  tweeter->postTweet(1, 5);
  cout << " post tweet [1,6]"
       << "\n";
  tweeter->postTweet(1, 6);
  cout << " post tweet [1,7]"
       << "\n";
  tweeter->postTweet(1, 7);
  auto tweets = tweeter->getNewsFeed(1);
  cout << "Tweets user 1:\n";
  for (auto tweet : tweets) {
    cout << tweet->id << "\t";
  }
  cout << "\npost tweet [2,10]"
       << "\n";
  tweeter->postTweet(2, 10);
  cout << " post tweet [2,8]"
       << "\n";
  tweeter->postTweet(2, 8);
  cout << " post tweet [2,9]"
       << "\n";
  tweeter->postTweet(2, 9);
  cout << "Tweets user 2:\n";
  tweets = tweeter->getNewsFeed(2);
  for (auto tweet : tweets) {
    cout << tweet->id << "\t";
  }
  cout << " follow [1,2]"
       << "\n";
  tweeter->follow(1, 2);
  cout << "Tweets user 1:\n";
  tweets = tweeter->getNewsFeed(1);
  for (auto tweet : tweets) {
    cout << tweet->id << "\t";
  }
  cout << " unfollow [1,2]"
       << "\n";
  tweeter->unfollow(1, 2);
  cout << "Tweets user 1:\n";
  tweets = tweeter->getNewsFeed(1);
  for (auto tweet : tweets) {
    cout << tweet->id << "\t";
  }
}