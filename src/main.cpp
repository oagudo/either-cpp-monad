#include <string>
#include "EitherMonad.h"
#include "Errors.h"

////////////////////////////////////////////////////////////////////////

struct Credentials { 
    std::string username;
    std::string pass;
};

struct AuthenticationToken { 
    std::string username;
};

struct UserInfo {
    unsigned int numberPosts;
    unsigned int totalKarma;
};

////////////////////////////////////////////////////////////////////////

Either<Error, double> averageKarmaPerPost(const UserInfo& info) {
    if (info.numberPosts != 0) return (static_cast<double>(info.totalKarma) / 
                                       static_cast<double>(info.numberPosts));
    else                       return AttemptToDivideByZero();
}

Either<Error, UserInfo> getUserInfo(const AuthenticationToken &token) {
    if (token.username == "user0")       return UserInfo { 0, 0 };
    else                                 return UserInfo { 4, 100 };
}

Either<Error, AuthenticationToken> authenticateUser(const Credentials &credentials) {
    if ((credentials.username == "user0") && (credentials.pass == "pass0"))          
                                                return AuthenticationToken {credentials.username};
    else if ((credentials.username == "user1") && (credentials.pass == "pass1"))          
                                                return AuthenticationToken {credentials.username};
    else                                        return AutenticationError();
}

Either<Error, Credentials> checkUserName(const Credentials &credentials) {
    if (credentials.username == "user0")       return credentials;
    else if (credentials.username == "user1")  return credentials;
    else                                       return InvalidUser();
}

auto getAverageKarmaPerPost(const std::string &username, 
                            const std::string &pass) {
        return 
        ((((mreturn< Either, Error, Credentials >( Credentials { username, pass} )
            >>=
        checkUserName)
            >>=
        authenticateUser)
            >>=
        getUserInfo)
            >>=
        averageKarmaPerPost);
}

////////////////////////////////////////////////////////////////////////

int main() {

    std::cout << "getAverageKarmaPerPost(user0, pass)  => " << 
        getAverageKarmaPerPost("user0", "pass") << std::endl;

    std::cout << "getAverageKarmaPerPost(user0, pass0) => " << 
        getAverageKarmaPerPost("user0", "pass0") << std::endl;

    std::cout << "getAverageKarmaPerPost(user1, pass0) => " << 
        getAverageKarmaPerPost("user1", "pass0") << std::endl;

    std::cout << "getAverageKarmaPerPost(user1, pass1) => " << 
        getAverageKarmaPerPost("user1", "pass1") << std::endl;

    std::cout << "getAverageKarmaPerPost(user2, pass2) => " << 
        getAverageKarmaPerPost("user2", "pass2") << std::endl;

    return 0;
}




