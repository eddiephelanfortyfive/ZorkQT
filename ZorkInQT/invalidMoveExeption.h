#ifndef INVALIDMOVEEXCEPTION_H
#define INVALIDMOVEEXCEPTION_H

#include <exception>
#include <string>

class InvalidMoveException : public std::exception {
public:
    InvalidMoveException(const std::string& direction)
        : m_direction(direction) {}

    virtual std::string message() const noexcept {
        return "Invalid move in direction: " + m_direction;
    }

    virtual const char* what() const noexcept override {
        return message().c_str();
    }

private:
    std::string m_direction;
};

#endif
