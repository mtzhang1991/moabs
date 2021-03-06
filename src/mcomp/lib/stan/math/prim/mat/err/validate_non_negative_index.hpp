#ifndef STAN__MATH__PRIM__MAT__ERR__VALIDATE_NON_NEGATIVE_INDEX_HPP
#define STAN__MATH__PRIM__MAT__ERR__VALIDATE_NON_NEGATIVE_INDEX_HPP

#include <sstream>
#include <stdexcept>
#include <string>

namespace stan {
  namespace math {

    inline void
    validate_non_negative_index(const char* var_name,
                                const char* expr,
                                int val) {
      if (val < 0) {
        std::stringstream msg;
        msg << "Found negative dimension size in variable declaration"
            << "; variable=" << var_name
            << "; dimension size expression=" << expr
            << "; expression value=" << val;
        std::string msg_str(msg.str());
        throw std::invalid_argument(msg_str.c_str());
      }
    }

  }
}
#endif
