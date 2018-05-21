bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first > b.first)
    return true;
  else if (a.first == b.first && a.second < b.second)
    return true;
  return false;
}
class Solution {
 public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
    if (people.size() <= 1) return people;
    sort(people.begin(), people.end(), cmp);
    int max = people[0].first;
    auto i = people.begin();
    while ((++i)->first == max) {
    }
    vector<pair<int, int>> ans(people.begin(), i);
    for (; i != people.end(); ++i) ans.insert(ans.begin() + i->second, *i);
    return ans;
  }
};