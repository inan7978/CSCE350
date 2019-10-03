// Inan Ismailov
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <array>
#include <cmath>
#include <sstream>
using namespace std;
using std::cin;
using std::string;
using std::cout;
using std::endl;


int main(int argc, const char* argv[]){
while(1){
int num1;
int num2;
int num3;
int num4;
cin >> num1;
cin >> num2;
cin >> num3;
cin >> num4;
if (num1 == 0 && num2 == 0 && num3 == 0 && num4 == 0){
exit(0);
}
if (num1<0||num2<0||num3<0||num4<0){
exit(0);
}
int answer = num1+num2+num3+num4;
cout << answer << endl;
}
}