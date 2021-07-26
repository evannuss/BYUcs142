#pragma once

#include<vector>
#include<string>
#include"Song.h"
using namespace std;

class Playlist {
public:
	Playlist(string name = "none");
	string GetName()const;
	void AddSong(Song* song);
	void PlayPlaylist();
	void PrintSongs();
	void DeleteSong(int songIndex);
	vector<Song*> GetSongs()const;
private:
	string playlistName;
	vector<Song*> songList;
};