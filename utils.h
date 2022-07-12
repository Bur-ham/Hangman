#include <string>

#define MAX_GUESSES 6

std::string makeHangman(int wrongGuessCount) {
    switch (wrongGuessCount) {
    case 1:
        return "-------\n   |\n   o";
    case 2:
        return "-------\n   |\n   o \n   |";
    case 3:
        return "-------\n   |\n   o \n  /|";
    case 4:
        return "-------\n   |\n   o \n  /|\\";
    case 5:
        return "-------\n   |\n   o \n  /|\\\n  /";
    case 6:
        return "-------\n   |\n   o \n  /|\\\n  / \\";
    default:
        return "-------";
    }
}