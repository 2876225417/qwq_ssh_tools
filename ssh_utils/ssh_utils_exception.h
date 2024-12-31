

#ifndef SSH_UTILS_EXCEPTION_H_
#define SSH_UTILS_EXCEPTION_H_

#include <exception>

namespace ssh_utils {

    class ssh_exception: public std::exception {
        ssh_exception() = default;
        ~ssh_exception() noexcept override ;

        const char* what() const noexcept override;

    };
}
#endif