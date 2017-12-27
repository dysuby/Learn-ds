#include <list>
#include <map>
using namespace std;

list<T> getMode(list<T> ls) {
  int max = 0;
  map<T, int> fuck;
  list<T> ans;
  for (auto i = ls.begin(); i != ls.end(); ++i) {
    if (fuck.find(*i) != fuck.end())
      ++fuck[*i];
    else
      fuck[*i] = 1;
    max = max > fuck[*i] ? max : fuck[*i];
  }
  for (auto i = fuck.begin(); i != fuck.end(); ++i)
    if (max == (*i).second)
      ans.push_back((*i).first);
  return ans;
}

// returns the list of  modes for ls, and the order doesn't matter.
