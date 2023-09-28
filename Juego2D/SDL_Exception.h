#include <exception>
#ifndef SDL_PROJECT_SDL_EXCEPTION_H
#define SDL_PROJECT_SDL_EXCEPTION_H
class SDL_Exception : public std::exception {
public:
    SDL_Exception(const char* message) : message(message) {}
    virtual const char* what() const throw() {
        return message;
    }

    const char* message;
};
#endif 