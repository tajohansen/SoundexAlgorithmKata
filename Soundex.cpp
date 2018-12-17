//
// Created by troyjohansen on 12/13/2018.
//
#include <unordered_map>
#include "Soundex.h"

string Soundex::zeroPad(const string& word) const
{
    auto zerosNeeded = MaxcodeLength - word.length();
    return word + string(zerosNeeded, '0');
}

string Soundex::encode(const string& word) const
{
    return zeroPad(upperFront(head(word)) + encodeDigits(tail(word)));
}


string Soundex::head(const string &word) const {
    return word.substr(0,1);
}

string Soundex::tail(const string &word) const {
    return word.substr(1);
}


string Soundex::encodeDigits(const string &word) const {

    string encoding;

    for (auto letter : word)
    {
        if (isComplete(encoding))
        {
            break;
        }
        if (encodeDigit(letter) != lastDigit(encoding))
        {
            encoding += encodeDigit(letter);
        }
    }
    return encoding;

}

string Soundex::encodeDigit(char letter) const
{
    const unordered_map<char, string> encoding{
            {'b', "1"}, {'f', "1"}, {'p', "1"},{'v', "1"}, {'c', "2"},
            {'g', "2"},{'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"},
            {'x', "2"},{'z', "2"},{'d', "3"},{'t', "3"},{'l', "4"},
            {'m', "5"},{'n', "5"}, {'r', "6"}
    };

    // Find the letter in the map and
    // return the associated value
    // If you reach the end of the map,
    // you got no match. In this case, return
    // an empty string.
    auto it = encoding.find(letter);
    return it == encoding.end() ? "" : it->second;

}
bool Soundex::isComplete(const string &encoding) const {
    return encoding.length() == MaxcodeLength - 1;
}

string Soundex::lastDigit(const string &encoding) const {
    if (encoding.empty())
    {
        return  "";
    }
    return std::string(1,encoding.back());
}

string Soundex::upperFront(const string &word) const
{
    return std::string(1,
            toupper(static_cast<unsigned char>(word.front())));
}

