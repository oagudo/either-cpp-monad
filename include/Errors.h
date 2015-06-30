#ifndef _ERRORS_H
#define _ERRORS_H

struct Error {
    Error(const std::string &error) : _error(error) { };
    std::string ToString() const { return _error; }
private:
    std::string _error;
};

std::ostream& operator<<(std::ostream& os, const Error& error) {
    os << error.ToString();
    return  os;
}

#define APPLICATION_ERROR(error_name, error_desc) \
    struct error_name : public Error { \
        error_name() : Error(error_desc) { }  \
    };

// Custom application errors
//
APPLICATION_ERROR(AutenticationError,           "Autentication error")
APPLICATION_ERROR(InvalidUser,                  "Invalid user")
APPLICATION_ERROR(AttemptToDivideByZero,        "Attempt to divide by zero")

#endif
