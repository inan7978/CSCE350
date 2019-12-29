// Inan Ismailov
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

int ctoi(char d){ // works
	if (d == '1'){
		return 1;
	}
	if (d == '2'){
		return 2;
	}
	if (d == '3'){
		return 3;
	}
	if (d == '4'){
		return 4;
	}
	if (d == '5'){
		return 5;
	}
	if (d == '6'){
		return 6;
	}
	if (d == '7'){
		return 7;
	}
	if (d == '8'){
		return 8;
	}
	if (d == '9'){
		return 9;
	}
return 0;
}

char itoc(int d){ // works
	if (d == 1){
		return '1';
	}
	if (d == 2){
		return '2';
	}
	if (d == 3){
		return '3';
	}
	if (d == 4){
		return '4';
	}
	if (d == 5){
		return '5';
	}
	if (d == 6){
		return '6';
	}
	if (d == 7){
		return '7';
	}
	if (d == 8){
		return '8';
	}
	if (d == 9){
		return '9';
	}
	if (d == 0){
		return '0';
	}
	return '0';
}

bool isPowerOfTwo(long n) { // found the idea online and implemented it
   if(n == 0){
   return false; 
  }
   return (ceil(log2(n)) == floor(log2(n))); 
} 

string zTrim(string a){ //works trims excess zeros from the front
	if (a[0] != '0'){
		return a;
	}
	int countA = 0;
	for (int i = 0; i < a.size(); ++i){
		if (a[i] == '0'){
			++countA;
		}
	}
	if (countA == a.size()){
		return "0";
	}
int count = 0;
	string tmpp;
	string result;
while(a[count] == '0'){
	++count;
}
int again = (a.size() - count);
tmpp = a.substr((count), again);
result = tmpp;
return result;
}

bool longerS(string a,string b){ // if first arg is longer than
if (a.length() > b.length()){        // second arg return true, else false. works
return true;
	} else {
		return false;
	}
}

bool largerThan(string t, string e){ // if the first argument is 
	string a = zTrim(t); 			 //larger than the second one it returns true. works
	string b = zTrim(e);
	if (longerS(a,b)){
		return true;
	}
	if (a.length() == b.length()){
		for (int i = 0; i < a.length(); ++i){
			if (ctoi(a[i]) > ctoi(b[i]))
				return true;
		}
	}
	return false;
}

string toPower(string a, long long n){ // does the power calculation
	if (n == 0){
		return "1";
	} else {
		for (int i = 0; i < n - 1; ++i){
			a = a + "0";
		}
	}
	return a;
}

string padded (string a, long long n){ // takes the string in and pads with zeros until it is n long. works
	reverse(a.begin(), a.end());
	while (a.length() < n){
		a = a + "0";
	}
	reverse(a.begin(), a.end());
	return a;
}

string sumOf(string a,string b){ // add the two arguments together. works.
	if (a.length() < 5 && b.length() < 5){
		return to_string(stoi(a) + stoi(b));
	}
	a = zTrim(a);
	b = zTrim(b);
	string result;
	int carry = 0;
	int buffer = 0;
	string last2;
	if (a.length() > b.length()){
		b = padded(b,a.length());
	} else if (a.length() < b.length()){  // this section makes sure the numbers are made the same size if they arent already
		a = padded(a,b.length());
	}
	for (int i = a.size() - 1; i != -1; --i){
		buffer = ctoi(a[i]) + ctoi(b[i]) + carry;
		if (i == 0){
			last2 = to_string(buffer);
			//Inan Ismailov
			reverse(last2.begin(),last2.end());
			result = result + last2;
		} else {
			result = result + itoc(buffer % 10);
			carry = (buffer/10);
	}
}
reverse(result.begin(),result.end());
return result;
}

string diffOf(string a,string b){ // finds difference of arguments make sure the larger number goes first...
	string result = "";              // what a pain in the ass this method was
    int n1 = a.length();
    int n2 = b.length(); 
    int diff = n1 - n2; 
    int carry = 0; 
  	for (int i = n2 - 1; i >= 0; i--){ 
    int sub = ((a[i + diff] - '0') - (b[i] - '0') - carry); 
        if (sub < 0){ 
            sub = sub + 10; 
            carry = 1; 
        } else {
            carry = 0; 
        }
  		result.push_back(sub + '0'); 
    } 
    for (int i = n1 - n2 - 1; i >= 0; i--){ 
        if (a[i] == '0' && carry){ 
            result.push_back('9'); 
            continue; 
        } 
        int sub = ((a[i] - '0') - carry); 
        if (i > 0 || sub > 0){
            result.push_back(sub + '0'); 
        }
        carry = 0; 
  	} 
    reverse(result.begin(), result.end()); 
  	result = zTrim(result);
    return result; 
	}

