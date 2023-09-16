#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <iterator>


class Song {
    friend std::ostream& operator<<(std::ostream& os, const Song& s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{ name }, artist{ artist }, rating{ rating } {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }

    bool operator<(const Song& rhs) const {
        return this->name < rhs.name;
    }

    bool operator==(const Song& rhs) const {
        return this->name == rhs.name;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
    os << std::setw(20) << std::left << s.name
        << std::setw(30) << std::left << s.artist
        << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song& song) {
    // This function should display 
    // Playing: followed by the song that is playing

    std::cout << "Playing:\n" << song << std::endl;
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song) {
    // This function should display the current playlist 
    // and then the current song playing.

    std::cout << std::endl;

    for (auto actualSong : playlist)
    {
        std::cout << actualSong << std::endl;
    }

    std::cout << "Current song:\n" << current_song << std::endl;
    
}


// forward declaration
char getSelection();
void handleSelection(char selection, std::list<Song>& playlist,std::list<Song>::iterator &currentSong);
void playNextSong(std::list<Song> &playlist, std::list<Song>::iterator &currentSong);
void playPreviousSong(std::list<Song>& playlist, std::list<Song>::iterator& currentSong);


int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}
    };

    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    char actualSelection{};
    // Run programm until quit
    do
    {
        display_menu();
        actualSelection = getSelection();
        handleSelection(actualSelection, playlist, current_song);
    } while (actualSelection != 'Q');
  
    return 0;
}

char getSelection()
{
    char selection{};
    bool selectionLegit{ false };
    do
    {
        std::cin >> selection;
        selection = std::toupper(selection);
        selectionLegit = (selection == 'F' || selection == 'N' || selection == 'P' ||
            selection == 'A' || selection == 'L' || selection == 'Q');
        if (!selectionLegit)
        {
            std::cout << "Invalid selection, try again\n";
        }
    } while (!selectionLegit);
    return selection;
}

void handleSelection(char selection, std::list<Song>& playlist, std::list<Song>::iterator& currentSong)
{
    switch (selection)
    {
        case 'F':
            break;
        case 'N':
            playNextSong(playlist, currentSong);
            break;
        case 'P':
            playPreviousSong(playlist, currentSong);
            break;
        case 'A':
            break;
        case 'L':
            display_playlist(playlist, *currentSong);
            break;
        case 'Q':
            std::cout << "Thanks for listening!" << std::endl;
            break;
    }
}


// Playing next song
void playNextSong(std::list<Song>& playlist, std::list<Song>::iterator& currentSong)
{
    std::cout << "Playing next song\nPlaying:\n";
    if (currentSong->get_name() == playlist.back().get_name())
    {
        currentSong = playlist.begin();
    }
    else
    {
        ++currentSong;
    }
    
    std::cout << *currentSong << std::endl;
}

// Playing previous song
void playPreviousSong(std::list<Song>& playlist, std::list<Song>::iterator& currentSong)
{
    std::cout << "Playing previous song\nPlaying:\n";
    if (currentSong->get_name() == playlist.front().get_name())
    {
        currentSong = std::prev(playlist.end());
    }
    else
    {
        --currentSong;
    }

    std::cout << *currentSong << std::endl;
}
