#pragma once

#include"Headers.h"

class myexception : public std:: exception
{
    virtual const char* what() const throw()
    {
        return "Please Enter Valid Choise";
    }
} exptn;




class Fileexception : public std::exception
{
    virtual const char* what() const throw()
    {
        return "File Not Found/Generated...!";
    }
} Fileexptn;