string pencilAlg(string t,string e){ //pencil method. Used in the karatsuba version

string ans = "Error";
string a = zTrim(t);
string b = zTrim(e);
if (a == "0" || b == "0"){
	return "0";
}

if (a.size() < 5 && b.size() < 5){
	return to_string(stoi(a)*stoi(b));
}
string tmp;
string tran;
string mTemp;
long counting = 0;
int buff;
int next = 0;
vector<char> flip;
vector<string> contents;
for (long j = b.size() - 1; j != -1; --j){
	for (long i = a.size() - 1; i != -1; --i){
		buff = ctoi(a[i]) * ctoi(b[j]);
		//0I0n0a0n0 0I0s0m0a0i0l0o0v0
		if(i == 0){
			mTemp = to_string(buff + next);
			if (mTemp.size() > 1){
			swap(mTemp[1],mTemp[0]);
			tmp = tmp + mTemp;
		} else {
			tmp = tmp + mTemp;
		}
		} else {
			tmp = tmp + to_string((buff + next) % 10);
			if ((buff + next) < 10){
				next = 0;
			} else {
				tran = to_string(buff + next);
			next = ctoi(tran[0]);
		}
	  }
	}
	reverse(tmp.begin(), tmp.end());
for (int i = 0; i < counting; ++i){
	tmp = tmp + "0";
}
contents.push_back(tmp);
next = 0;
tmp = "";
++counting;
}
ans = "";
for (int i = 0; i < contents.size(); i++){
	ans = sumOf(contents[i], ans);
}
	return ans;
}

string karatsuba(string i,string j){
string a = i;
string b = j;
	if (a.length() < 5 && b.length() < 5){
		return to_string(stoi(a)*stoi(b));
	}
if (a.length() > b.length()){ //makes the two argumens a length of the next 2^n
	reverse(a.begin(),a.end());// there are three versions for the three different possible cases
	while(!isPowerOfTwo(a.length())){
		a = a + '0';
	}
	reverse(a.begin(),a.end());
	b = padded(b, a.length());
}
if (b.length() > a.length()){
	reverse(b.begin(),b.end());
	while(!isPowerOfTwo(b.length())){
		b = b + '0';
	}
	reverse(b.begin(), b.end());
	a = padded(a, b.length());
}
if (a.length() == b.length()){
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while(!isPowerOfTwo(a.length())){
		a = a + '0';
		b = b + '0';
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
}
int m = a.size()/2;
string a0 = a.substr(m,m);
string a1 = a.substr(0,m);
string b0 = b.substr(m,m);
string b1 = b.substr(0,m);
//Inan Ismailov
string c2 = karatsuba(a1,b1);
string c0 = karatsuba(a0,b0);
//////// below are helper variables to help with calculating the result
string c1h1 = sumOf(a1,a0);
string c1h2 = sumOf(b1,b0);
string c1h3 = sumOf(c2,c0);
string c1 = diffOf(karatsuba(c1h1,c1h2), c1h3);
string r1h1 = toPower("10", (2*m));
string r1h2 = pencilAlg(r1h1, c2);
string r1h3 = toPower("10", m);
string r1h4 = pencilAlg(r1h3,c1);
string r1h5 = sumOf(r1h2,r1h4);
	return sumOf(r1h5,c0);
}

int main(void)
{
	while(1){
string inputed;
cout << "Enter the equation: ";
cin >> inputed;
istringstream ff(inputed);
string tmp;
string a;
string b;
int count = 0;
while(getline(ff, tmp, '*')){
  if (count == 0){
a = tmp;
++count;
  } else {
b = tmp;
  }
}
cout << "B: " << pencilAlg(a,b) << endl;
cout << "K: " << karatsuba(a,b) << endl;
}
return 0;
}