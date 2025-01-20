#include "2.hpp"

outerr::ErrException::ErrException(int ID, const char *err, const char *func)
{
    this->ID = ID;
    this->err = err;
    this->func = func;
}

const char *outerr::ErrException::what() const noexcept
{
    std::string str = "";
    str.append("ID: [");
    str.append(std::to_string(this->ID));
    str.append("] ErrException: [");
    str.append(err);
    str.append("] Function: [");
    str.append(this->func);
    str.append("]");
    char *r = new char[strlen(str.c_str()) + 1];
    strlcpy(r, str.c_str(), strlen(str.c_str()) + 1);
    return r;
}

outerr::NotExitException::NotExitException(int ID, const char *err, const char *func)
{
    this->ID = ID;
    this->err = err;
    this->func = func;
}

const char *outerr::NotExitException::what() const noexcept
{
    std::string str = "";
    str.append("ID: [");
    str.append(std::to_string(this->ID));
    str.append("] NotExitException: [");
    str.append(err);
    str.append("] Function: [");
    str.append(this->func);
    str.append("]");
    char *r = new char[strlen(str.c_str()) + 1];
    strlcpy(r, str.c_str(), strlen(str.c_str()) + 1);
    return r;
}