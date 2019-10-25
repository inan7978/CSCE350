// Inan Ismailov
// I wasnt sure what you meant by end of file on the stadard input so I made it keep going until '&' is entered.
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <array>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using std::cin;
using std::string;
using std::cout;
using std::endl;

bool allUnique (string num){
	int c0 = 0;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	int c5 = 0; 
	int c6 = 0; 
	int c7 = 0;
	int c8 = 0;
	int c9 = 0;

 for (int i = 0;i < num.size(); ++i){
 	if (num.at(i) == '0'){
 		++c0;
 	}
 	if (num.at(i) == '1'){
 		++c1;
 	}
 	if (num.at(i) == '2'){
 		++c2;
 	}
 	if (num.at(i) == '3'){
 		++c3;
 	}
 	if (num.at(i) == '4'){
 		++c4;
 	}
 	if (num.at(i) == '5'){
 		++c5;
 	}
 	if (num.at(i) == '6'){
 		++c6;
 	}
 	if (num.at(i) == '7'){
 		++c7;
 	}
 	if (num.at(i) == '8'){
 		++c8;
 	}
 	if (num.at(i) == '9'){
 		++c9;
 	}
 	
 }
 if (c0 > 1 || c1 > 1 || c2 > 1 || c3 > 1 || c4 > 1 || c5 > 1 || c6 > 1 || c7 > 1 || c8 > 1 || c9 > 1){
 	return false;
 }else {
 	return true;
 }


}
string helper(int a){ // return a string with every possible combo for that size with all 10 individual digits.
	string out;
	string tempM = "";
	string tempD = "";
for (int i = 0; i < a; ++i){
tempD = tempD + to_string(i);
tempM = tempM + '9';
}
	string s = tempD;
    stringstream geek(s); 
	int tD = 0; 
    geek >> tD; 
  	//cout << "Value of tD : " << tD << endl;

  	string d = tempM;
    stringstream geek1(d); 
	long tM = 0; 
    geek1 >> tM; 
  	//cout << "Value of tM : " << tM << endl;
//cout << tempM << endl;
//cout << tempD << endl;
    string tmp;
for (long i = tM; i >= tD; --i){
	if (to_string(i).size() != tempD.size()){
		tmp = "0" + to_string(i);
		if (allUnique(tmp)){
			out = out + tmp + '\n';
			tmp = "";
		}
	} else {
		tmp = to_string(i);
		if(allUnique(tmp)){
			out = out + tmp + '\n';
			tmp = "";
	}
		
	}
	}
	return out;
}


int main(void){
	while(1){
	cout << "Enter the crpytarithemic problem. If done, enter &. " << endl;
string input;
string beforePlus;
string afterPlus;
string afterEq;
vector<char> values;
int plusLoc;
int equalLoc;
int change;
cin >> input;
if (input == "&"){
	exit(0);
}

int counter = 0;
for (int i = 0; i < input.size(); ++i){ // Populates which characters are present in input.
for(int v = 0; v < values.size(); ++v){
if (input.at(i) == values[v]){
			++counter;
		}
}
if (counter == 0){
		if((input.at(i) == '=') || (input.at(i) == '+')){
			counter == 0;
		} else {
		values.push_back(input.at(i));
		counter = 0;}
	} else {
		counter = 0;
	}
}
// for (int i = 0; i < values.size(); ++i){  // uncomment to see the values
// 	cout << values.at(i) << endl;
// }

string output = helper(values.size());
string line2;
string buf;
istringstream ff(output);
int counter2 = 0;

while(getline(ff, line2)){ // values and line2 will be using the same index in assigning.
	string buf = line2;
	string newOne = input;
	for (int i = 0; i < values.size(); ++i){
		for (int j = 0; j < input.size(); ++j) {
	if (values[i] == newOne[j]){
		newOne[j] = buf.at(i);
		}
	}
}
plusLoc = newOne.find('+');
equalLoc = newOne.find('=');
beforePlus = newOne.substr(0,plusLoc);
change = equalLoc - plusLoc - 1;
afterPlus = newOne.substr((plusLoc+1), change );
afterEq = newOne.substr((equalLoc+1), (input.size()-1));
if (stoi(beforePlus) + stoi(afterPlus) == stoi(afterEq)){
	if (beforePlus.at(0) != '0' && afterPlus.at(0) != '0' && afterEq.at(0) != '0'){
		cout << beforePlus << "  +  " << afterPlus << " = " << afterEq << endl;
		++counter2;
	}
}
}
if (counter2 == 0){
	cout << "No solution" << endl;
	cout << endl;
}
}
}