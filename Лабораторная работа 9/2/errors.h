#pragma once
#include <iostream>
using namespace std;

class Error
{
public:
    virtual void what() {};
};

class IndexError : public Error
{
protected:
    string msg_1;
public:
    IndexError()
    { 
        msg_1 = "Invalid index of list."; 
    }
    virtual void what() 
    { 
        cout << msg_1 << "\n"; 
    }   
};

class ErrorIndexIsTooSmall : public IndexError 
{
protected:
    string msg_2;
public:
    ErrorIndexIsTooSmall() 
    {
        IndexError();
        msg_2 = "Index must be non-negative.";
    }
    virtual void what() 
    {
        cout << msg_1 << " " << msg_2 << "\n\n";
    }
};

class ErrorIndexIsTooBig : public IndexError 
{
protected:
    string msg_2;
public:
    ErrorIndexIsTooBig() 
    {
        IndexError();
        msg_2 = "Index more than current list size.";
    }
    virtual void what() {
        cout << msg_1 << " " << msg_2 << "\n\n";
    }
};

class SizeError : public Error 
{
protected:
    string msg_1;
public:
    SizeError() 
    {
        msg_1 = "Invalid list size!";
    }
    virtual void what() 
    {
        cout << msg_1 << endl;
    }
};

class ErrorSizeIsTooSmall : public SizeError 
{
protected:
    string msg_2;
public:
    ErrorSizeIsTooSmall()
    {
        IndexError();
        msg_2 = "Size must be non-negative!";
    }
    virtual void what() 
    {
        cout << msg_1 << " " << msg_2 << "\n\n";
    }
};

class ErrorSizeIsTooBig : public SizeError
{
protected:
    string msg_2;
public:
    ErrorSizeIsTooBig()
    {
        IndexError();
        msg_2 = "The size is exceeded.";
    }
    virtual void what() 
    {
        cout << msg_1 << " " << msg_2 << "\n\n";
    }
};
