#include "functions.h"

void addWordToDictionary(std::map<std::string, std::list<std::string>> &dictionary){

    size_t choice = 0;
    std::string key;
    std::string translate;
    std::list<std::string> list;

    std::cout << "Enter a word:" << std::endl;
    std::cin >> key;
    std::transform(key.begin(), key.end(), key.begin(), toupper);
    std::map <std::string, std::list<std::string>> :: iterator element;
    element = dictionary.find(key);

    if(element != dictionary.end() && !dictionary.empty()){
        std::cout << "This word is already in the dictionary!" << std::endl;
        return;
    }

    std::cout << "1 - Add translation of the word." << std::endl;
    std::cout << "0 - exit." << std::endl;
    std::cin >> choice;

    if(!std::cin) {
        throw WrongUnsignedNumber();
    }
    else if(choice > 1){
        throw WrongCommand();
    }

    if(choice) {
        std::cout << "Add translation of the word." << std::endl;
        std::cin >> translate;
        list.push_back(translate);
    }
    dictionary.insert(make_pair(key, list));
    std::cout << std::endl;
}

void addTranslationToDictionary(std::map<std::string, std::list<std::string>> &dictionary){
    std::string key;
    std::cout << "Enter the word to which you want to add a translation:" << std::endl;
    std::cin >> key;
    std::transform(key.begin(), key.end(), key.begin(), toupper);
    std::map <std::string, std::list<std::string>> :: iterator element;
    element = dictionary.find(key);

    if(element == dictionary.end() && !dictionary.empty()){
        std::cout << "This word is not in the dictionary!" << std::endl;
        return;
    }

    std::cout << "Add translation:" << std::endl;
    std::string translate;
    std::cin >> translate;
    element->second.push_back(translate);
    std::cout << std::endl;
}

void removeWordFromDictionary(std::map<std::string, std::list<std::string>> &dictionary){
    std::string key;
    std::cout << "Enter the word you want to remove from the dictionary:" << std::endl;
    std::cin >> key;
    std::transform(key.begin(), key.end(), key.begin(), toupper);
    std::map <std::string, std::list<std::string>> :: iterator element;
    element = dictionary.find(key);

    if(element == dictionary.end()){
        std::cout << "This word is not in the dictionary!" << std::endl;
        return;
    }
    else{
        dictionary.erase(element);
    }
    std::cout << std::endl;
}

void removeTranslationFromDictionary(std::map<std::string, std::list<std::string>> &dictionary){
    std::string key;
    std::cout << "Enter the word where you want to remove the translation:" << std::endl;
    std::cin >> key;
    std::transform(key.begin(), key.end(), key.begin(), toupper);
    std::map <std::string, std::list<std::string>> :: iterator element;
    element = dictionary.find(key);

    if(element == dictionary.end() && !dictionary.empty()){
        std::cout << "This word is not in the dictionary!" << std::endl;
        return;
    }
    else if(element->second.empty()){
        std::cout << "Translation field is empty!" << std::endl;
        return;
    }

    std::size_t num;
    std::cout << "Choose the translation number of the word" << std::endl;
    std::cin >> num;
    auto translate = element->second.begin();
    if(!std::cin) {
        throw WrongUnsignedNumber();
    }
    else if(num > element->second.size()){
        throw WrongInputElement();
    }

    std::advance(translate, num);

    element->second.erase(translate);
    std::cout << std::endl;
}

void showTranslate(std::list<std::string> &data){
    size_t i = 0;

    if(data.empty()){
        std::cout << "Translation field is empty!" << std::endl;
        return;
    }

    for_each(data.begin(),data.end(), [&i](const std::string &bul){
        std::cout << "[" << i++ << "] - " << bul << "\n";
    });
    std::cout << std::endl;
}

void findTranslation(std::map<std::string, std::list<std::string>> &dictionary) {
    std::string key;
    std::cout << "Enter the word whose translation you want to see:" << std::endl;
    std::cin >> key;
    std::transform(key.begin(), key.end(), key.begin(), toupper);
    std::map <std::string, std::list<std::string>> :: iterator element;
    element = dictionary.find(key);

    if(element == dictionary.end() && !dictionary.empty()){
        std::cout << "This word is not in the dictionary!" << std::endl;
        return;
    }
    showTranslate(element->second);
}

void showDictionary(std::map<std::string, std::list<std::string>> &dictionary){

    auto functor = [](const std::pair<std::string, std::list<std::string>>& data)
    {
        std::ostringstream str;
        str << data.first << ": \n";
        size_t i = 0;

        if(data.second.empty()){
            str << "Translation field is empty! \n" << std::endl;
        }
        else {
            for_each(data.second.begin(), data.second.end(), [&str, &i](const std::string &bul) {
                str << "[" << i++ << "] - " << bul << "\n";
            });
        }

        return str.str();
    };

    if(dictionary.empty()){
        std::cout << "Alphabet is empty!" << std::endl;
    }

    std::transform(
            dictionary.begin(),
            dictionary.end(),
            std::ostream_iterator<std::string>(std::cout, "\n"),
            functor);
    std::cout << std::endl;
}