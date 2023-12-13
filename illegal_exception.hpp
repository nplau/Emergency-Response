#ifndef ILLEGAL_EXCEPTION_HPP
#define ILLEGAL_EXCEPTION_HPP

#include <iostream>
#include <stdexcept>

/*CITATION:

reused the same exception as used in project 3*/

class illegal_exception : public std::exception
{
public:
    std::string what();
};

#endif