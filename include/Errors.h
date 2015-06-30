#ifndef _ERRORS_H
#define _ERRORS_H

struct Error {
    Error(const std::string &error) : _error(error) { };
    std::string ToString() const { return _error; }
private:
    std::string _error;
};

#define APPLICATION_ERROR(error_name, error_desc) \
    struct error_name : public Error { \
        error_name() : Error(error_desc) { }  \
    };

// Custom application errors
//
APPLICATION_ERROR(DivideByZero, "Attempt to dive by zero")
APPLICATION_ERROR(InvalidArg, "Invalid argument")

#endif
