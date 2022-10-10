#include "Exeptions.h"
#include "functions.h"

size_t selectAction(){
    size_t choice = 0;

    std::cout << "1 - Add word to dictionary" << std::endl;
    std::cout << "2 - Enter a translation into an existing word" << std::endl;
    std::cout << "3 - Remove word from dictionary" << std::endl;
    std::cout << "4 - Remove translation from dictionary" << std::endl;
    std::cout << "5 - Find translation" << std::endl;
    std::cout << "6 - Show dictionary" << std::endl;
    std::cout << "7 - Exit" << std::endl;
    std::cin >> choice;

    if (!std::cin) {
        throw WrongUnsignedNumber();
    }

    std::cout << std::endl;

    return choice;
}

int main() {
    std::map<std::string, std::list<std::string>> dictionary;

    try {
         size_t choice = selectAction();

        while (choice != 7) {
            switch (choice) {
                case 1:
                    addWordToDictionary(dictionary);
                    break;
                case 2:
                    addTranslationToDictionary(dictionary);
                    break;
                case 3:
                    removeWordFromDictionary(dictionary);
                    break;
                case 4:
                    removeTranslationFromDictionary(dictionary);
                    break;
                case 5:
                    findTranslation(dictionary);
                    break;
                case 6:
                    showDictionary(dictionary);
                    break;
                case 7:
                    break;
                default:
                    throw WrongCommandMain();
            }

            choice = selectAction();
        }
    }
    catch (std::exception &exception) {
        std::cerr << std::endl << exception.what() << std::endl;
        return -1;
    }
    return 0;
}
