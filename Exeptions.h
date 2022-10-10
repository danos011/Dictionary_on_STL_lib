#ifndef TECPROG_COURSE_WORK_EXEPTIONS_H
#define TECPROG_COURSE_WORK_EXEPTIONS_H

#include <exception>
#include <string>

class BaseException : public std::exception {
public:
    const char *what() const noexcept override { return message_; }

protected:
    const char *message_;
};

class WrongCommand : public BaseException {
public:
    WrongCommand() { message_ = "Wrong command!"; }
};

class WrongCommandMain : public BaseException {
public:
    WrongCommandMain() { message_ = "Wrong command in main!"; }
};

class WrongInputElement : public BaseException {
public:
    WrongInputElement() { message_ = "This element doesn't exist!"; }
};

class WrongUnsignedNumber : public BaseException {
public:
    WrongUnsignedNumber() { message_ = "Wrong unsigned number!"; }
};

#endif //TECPROG_COURSE_WORK_EXEPTIONS_H

