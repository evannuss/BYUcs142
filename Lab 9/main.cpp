/*
Evan Nuss, Section 1, nussevan@gmail.com
Freeing memory: main.cpp: lines 153 and 130
Test Case 1:
	input: options. add. rolling in the deep. there's a fire. STOP. list. quit
	output: options menu displayed correctly. asked for song name and first line.
	displayed the song, first line, and plays.
Test Case 2:
	input: add. baby. ya know you love me. STOP. addp. Awesome. addsp. 0. 0. play. 0.
	delp. 0. delsl. 0. list. quit
	output: asked for song name and first line. asked for a playlist name. asked for playlist index
	and song index. displayed first line of song in playlist. asked for playlist index to delete.
	asked for song index to delete. list of songs was empty. 
Test Case 3:
	input: add. baby. ya know you love me. add. i want it that way. yeahh. add. what makes you beautiful.
	you're insecure, don't know what for. addp. the songs we all secretly love. addsp. 0. 0. addsp. 0. 1. addsp. 0. 2
	play. quit
	output: asked for names and first lines of all 3 songs. asked for playlist name.
	asked for indices of playlist and songs. displayed first lines of songs.
*/

#include<iostream>
#include<string>
#include<vector>
#include"Song.h"
#include"Playlist.h"


using namespace std;


int main() {
	string userSelection;
	vector<Song*> musicLibrary;
	string inputSongName;
	string inputFirstLine;
	vector<Playlist> playlists;
	string inputPlaylistName;
	
	int playlistIndex = 0;
	int songIndex = 0;

	string songInPlaylist;
	string songInLibrary;

	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;
	cout << "Enter your selection now: ";
	cin >> userSelection;
	while (userSelection != "quit") {
		
		if (userSelection == "add") {
			int i = 0;
			cout << "Read in Song names, first lines, and tags (type \"STOP\" when done) :" << endl;
			cout << "Song Name: " << endl;
			cin.ignore();
			getline(cin, inputSongName);
			cout << "Song's first line: " << endl;
			getline(cin, inputFirstLine);
			while (inputSongName != "STOP") {
				musicLibrary.push_back(new Song(inputSongName, inputFirstLine));

				cout << "Song Name: " << endl;
				getline(cin, inputSongName);
				if (inputSongName != "STOP") {
					cout << "Song's first line: " << endl;
					getline(cin, inputFirstLine);
				}
				i++;
			}
		}
		else if (userSelection == "list") {
			for (int i = 0; i < musicLibrary.size(); i++) {
				cout << musicLibrary.at(i)->GetName() << ": " << "\"" << musicLibrary.at(i)->GetFirstLine() << "\", "
					<< musicLibrary.at(i)->GetNumPlays() << " play(s)." << endl;
			}

		}
		else if (userSelection == "addp") {
			cout << "Playlist name: " << endl;
			cin.ignore();
			getline(cin, inputPlaylistName);
			cout << endl;
			Playlist newPlaylist(inputPlaylistName);
			playlists.push_back(newPlaylist);
		}
		else if (userSelection == "addsp") {
			for (int i = 0; i < playlists.size(); i++) {
				cout << i << ": " << playlists.at(i).GetName() << endl;
			}
			cout << "Pick a playlist index number: " << endl;
			cin >> playlistIndex;
			for (int i = 0; i < musicLibrary.size(); i++) {
				cout << i << ": " << musicLibrary.at(i)->GetName() << endl;
			}
			cout << "Pick a song index number: " << endl;
			cin >> songIndex;
			playlists.at(playlistIndex).AddSong(musicLibrary.at(songIndex));
		}
		else if (userSelection == "listp") {
			for (int i = 0; i < playlists.size(); i++) {
				cout << i << ": " << playlists.at(i).GetName() << endl;
			}
		}
		else if (userSelection == "play") {
			for (int i = 0; i < playlists.size(); i++) {
				cout << i << ": " << playlists.at(i).GetName() << endl;
			}
			cout << "Pick a playlist index number: " << endl;
			cin >> playlistIndex;
			playlists.at(playlistIndex).PlayPlaylist();
		}
		else if (userSelection == "delp") {
			for (int i = 0; i < playlists.size(); i++) {
				cout << i << ": " << playlists.at(i).GetName() << endl;
			}
			cout << "Pick a playlist index number to delete: " << endl;
			cin >> playlistIndex;
			playlists.erase(playlists.begin() + playlistIndex);
		}
		else if (userSelection == "delsp") {
			for (int i = 0; i < playlists.size(); i++) {
				cout << i << ": " << playlists.at(i).GetName() << endl;
			}
			cout << "Pick a playlist index number: " << endl;
			cin >> playlistIndex;
			playlists.at(playlistIndex).PrintSongs();
			cout << "Pick a song index number to delete: " << endl;
			cin >> songIndex;
			playlists.at(playlistIndex).DeleteSong(songIndex);
		}
		else if (userSelection == "delsl") {
			for (int i = 0; i < musicLibrary.size(); i++) {
				cout << i << ": " << musicLibrary.at(i)->GetName() << endl;
			}
			cout << "Pick a song index number: " << endl;
			cin >> songIndex;
			for (int i = 0; i < playlists.size(); i++) {
				for (int j = 0; j < playlists.at(i).GetSongs().size(); j++) {
					songInPlaylist = playlists.at(i).GetSongs().at(j)->GetName();
					songInLibrary = musicLibrary.at(songIndex)->GetName();
					if (songInPlaylist == songInLibrary) {
						playlists.at(i).DeleteSong(j);
					}
				}
			}
			delete musicLibrary.at(songIndex); //FREEING MEMORY
			musicLibrary.erase(musicLibrary.begin() + songIndex);
		}
		else {
			cout << endl;
			cout << "add \t Adds a list of songs to the library" << endl;
			cout << "list \t Lists all the songs in the library" << endl;
			cout << "addp \t Adds a new playlist" << endl;
			cout << "addsp \t Adds a song to a playlist" << endl;
			cout << "listp \t Lists all the playlists" << endl;
			cout << "play \t Plays a playlist" << endl;
			cout << "delp \t Deletes a playlist" << endl;
			cout << "delsp \t Deletes a song from a playlist" << endl;
			cout << "delsl \t Deletes a song from the library (and all playlists)" << endl;
			cout << "options \t Prints this options menu" << endl;
			cout << "quit \t Quits the program" << endl;
		}
		cout << endl;
		cout << "Enter your selection now: ";
		cin >> userSelection;
	}
	cout << "Goodbye!" << endl;
	for (int i = 0; i < musicLibrary.size();  i++) {
		delete musicLibrary.at(i); //FREEING MEMORY
	}
	//system("pause");
	return 0;
}