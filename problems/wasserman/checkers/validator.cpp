#include <set>
#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include "testlib.h"
using namespace std;

// Checks whether the strings are composed by only a-z and A-Z characters.
bool checkString(const string &s, bool allowSpaces) {
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == ' ') {
      if(!allowSpaces) return false;
      continue;
    }

    if(s[i] >= 'a' && s[i] <= 'z') continue;
    if(s[i] >= 'A' && s[i] <= 'Z') continue;
    return false;
  }
  return true;
}


int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int n = inf.readInt(1, 50000);
  inf.readEoln();

  set<string> dict_keys;
  for(int i = 0; i < n; i++) {
    string s, t;
    s = inf.readString();
    t = inf.readLine();

    dict_keys.insert(s);

    // Ensuring sizes are correct.
    ensure(s.size() > 0 && s.size() <= 50);
    ensure(t.size() > 0 && t.size() <= 100);
  
    // Ensuring the strings are composed by only a-z and A-Z.
    ensure(checkString(s, false));
    ensure(checkString(t, true));
  }
  
  // Ensuring all the dictionary keys are distinct.
  ensuref(dict_keys.size() == n, "Dictionary keys are not unique.");

  string last_line = inf.readString();
  ensure(last_line.size() > 0 && last_line.size() <= 1000000);
  inf.readEof();

  return 0;
}
