/*
Evan Nuss, Section 1, nussevan@gmail.com
Freeing memory: main.cpp: lines 153 and 130
Test Case: 
	input: add, a b cd, a b cd, r t d, STOP, autogenp, faves, c d, play, 0, quit

	output: prompted for song name, first line, and tags correctly. asked for playlist name and
	tags. played first lines of a, a, and r.
*/

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
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
	string songInPlaylist2;
	string songInLibrary2;
	string inputTags;
	string songTag;

	istringstream tagISS;

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
			cout << "Tags: " << endl;
			getline(cin, inputTags);
			while (inputSongName != "STOP") {
				musicLibrary.push_back(new Song(inputSongName, inputFirstLine));
				tagISS.clear();
				tagISS.str(inputTags);
				while (!tagISS.eof()) {
					tagISS >> songTag;
					if (inputTags == "") {
						songTag = "";
					}
					musicLibrary.at(i)->AddTag(songTag);
				}

				cout << "Song Name: " << endl;
				getline(cin, inputSongName);
				if (inputSongName != "STOP") {
					cout << "Song's first line: " << endl;
					getline(cin, inputFirstLine);

					cout << "Tags: " << endl;
					getline(cin, inputTags);
				}
				i++;
			}
		}
		else if (userSelection == "list") {
			for (int i = 0; i < musicLibrary.size(); i++) {
				cout << musicLibrary.at(i)->GetName() << ": " << "\"" << musicLibrary.at(i)->GetFirstLine() << "\", "
					<< musicLibrary.at(i)->GetNumPlays() << " play(s)." << endl;
				cout << "Tags: ";
				for (int j = 0; j < musicLibrary.at(i)->GetTags().size(); j++) {
					cout << musicLibrary.at(i)->GetTags().at(j) << " ";
				}
				cout << endl;
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
		else if (userSelection == "autogenp") {
			istringstream autogenTagsISS;
			string tagToFind;
			vector<bool> alreadyInPlaylist(musicLibrary.size(), false);

			cout << "Playlist name: " << endl;
			cin.ignore();
			getline(cin, inputPlaylistName);
			Playlist autogenPlaylist(inputPlaylistName);

			cout << "Tags: " << endl;
			getline(cin, inputTags);
			autogenTagsISS.str(inputTags);

			while (!autogenTagsISS.eof()) {
				autogenTagsISS >> tagToFind;
				for (int i = 0; i < musicLibrary.size(); i++) {
					for (int j = 0; j < musicLibrary.at(i)->GetTags().size(); j++) {
						if (musicLibrary.at(i)->GetTags().at(j) == tagToFind && alreadyInPlaylist.at(i) == false){
							autogenPlaylist.AddSong(musicLibrary.at(i));
							alreadyInPlaylist.at(i) = true;
						}
					}
				}
			}
			playlists.push_back(autogenPlaylist);
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
					songInPlaylist2 = playlists.at(i).GetSongs().at(j)->GetFirstLine();
					songInLibrary2 = musicLibrary.at(songIndex)->GetFirstLine();
					if (songInPlaylist == songInLibrary && songInPlaylist2 == songInLibrary2) {
						playlists.at(i).DeleteSong(j);
					}
				}
			}
			delete musicLibrary.at(songIndex); //FREEING MEMORY
			musicLibrary.erase(musicLibrary.begin() + songIndex);
		}
		else if (userSelection == "deldup") {
			for (int i = 0; i < musicLibrary.size(); i++) {
				for (int j = 0; j < musicLibrary.size(); j++) {
					if (i == j) {
						break;
					}
					else {
						if (musicLibrary.at(i)->GetName() == musicLibrary.at(j)->GetName() &&
							musicLibrary.at(i)->GetFirstLine() == musicLibrary.at(j)->GetFirstLine()) {

							for (int k = 0; k < playlists.size(); k++) {
								for (int q = 0; q < playlists.at(k).GetSongs().size(); q++) {

									if (musicLibrary.at(j) == playlists.at(k).GetSongs().at(q)) {
										playlists.at(k).GetSongs().at(q) = musicLibrary.at(i);
									}
								}
							}
							delete musicLibrary.at(j);
							musicLibrary.erase(musicLibrary.begin() + j);
							j--;

							cout << "removing a duplicate of " << musicLibrary.at(i)->GetName() << endl;
						}
						else {
							if (j == musicLibrary.size() - 1) {
								j++;
							}
						}
					}
				}
			}
		}
		else if (userSelection == "updatesl") {
			for (int i = 0; i < musicLibrary.size(); i++) {
				cout << "\t" << i << ": " << musicLibrary.at(i)->GetName() << endl;
			}
			cout << "Pick a song index number: " << endl;
			cin >> songIndex;
			cout << "Song's first line: " << endl;
			cin >> inputFirstLine;

			musicLibrary.at(songIndex)->EditFirstLine(inputFirstLine);
		}
		else {
			cout << endl;
			cout << "add \t Adds a list of songs to the library" << endl;
			cout << "list \t Lists all the songs in the library" << endl;
			cout << "addp \t Adds a new playlist" << endl;
			cout << "autogenp \t Autogenerate a new playlist (based on tags)" << endl;
			cout << "addsp \t Adds a song to a playlist" << endl;
			cout << "listp \t Lists all the playlists" << endl;
			cout << "play \t Plays a playlist" << endl;
			cout << "delp \t Deletes a playlist" << endl;
			cout << "delsp \t Deletes a song from a playlist" << endl;
			cout << "delsl \t Deletes a song from the library (and all playlists)" << endl;
			cout << "deldup \t Deletes duplicate songs from the library (and all playlists)" << endl;
			cout << "updatesl \t Update a song in the library" << endl;
			cout << "options \t Prints this options menu" << endl;
			cout << "quit \t Quits the program" << endl;
		}
		cout << endl;
		cout << "Enter your selection now: ";
		cin >> userSelection;
	}
	cout << "Goodbye!" << endl;
	for (int i = 0; i < musicLibrary.size(); i++) {
		delete musicLibrary.at(i); //FREEING MEMORY
	}
	//system("pause");
	return 0;
}