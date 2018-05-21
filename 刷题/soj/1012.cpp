double mean(map<int, double> p) {
  double ans = 0;
  for (auto fuck = p.begin(); fuck != p.end(); ++fuck)
    ans += fuck->first * fuck->second;
  return ans;
}