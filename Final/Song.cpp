#include"Song.h"
#include<iostream>
#include<string>

using namespace std;

Song::Song(string name, string firstLine) {
	songName = name;
	songFirstLine = firstLine;
	numPlays = 0;
}

string Song::GetName()const {
	return songName;
}

string Song::GetFirstLine()const {
	return songFirstLine;
}

void Song::IncrementPlays() {
	numPlays++;
	return;
}

int Song::GetNumPlays()const {
	return numPlays;
}

void Song::AddTag(string tag) {
	songTags.push_back(tag);
	return;
}

vector<string> Song::GetTags() {
	return songTags;
}

void Song::EditFirstLine(string newFirstLine) {
	songFirstLine = newFirstLine;
	return;
}