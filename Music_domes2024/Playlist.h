//
// Created by user on 5/5/2024.
//

#ifndef MUSIC_DOMES2024_PLAYLIST_H
#define MUSIC_DOMES2024_PLAYLIST_H

#include "Song.cpp"
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>


class Playlist {
    friend class Song;
private:
    Song *head;   //The Node
    int lenght = 0;
    Song *curr = head;
public:
    // Constructor
    Playlist(Song *headuser = nullptr) {
        head = headuser;
    }

    // Destructor
    ~Playlist() {}

    Song *gethead() const {return (head);}

    int getcount() const {return (lenght);}

    bool isEmpty() const {return head == nullptr;}

    void addSong(const string& t, const string& n, const string& s, const string& a, int l, int p) {
        Song* newsong = new Song(t, n, s, a, l);
        if (isEmpty()) {
            head = newsong;
        } else {
            Song* current = head;
            int i = 1;
            while (current->next != nullptr && i < p - 1) {
                current = current->next;
                i++;
            }
            newsong->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = newsong;
            }
            current->next = newsong;
            newsong->prev = current;
        }
        lenght++;
    }

    //function to see if there is a node in the list with the data
    Song* find(string d) {
        if (!isEmpty()) {
            Song *current = head;
            while (current != nullptr) {
                if (current->Title == d) {
                    return current;
                }
                current = current->next;
            }
        }
        return nullptr;
    }

    void displaySongs() const {
        int i  = 1;
        if (isEmpty()) {
            cout << "The playlist is empty." << endl;
        } else {
            cout << "Songs in playlist:" << endl;
            Song *current = head;
            while (current != nullptr) {
                cout << "Song no." << i << " : ";
                current->printSong();
                cout << endl; i++;
                current = current->next;
            }
        }
    }

    void updatecurr() {
        curr = head;
    }

    bool playnext() {
        if (isEmpty()) {
            cout << "Playlist is empty";
            return 0;
        }
        if (curr->next != nullptr) {
        curr = curr->next;
        curr->playingSong();
        } else {
            cout << "There is no next song.";
        }
        return 1;
    }

    bool playprev() {
        if (isEmpty()) {
            cout << "Playlist is empty";
            return 0;
        }

        if (curr->prev != nullptr) {
            curr = curr->prev;
            curr->playingSong();
        } else {
            cout << "There is no previous song.";
        }
        return 1;
    }

    Song* findFromPosition(int i) {
        int j = 1;
        Song *current = head;
        while (j <= i) {
            current = current->next;
            j++;
        }
        return current;
    }

    void changeorder(int o, int d) {
        if (o == d) return; // No change needed if positions are the same

        Song* back = findFromPosition(o);
        Song* front = findFromPosition(d);

        if (!back || !front) return; // Exit if invalid positions are given

        // Disconnect back from the list
        if (back->prev) back->prev->next = back->next;
        if (back->next) back->next->prev = back->prev;

        // Disconnect front from the list
        if (front->prev) front->prev->next = front->next;
        if (front->next) front->next->prev = front->prev;

        if (head == back) head = back->next; // Update head if necessary
        if (head == front) head = front->next; // Update head if necessary

        // Reconnect back where front was
        back->prev = front->prev;
        back->next = front->next;
        if (back->prev) back->prev->next = back;
        if (back->next) back->next->prev = back;

        // Reconnect front where back was
        front->prev = (back->prev == front) ? back : back->prev; // Handle adjacent nodes
        front->next = (back->next == front) ? back : back->next;
        if (front->prev) front->prev->next = front;
        if (front->next) front->next->prev = front;

        // Correct head and tail if necessary
        if (!back->prev) head = back; // Back is now at the start
        if (!front->prev) head = front; // Front is now at the start
    }

    void randomPlay() {
        if (isEmpty()) {
            cout << "The playlist is empty.\n";
            return;
        }

        int songCount = getcount();
        Song** songArray = new Song*[songCount];

        Song* current = head;
        int index = 0;
        while (current != nullptr) {
            songArray[index++] = current;
            current = current->next;
        }

        srand(time(nullptr));

        for (int i = songCount - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            Song* temp = songArray[i];
            songArray[i] = songArray[j];
            songArray[j] = temp;
        }
        for (int i = 0; i < songCount; ++i) {
            songArray[i]->printSong();
            cout << endl;
        }

        // Clean up the dynamic array
        delete[] songArray;
    }

    bool compareSongs(Song* a, Song* b, int choice) {
        switch (choice) {
            case 1: return a->Title > b->Title;
            case 2: return a->Name > b->Name;
            case 3: return a->Surname > b->Surname;
            case 4: return a->Likes < b->Likes;
            default: return false;
        }
    }

    void sortPlaylist(int choice) {
        bool swap;
        do {
            swap = false;
            Song* current = head;
            while (current != nullptr && current->next != nullptr) {
                if (compareSongs(current, current->next, choice)) {
                    Song* temp = current->next;
                    if (current->prev) current->prev->next = temp;
                    if (temp->next) temp->next->prev = current;

                    current->next = temp->next;
                    temp->prev = current->prev;

                    temp->next = current;
                    current->prev = temp;

                    if (current == head) head = temp;
                    swap = true;
                }
                current = current->next;
            }
        } while (swap);
    }


};


#endif //MUSIC_DOMES2024_PLAYLIST_H
