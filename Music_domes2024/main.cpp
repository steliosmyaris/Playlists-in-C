#include <iostream>
#include "Song.cpp"
#include "Playlist.cpp"
int main() {
    Playlist *p1 = new Playlist;

    string title, name, surname, album;
    int likes, position;
    int i = 0;

    while (i != 8) {
        cout << "1. Insert new song into playlist\n" <<
             "2. Play next song in playlist\n" <<
             "3. Play previous song in playlist\n" <<
             "4. Play all songs in playlist in random order\n" <<
             "5. Move song to another position in playlist\n" <<
             "6. Sort playlist\n" <<
             "7. Print playlist to screen\n" <<
             "8. Exit\n";
        cin >> i ;
        if (i == 1) {
            cout << "Enter title of song: ";
            cin >> title;
            cout << "Enter name of singer: ";
            cin >> name;
            cout << "Enter surname of singer: ";
            cin >> surname;
            cout << "Enter title of album: ";
            cin >> album;
            cout << "Enter number of likes: ";
            cin >> likes;
            cout << "Enter position in playlist: ";
            cin >> position;
            p1->addSong(title, name, surname, album, likes, position);
        } else if (i == 2) {
            p1->playnext();
        } else if (i == 3) {
            p1->playprev();
        } else if ( i == 4) {
            p1->randomPlay();
        } else if (i ==5 ) {
            cout << "give current position: ";
            cin >> likes;
            cout << endl << "give new position: ";
            cin >> position;
            p1->changeorder(likes, position); //οικονομία μνήμης
        } else if (i == 6) {
            cout << "Sort playlist by: \n"
                 << "1. Song title \n"
                 << "2. Singer's first name \n"
                 << "3. Singer's last name \n"
                 << "4. Number of likes (decreasing) \n"
                 << "5. Cancel\n";
            int sortChoice;
            cin >> sortChoice;
            if (sortChoice >= 1 && sortChoice <= 4) {
                p1->sortPlaylist(sortChoice);
                cout << "playlist sorted successfully.\n";
            } else if (sortChoice == 5) {
                cout << "sorting canceled.\n";
            } else {
                cout << "put a valid number please.\n";
            }
        } else if (i == 7) {
            p1->displaySongs();
        }else {
            if( i = 8 ) {
                cout << "Thank you for using my app.";
            } else {
            cout << "put a valid number please";
            }
        }
    }
    return 0;
}
