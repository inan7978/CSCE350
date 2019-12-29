// Inan Ismailov
#include <iostream>
#include <regex>
using namespace std;
bool isP(string a);
vector<string> v(string a);
vector<string> cutv;

vector<string> v(string a) {
  string b;
  string input;
  int mC = 0;
  int loc = 0;
  input = a;
  int aL = a.length();
  int inL = input.length();
  bool c;
  for (int i = 0; i < aL; i++){
    for (int j = aL; j > 0; j--){
    b = a.substr(i,j);
    c = isP(b);
    if (c) {
	b = b + "|";
    cutv.push_back(b);
    loc = loc + cutv[i].length() - 1;
    if (loc > (inL - 1)){
     break;
    }
    if (i == aL && j == aL){
     break;
    }
    if (aL > 1 && (i != aL - 1 && j != aL - 1)){
     a = a.substr(j-1, aL);
     j = aL;
    }
   i++;
  }
  }
   if (loc > (inL - 1)){
     break;
    }
  }
  int cutS = cutv.size();
  mC = cutS - 1;
  cout << mC << " ";
  for(int i = 0; i < cutS; i++)
    cout << cutv[i];
  cout << endl;
  return cutv;
}

bool isP(string a) {
  bool result = false;
  string b;
  if (a.length() == 1) {
    return true;
  }
  if (a.length() == 2) {
    if (a[0] == a[1]){
      return true;
  } else {
      return false;
    }
  }
  int tmp = a.length()-1;
    if (a[0] == a[tmp] && a.length() > 2) {
      result = isP(a.substr(1,(tmp - 1)));
    }
  return result;
}

int main (void) {
  string input;
  while (1){
  	cout << "Enter a word to be split into palindromes: ";
    getline(cin, input);
    v(input);
    cutv.clear();
    cout << endl;
  }
  return 0;
}
