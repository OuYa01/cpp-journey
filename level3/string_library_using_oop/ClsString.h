#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class clsString {
private:
    string _s;

    // Helper functions
    static char ToLower(char c) {
        return (c >= 'A' && c <= 'Z') ? c + 32 : c;
    }

    static char ToUpper(char c) {
        return (c >= 'a' && c <= 'z') ? c - 32 : c;
    }

    static bool IsVowel(char c) {
        c = ToLower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

public:
    // Constructors
    clsString() : _s("") {}
    clsString(string s) : _s(s) {}

    // Setters and Getters
    void SetValue(string s) { _s = s; }
    string GetValue() const { return _s; }

    // Length and Count Functions
    static size_t Length(const string& s) {
        size_t len = 0;
        for (char i : s) len++;
        return len;
    }

    size_t Length() const {
        return Length(_s);
    }

    static size_t CountUppercase(const string& s) {
        size_t count = 0;
        for (char i : s)
            if (i >= 'A' && i <= 'Z') count++;
        return count;
    }

    size_t CountUppercase() const {
        return CountUppercase(_s);
    }

    static size_t CountLowercase(const string& s) {
        size_t count = 0;
        for (char i : s)
            if (i >= 'a' && i <= 'z') count++;
        return count;
    }

    size_t CountLowercase() const {
        return CountLowercase(_s);
    }

    // Case Manipulation
    static string UpperFirstLetter(const string& s) {
        string result = s;
        if (result.empty()) return result;

        if (result[0] != ' ' && result[0] >= 'a' && result[0] <= 'z')
            result[0] -= 32;

        for (size_t i = 1; i < result.length(); i++) {
            if (result[i-1] == ' ' && result[i] != ' ' && result[i] >= 'a' && result[i] <= 'z')
                result[i] -= 32;
        }
        return result;
    }

    string UpperFirstLetter() const {
        return UpperFirstLetter(_s);
    }

    static string LowerFirstLetter(const string& s) {
        string result = s;
        if (result.empty()) return result;

        if (result[0] != ' ' && result[0] >= 'A' && result[0] <= 'Z')
            result[0] += 32;

        for (size_t i = 1; i < result.length(); i++) {
            if (result[i-1] == ' ' && result[i] != ' ' && result[i] >= 'A' && result[i] <= 'Z')
                result[i] += 32;
        }
        return result;
    }

    string LowerFirstLetter() const {
        return LowerFirstLetter(_s);
    }

    static string UpperAllString(const string& s) {
        string result = s;
        for (char& c : result)
            if (c >= 'a' && c <= 'z') c -= 32;
        return result;
    }

    string UpperAllString() const {
        return UpperAllString(_s);
    }

    static string LowerAllString(const string& s) {
        string result = s;
        for (char& c : result)
            if (c >= 'A' && c <= 'Z') c += 32;
        return result;
    }

    string LowerAllString() const {
        return LowerAllString(_s);
    }

    static string InvertAllString(const string& s) {
        string result = s;
        for (char& c : result) {
            if (c >= 'a' && c <= 'z') c -= 32;
            else if (c >= 'A' && c <= 'Z') c += 32;
        }
        return result;
    }

    string InvertAllString() const {
        return InvertAllString(_s);
    }

    // Word Operations
    static void PrintFirstLetterOfEachWord(const string& s) {
        if (s.empty()) {
            cout << "Empty string" << endl;
            return;
        }

        if (s[0] != ' ') cout << s[0] << endl;

        for (size_t i = 1; i < s.length(); i++) {
            if (s[i-1] == ' ' && s[i] != ' ')
                cout << s[i] << endl;
        }
    }

    void PrintFirstLetterOfEachWord() const {
        PrintFirstLetterOfEachWord(_s);
    }

    static void PrintEachWord(const string& s) {
        vector<string> words = Split(s, " ");
        for (const string& word : words)
            if (!word.empty()) cout << word << endl;
    }

    void PrintEachWord() const {
        PrintEachWord(_s);
    }

    static int CountWords(const string& s) {
        vector<string> words = Split(s, " ");
        int count = 0;
        for (const string& word : words)
            if (!word.empty()) count++;
        return count;
    }

    int CountWords() const {
        return CountWords(_s);
    }

    // String Manipulation
    static vector<string> Split(const string& s, const string& delim) {
        vector<string> v;
        string str = s;
        size_t pos = 0;
        string token;

        while ((pos = str.find(delim)) != string::npos) {
            token = str.substr(0, pos);
            if (!token.empty()) v.push_back(token);
            str.erase(0, pos + delim.length());
        }
        if (!str.empty()) v.push_back(str);
        return v;
    }

    vector<string> Split(const string& delim) const {
        return Split(_s, delim);
    }

    static string TrimLeft(const string& s) {
        for (size_t i = 0; i < s.length(); i++)
            if (s[i] != ' ') return s.substr(i);
        return "";
    }

    string TrimLeft() const {
        return TrimLeft(_s);
    }

    static string TrimRight(const string& s) {
        for (size_t i = s.length() - 1; i >= 0; i--)
            if (s[i] != ' ') return s.substr(0, i + 1);
        return "";
    }

    string TrimRight() const {
        return TrimRight(_s);
    }

    static string Trim(const string& s) {
        string result = TrimLeft(s);
        result = TrimRight(result);
        return result;
    }

    string Trim() const {
        return Trim(_s);
    }

    static string Join(const vector<string>& v, const string& delim) {
        if (v.empty()) return "";
        string result;
        for (size_t i = 0; i < v.size(); i++) {
            result += v[i];
            if (i < v.size() - 1) result += delim;
        }
        return result;
    }

    static string Join(const string arr[], short size, const string& delim) {
        if (size == 0) return "";
        string result;
        for (short i = 0; i < size; i++) {
            result += arr[i];
            if (i < size - 1) result += delim;
        }
        return result;
    }

    static string Reverse(const string& s) {
        vector<string> words = Split(s, " ");
        string result;
        for (size_t i = words.size(); i > 0; i--) {
            result += words[i-1];
            if (i > 1) result += " ";
        }
        return result;
    }

    string Reverse() const {
        return Reverse(_s);
    }

    static string ReplaceWord(const string& s, const string& oldWord, const string& newWord) {
        string result = s;
        size_t pos = result.find(oldWord);
        while (pos != string::npos) {
            result.replace(pos, oldWord.length(), newWord);
            pos = result.find(oldWord);
        }
        return result;
    }

    string ReplaceWord(const string& oldWord, const string& newWord) const {
        return ReplaceWord(_s, oldWord, newWord);
    }

    static string RemovePunctuation(const string& s) {
        string result = s;
        for (size_t i = 0; i < result.length(); i++) {
            if (ispunct(result[i])) {
                result.erase(i, 1);
                i--;
            }
        }
        return result;
    }

    string RemovePunctuation() const {
        return RemovePunctuation(_s);
    }

    // Character Operations
    static int CountVowels(const string& s) {
        int count = 0;
        for (char c : s)
            if (IsVowel(c)) count++;
        return count;
    }

    int CountVowels() const {
        return CountVowels(_s);
    }
};