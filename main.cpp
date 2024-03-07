#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

int passwordGenerate(int lettersUpperLength, int lettersLowerLength, int numbersLength, int symbolLength) {
    std::string password;

    std::string lettersUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lettersLower = "abcdefghijklmnopqrstuvwxyz";
    std::string numbers = "0123456789";
    std::string symbols = "!@#$%^&v*_+-=[].<>?";

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle(lettersUpper.begin(), lettersUpper.end(), std::default_random_engine(seed));
    shuffle(lettersLower.begin(), lettersLower.end(), std::default_random_engine(seed));
    shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
    shuffle(symbols.begin(), symbols.end(), std::default_random_engine(seed));

    password = lettersUpper.substr(0, lettersLowerLength) +
                      lettersLower.substr(0, lettersUpperLength) +
                      numbers.substr(0, numbersLength) +
                      symbols.substr(0, symbolLength);

    shuffle(password.begin(), password.end(), std::default_random_engine(seed));

    std::cout << "your password is:\n"<< password;
}

int main()
{
    int lettersUpperLength;
    int lettersLowerLength;
    int numberLength;
    int symbolLength;

    std::string login = "login";
    std::string testLogin;

    std::cout << "write login(is beta version login is: login): \n";
    std::cin >> testLogin;
    if (testLogin != login) {
        std::cout << "your answer is falls\nleaving from program...";
        exit(0);
    }

    std::cout << "choose count of upper case letters: ";
    std::cin >> lettersUpperLength;
    std::cout << std::endl;

    std::cout << "choose count of lower case letters: ";
    std::cin >> lettersLowerLength;
    std::cout << std::endl;

    std::cout << "choose count of number: ";
    std::cin >> numberLength;
    std::cout << std::endl;

    std::cout << "choose count of symbol: ";
    std::cin >> symbolLength;
    std::cout << std::endl;
    passwordGenerate(lettersUpperLength,lettersLowerLength,numberLength,symbolLength);
}
