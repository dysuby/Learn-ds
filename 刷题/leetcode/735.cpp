class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> s;
    int size = asteroids.size();
    if (!size) return asteroids;
    for (int i = 0; i < size; ++i) {
      if (s.empty()) {
        s.push_back(asteroids[i]);
        continue;
      }
      int top = s.back();
      if (top < 0) {
        s.push_back(asteroids[i]);
      } else {
        int old;
        while (top > 0) {
          if (asteroids[i] < 0 && -asteroids[i] >= top) {
            s.pop_back();
            old = top;
            if (s.empty() || top == -asteroids[i])
              break;
            else
              top = s.back();
          } else {
            if (asteroids[i] > 0) s.push_back(asteroids[i]);
            break;
          }
        }
        if ((s.empty() || top < 0) && -asteroids[i] > old)
          s.push_back(asteroids[i]);
      }
    }
    return s;
  }
};

// class Solution {
//  public:
//   vector<int> asteroidCollision(vector<int>& asteroids) {
//     vector<int> s;  // use vector to simulate stack.
//     vector<int>& a = asteroids;
//     for (int i = 0; i < a.size(); i++) {
//       if (a[i] > 0)  // a[i] is positive star
//         s.push_back(a[i]);
//       else if (s.empty() || s.back() < 0)  // a[i] is negative star and there is
//                                            // no positive on stack
//         s.push_back(a[i]);                 // negative star pass through
//       else if (s.back() <=
//                -a[i]) {  // a[i] is negative star and stack top is positive star
//         if (s.back() < -a[i])
//           i--;  // only positive star on stack top get destroyed, stay on i to
//                 // check more on stack.
//         s.pop_back();  // destroy positive star on the frontier;
//       }  // else : positive on stack bigger, negative star destroyed.
//     }
//     return s;
//   }
// };