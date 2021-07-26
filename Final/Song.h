#pragma once

#include<string>
#include<vector>
using namespace std;

class Song {
public:
	Song(string name = "none", string firstLine = "none");
	string GetName()const;
	string GetFirstLine()const;
	void IncrementPlays();
	int GetNumPlays()const;
	void AddTag(string tag);
	vector<string> GetTags();
	void EditFirstLine(string newFirstLine);
private:
	string songName;
	string songFirstLine;
	int numPlays;
	vector<string> songTags;
};
