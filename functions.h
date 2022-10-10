#ifndef TECPROG_COURSE_WORK_FUNCTIONS_H
#define TECPROG_COURSE_WORK_FUNCTIONS_H

#include <iostream>
#include <functional>
#include <map>
#include <list>
#include <string>
#include <algorithm>
#include <sstream>

#include "Exeptions.h"

void addWordToDictionary(std::map<std::string, std::list<std::string>> &dictionary);
void addTranslationToDictionary(std::map<std::string, std::list<std::string>> &dictionary);
void removeWordFromDictionary(std::map<std::string, std::list<std::string>> &dictionary);
void removeTranslationFromDictionary(std::map<std::string, std::list<std::string>> &dictionary);
void showTranslate(std::list<std::string> &data);
void findTranslation(std::map<std::string, std::list<std::string>> &dictionary);
void showDictionary(std::map<std::string, std::list<std::string>> &dictionary);


#endif //TECPROG_COURSE_WORK_FUNCTIONS_H
