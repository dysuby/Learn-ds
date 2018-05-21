#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Pflag = false, Lflag = false;
string head[7] = {"", "1", "2", "3", "4", "5", "6"};
vector<string> total;

void handle(string &str) {
  if (str.size() == 0) {
    if (Lflag) {
      total.push_back("</ul>");
      Lflag = false;
    }
    if (Pflag) {
      total[total.size() - 1] += "</p>";
      Pflag = false;
    }
    return;
  }
  if (str[0] == '#') {
    int temp = 1, index = 0;
    while (index < str.size() && str[++index] == '#')
      ++temp;
    while (index < str.size() && str[++index] == ' ')
      continue;
    str = "<h" + head[temp] + ">" + str.substr(index) + "</h" + head[temp] + ">";
    if (Lflag) {
      total.push_back("</ul>");
    }
    if (Pflag) {
      total[total.size() - 1] += "</p>";
      Pflag = false;
    }
  } else if (str[0] == '*') {
    if (Pflag) {
      total[total.size() - 1] += "</p>";
      Pflag = false;
    }
    if (Lflag == false) {
      total.push_back("<ul>");
      Lflag = true;
    }
    int index = 0;
    while (index < str.size() && str[++index] == ' ')
      continue;
    str = "<li>" + str.substr(index) + "</li>";
  } else if (Pflag == false) {
      if (Lflag) {
        total.push_back("</ul>");
        Lflag = false;
      }
      Pflag = true;
      str = "<p>" + str;
  }
  string link, href;
  for (int index = 0; index < str.size(); ++index) {
    if (str[index] == '[') {
      int begin = index;
      while (index < str.size() && str[++index] != ']')
        link.push_back(str[index]);
      ++index;
      while (index < str.size() && str[++index] != ')')
        href.push_back(str[index]);
      str = str.substr(0, begin) + "<a href=\"" + href + "\">" + link + "</a>" + str.substr(index + 1);
    }
    if (str[index] == '_') {
      string temp;
      int begin = index;
      while (index < str.size() && str[++index] != '_')
        temp.push_back(str[index]);
      str = str.substr(0, begin) + "<em>" + temp + "</em>" + str.substr(index + 1);
    }
  }
}

int main() {
  string str;
  while (getline(cin, str) && str != "-1") {
    handle(str);
    if (str.size())
      total.push_back(str);
  }
  if (Pflag) {
    total[total.size() - 1] += "</p>";
  }
  if (Lflag) {
    total.push_back("</ul>");
  }
  for (int i = 0; i < total.size(); ++i) {
    cout << total[i] << endl;
  }
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// const int MAX = 105;
// string strs[MAX];

// void output(string str)
// {
//   int len = str.length();
//   for (int i = 0; i < len; i++)
//   {
//     if (str[i] == '_')
//     {
//       int r = str.find('_', i + 1);
//       string tmp = "<em>" + str.substr(i + 1, r - i - 1) + "</em>";
//       output(tmp);
//       i = r;
//     }
//     else if (str[i] == '[')
//     {
//       int r = str.find(']', i + 1);
//       string text = str.substr(i + 1, r - i - 1);

//       int l = str.find('(', r + 1);
//       int linkr = str.find(')', r + 1);

//       string link = str.substr(l + 1, linkr - l - 1);
//       string tmp = "<a href=\"" + link + "\">" + text + "</a>";

//       output(tmp);

//       i = linkr;
//     }
//     else
//       printf("%c", str[i]);
//   }
// }

// void solve_h()
// {
//   int len = strs[0].length();

//   int pos = len, cnt = 0;
//   for (int i = 0; i < len; i++)
//   {
//     if (strs[0][i] == '#')
//       cnt++;
//     if (strs[0][i] != '#' && strs[0][i] != ' ')
//     {
//       pos = i;
//       break;
//     }
//   }

//   cout << "<h" << cnt << ">";
//   output(strs[0].substr(pos));
//   cout << "</h" << cnt << ">" << endl;
// }

// void solve_p(int cnt)
// {
//   cout << "<p>";
//   for (int i = 0; i < cnt; i++)
//   {
//     output(strs[i]);

//     if (i == cnt - 1)
//       cout << "</p>";

//     cout << endl;
//   }
// }

// void solve_l(int cnt)
// {
//   cout << "<ul>" << endl;

//   for (int i = 0; i < cnt; i++)
//   {
//     int len = strs[i].length();
//     int pos = len, cnt = 0;

//     for (int j = 1; j < len; j++)
//       if (strs[i][j] != ' ')
//       {
//         pos = j;
//         break;
//       }

//     cout << "<li>";
//     output(strs[i].substr(pos));
//     cout << "</li>" << endl;
//   }
//   cout << "</ul>" << endl;
// }

// int main()
// {
//   //freopen("in.txt","r",stdin);
//   std::string line;

//   int cnt = 0;
//   while (getline(std::cin, line))
//   {
//     if (line == "")
//     {
//       if (cnt == 0)
//         continue;

//       if (strs[0][0] == '#')
//         solve_h();
//       else if (strs[0][0] == '*')
//         solve_l(cnt);
//       else
//         solve_p(cnt);

//       cnt = 0;
//       continue;
//     }

//     strs[cnt++] = line;
//   }

//   if (cnt)
//   {
//     if (strs[0][0] == '#')
//       solve_h();
//     else if (strs[0][0] == '*')
//       solve_l(cnt);
//     else
//       solve_p(cnt);
//   }
//   return 0;
// }