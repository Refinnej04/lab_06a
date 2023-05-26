// WordCount.cpp

#include "WordCount.h"

using namespace std;
#include <string>
#include <sstream>
#include <iostream>

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int total = 0;
    for (size_t i = 0; i < CAPACITY; ++i) {
        for (size_t j = 0; j < table[i].size(); ++j) {
            total += table[i][j].second;
}
}
return total;
}

int WordCount::getNumUniqueWords() const {
		int total = 0;
	for (auto num : table)
	{
		total += num.size();
	}
	return total;
}

int WordCount::getWordCount(std::string word) const {
	  word = makeValidWord(word);
    size_t index = hash(word);

for (size_t i = 0; i < table[index].size(); ++i) {
    if (table[index][i].first == word) {
    return table[index][i].second;
}
}
return 0;
}
	
int WordCount::incrWordCount(std::string word) {
		word = makeValidWord(word);
	if(word ==""){
	return 0;
	}
	size_t index = hash(word);
	for (size_t i = 0; i < table[index].size(); ++i)
	{
		if (table[index][i].first == word)
		{
			table[index][i].second++;
			return table[index][i].second;
		}
	}
	table[index].push_back(std::pair<std::string, int>(word, 1));
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	word = makeValidWord(word);
if(word ==""){
	return -1;
}
	size_t index = hash(word);
	for (size_t i = 0; i < table[index].size(); ++i)
	{
		if (table[index][i].first == word)
		{
			if (table[index][i].second > 1)
			{
				table[index][i].second--;
				return table[index][i].second;
			}
			else if (table[index][i].second == 1)
			{
				table[index].erase(table[index].begin() + i);
				return 0;
			}
		}
	}
	return -1;
}


bool WordCount::isWordChar(char c) {
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

std::string WordCount::makeValidWord(std::string word) {
string result = "";
	
	for (size_t i = 0; i < word.length(); i++)
	{
		if (isWordChar(word.at(i))|| word.at(i) == '-'  || word.at(i) =='\'')
		{
				result += tolower(word.at(i));
				
			}
		}

while (result.length()>0 &&(result.at(0) == '-' || result.at(0) == '\''  || result.at(result.length()-1) =='\'' || result.at(result.length()-1) =='-')){
	if(result.length()== 1){
		return "";
	}
	if(result.at(0) == '-' || result.at(0) == '\''){
		result = result.substr(1,result.length()-1);
	}
	if(result.at(result.length()-1) =='\'' || result.at(result.length()-1) =='-'){
		result = result.substr(0,result.length()-1);
	}

}

return result;
}
bool sortW(pair<string,int> P1,pair<string,int> P2){
	return P1.first >  P2.first;
}
bool sortO(pair<string,int> P1,pair<string,int> P2){
	if(P1.second != P2.second){
	return P1.second <  P2.second;}
	else {return P1.first <  P2.first;}
	
}


void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	vector<pair<string,int>> sortVec;
	for(size_t i =0; i< CAPACITY;i++){
		for(size_t j = 0; j<table[i].size();j++){
			sortVec.push_back(table[i].at(j));
		}
	}

	sort(sortVec.begin(),sortVec.end(),sortW);

	for(size_t i =0; i<sortVec.size();i++){
		out<< sortVec.at(i).first<< ","<<sortVec.at(i).second<<endl;
	}
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
		vector<pair<string,int>> sortVec;
	for(size_t i =0; i< CAPACITY;i++){
		for(size_t j = 0; j<table[i].size();j++){
			sortVec.push_back(table[i].at(j));
		}
	}

	sort(sortVec.begin(),sortVec.end(), sortO );

	for(size_t i =0; i<sortVec.size();i++){
		out<< sortVec.at(i).first<< ","<<sortVec.at(i).second<<endl;
	}
}

void WordCount::addAllWords(std::string text) {
	 istringstream iss(text);
    string word;
    while (iss >> word) {
        this->incrWordCount( word);
    }
}
