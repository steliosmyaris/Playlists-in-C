//
// Created by user on 5/5/2024.
//

#ifndef MUSIC_DOMES2024_SONG_H
#define MUSIC_DOMES2024_SONG_H


#include "Song.h"
using namespace std;
#include <iostream>
#include <string>

class Song {
    friend class Playlist;
public:
    string Title;
    string Name;
    string Surname;
    string Album;
    int Likes;           // Data of the node
    Song *next;      // Pointer to the next node
    Song *prev;      // Pointer to the next node

    // Constructor
    Song(string t = "", string n = "", string s = "", string a = "", int l = 0, Song *nx = nullptr, Song *p = nullptr) {
        Title = t;
        Name = n;
        Surname = s;
        Album = a;
        Likes = l;
        next = nx;
        prev = p;
    };

    Song *returnNext() {return next;};
    Song *returnPrev() {return prev;};

    void printSong(){
        cout << "Song " << Title
             << " from the album " << Album
             << " \nwith singer " << Name
             << " " << Surname
             << " (" << Likes << " users like this song)";
    }

    void playingSong(){
        cout << "Playing song " << Title
             << " from the album " << Album
             << " \nwith singer " << Name
             << " " << Surname
             << " (" << Likes << " users like this song)";
    }

    ~Song(){};
};


#endif //MUSIC_DOMES2024_SONG_H
