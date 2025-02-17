#ifndef STR_H
#define STR_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void PrintFibonacciSequencerR(int length, int x = 0, int y = 1);
void PrintFirstLetter(string str);
string UpperCaseFirstLetter(string str);
string LowerCaseFirstLetter(string str);
string LowerAllString(string str);
string UpperAllString(string str);
char InvertLetterCase(char char1);
size_t _strlen(const std::string& s);
size_t uppercase_length(const std::string& s);
size_t lowercase_length(const std::string& str);
bool IsVowel(char c);
char ToLower(char c);
void PrintEachWordInString(std::string s);
int CountEachWordInString(std::string s);
std::vector<std::string> splitStringIntoVector(std::string s, std::string delim);
std::string TrimLeft(std::string s);
std::string TrimRight(std::string s);
std::string Trim(std::string s);
std::string JoinString(std::vector<string> v, string delim);
std::string JoinString(std::string arr[], short size, string delim);

#endif
