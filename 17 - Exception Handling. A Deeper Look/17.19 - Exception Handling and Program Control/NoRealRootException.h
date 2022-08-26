// Exercise 17.19: NoRealRootException.h

#ifndef NOREALROOTEXCEPTION_H
#define NOREALROOTEXCEPTION_H

#include <stdexcept>

class NoRealRootException : public std::runtime_error {
public:
   NoRealRootException() : std::runtime_error{ "no real roots" }{};
};

#endif