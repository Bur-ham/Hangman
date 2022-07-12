#include <iostream>
#include <fstream>
#include <vector>
#include <set>


std::vector<std::string> getWords() {
    std::string tempWord;
    std::vector<std::string> wordVector;
    std::fstream file;
    file.open("words.txt", std::ios::in);
    while (std::getline(file, tempWord)) {
        wordVector.push_back(tempWord);
    }
    file.close();
    return wordVector;
}


std::string generateWordScores(std::string word, std::set<char> guessedSet) {
    std::string result = "";
    for (char c : word) {
        if (guessedSet.find(c) != guessedSet.end()) {
            result += c;
            result += " ";
        } else {
            result += "_ ";
        }
    }
    std::cout << std::endl;
    return result;
}

void printWordScores(std::string word, std::set<char> guessedSet) {
    std::string result = generateWordScores(word, guessedSet);
    std::cout << "Guess the word: " << result << std::endl;
}

void clearScreen() {
    std::system("clear");
}

int main() {
    std::vector<std::string> words = getWords();
    std::set <char> wordSet;
    std::set <char> guessedSet;

    std::srand (time(0));;
    int randIndex = (int) (std::rand() % words.size());
    std::string word = words[randIndex];

    
    for (auto w: word) {
        wordSet.insert(w);
    }

    int wrongGuessCount = 0;
    bool isGameOver = false;
    while (!isGameOver) {
        std::cout << "-----------------------------------------------------" << std::endl;
        std::string guess;
        std::cout << std::endl;
        std::cout << "Current Incorrect Guesses: " << wrongGuessCount << std::endl;
        printWordScores(word, guessedSet);
        if (wrongGuessCount == 3) {
            std::cout << "You lost!" << std::endl;
            std::cout << "The word was: " << word << std::endl;
            isGameOver = true;
            break;
        } else if (wordSet.size() == 0) {
            std::cout << "You won!" << std::endl;
            isGameOver = true;
            break;
        }
        std::cout << "Guess a letter: ";
        std::getline(std::cin >> std::ws, guess);

        if (guess.length() != 1 || guess.length() == 0) {
            std::cout << "Please enter a single letter." << std::endl;
            continue;
        } 

        if (guessedSet.find(guess[0]) != guessedSet.end()) {
            std::cout << "You already guessed that letter." << std::endl;
            continue;
        } 
        
        if (wordSet.find(guess[0]) != wordSet.end()) {
            guessedSet.insert(guess[0]);
            wordSet.erase(guess[0]);
        } else {
            wrongGuessCount++;
            clearScreen();
        }

        guessedSet.insert(guess[0]);
    }
}