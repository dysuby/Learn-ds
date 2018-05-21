class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<string> q;
    unordered_set<string> wordset(wordList.begin(), wordList.end());
    int ans = 0;
    q.push(beginWord);
    while (q.size()) {
      for (int i = q.size(); i > 0; --i) {
        string word = q.front();
        q.pop();
        // cout << word << endl;
        if (word == endWord) return ++ans;
        if (wordset.empty()) continue;
        int size = word.size();
        for (int i = 0; i < size; ++i) {
          char p = word[i];
          for (char j = 'a'; j <= 'z'; ++j) {
            word[i] = j;
            auto ite = wordset.find(word);
            if (ite != wordList.end()) {
              q.push(word);
              wordset.erase(ite);
            }
          }
          word[i] = p;
        }
      }
      ++ans;
    }
    return 0;
  }
};