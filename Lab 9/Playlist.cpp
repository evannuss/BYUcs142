#include"Playlist.h"
#include"Song.h"
#include<vector>
#include<string>
#include<iostream>

using namespace std;


Playlist::Playlist(string name) {
	playlistName = name;
}

string Playlist::GetName()const {
	return playlistName;
}

void Playlist::AddSong(Song* song) {
	songList.push_back(song);
	return;
}

void Playlist::PlayPlaylist() {
	cout << "Playing first lines of playlist: " << playlistName << endl;
	for (int i = 0; i < songList.size(); i++) {
		cout << songList.at(i)->GetFirstLine() << endl;
		songList.at(i)->IncrementPlays();
	}
	return;
}

void Playlist::PrintSongs() {
	for (int i = 0; i < songList.size(); i++) {
		cout << i << ": " << songList.at(i)->GetName() << endl;
	}
	return;
}

void Playlist::DeleteSong(int songIndex) {
	songList.erase(songList.begin() + songIndex);
	return;
}

vector<Song*> Playlist::GetSongs()const {
	return songList;
}