#ifndef STAN__MATH__PRIM__SCAL__ERR__CHECK_CONSISTENT_SIZES_HPP
#define STAN__MATH__PRIM__SCAL__ERR__CHECK_CONSISTENT_SIZES_HPP

#include <stan/math/prim/scal/err/check_consistent_size.hpp>

#include <algorithm>

namespace stan {
  namespace math {

    /**
     * Return <code>true</code> if the dimension of x1 is consistent
     * with x2.
     *
     * Consistent size is defined as having the same size if vector-like or
     * being a scalar.
     *
     * @tparam T1 Type of x1
     * @tparam T2 Type of x2
     *
     * @param function Function name (for error messages)
     * @param name1 Variable name (for error messages)
     * @param x1 Variable to check for consistent size
     * @param name2 Variable name (for error messages)
     * @param x2 Variable to check for consistent size
     *
     * @return <code>true</code> if x1 and x2 have consistent sizes
     * @throw <code>invalid_argument</code> if sizes are inconsistent
     */
    template <typename T1, typename T2>
    inline bool check_consistent_sizes(const char* function,
                                       const char* name1,
                                       const T1& x1,
                                       const char* name2,
                                       const T2& x2) {
      using stan::is_vector;
      size_t max_size = std::max(is_vector<T1>::value * size_of(x1),
                                 is_vector<T2>::value * size_of(x2));
      return check_consistent_size(function, name1, x1, max_size)
        && check_consistent_size(function, name2, x2, max_size);
    }

    /**
     * Return <code>true</code> if the dimension of x1, x2, and x3 are
     * consistent.
     *
     * Consistent size is defined as having the same size if vector-like or
     * being a scalar.
     *
     * @tparam T1 Type of x1
     * @tparam T2 Type of x2
     * @tparam T3 Type of x3
     *
     * @param function Function name (for error messages)
     * @param name1 Variable name (for error messages)
     * @param x1 Variable to check for consistent size
     * @param name2 Variable name (for error messages)
     * @param x2 Variable to check for consistent size
     * @param name3 Variable name (for error messages)
     * @param x3 Variable to check for consistent size
     *
     * @return <code>true</code> if x1, x2, and x3 have consistent sizes
     * @throw <code>invalid_argument</code> if sizes are inconsistent
     */
    template <typename T1, typename T2, typename T3>
    inline bool check_consistent_sizes(const char* function,
                                       const char* name1,
                                       const T1& x1,
                                       const char* name2,
                                       const T2& x2,
                                       const char* name3,
                                       const T3& x3) {
      size_t max_size = std::max(is_vector<T1>::value * size_of(x1),
                                 std::max(is_vector<T2>::value * size_of(x2),
                                          is_vector<T3>::value * size_of(x3)));
      return check_consistent_size(function, name1, x1, max_size)
        && check_consistent_size(function, name2, x2, max_size)
        && check_consistent_size(function, name3, x3, max_size);
    }

    /**
     * Return <code>true</code> if the dimension of x1, x2, x3, and x4
     * are consistent.
     *
     * Consistent size is defined as having the same size if
     * vector-like or being a scalar.
     *
     * @tparam T1 Type of x1
     * @tparam T2 Type of x2
     * @tparam T3 Type of x3
     * @tparam T4 Type of x4
     *
     * @param function Function name (for error messages)
     * @param name1 Variable name (for error messages)
     * @param x1 Variable to check for consistent size
     * @param name2 Variable name (for error messages)
     * @param x2 Variable to check for consistent size
     * @param name3 Variable name (for error messages)
     * @param x3 Variable to check for consistent size
     * @param name4 Variable name (for error messages)
     * @param x4 Variable to check for consistent size
     *
     * @return <code>true</code> if x1, x2, x3, and x4 have consistent sizes
     * @throw <code>invalid_argument</code> if sizes are inconsistent
     */
    template <typename T1, typename T2, typename T3, typename T4>
    inline bool check_consistent_sizes(const char* function,
                                       const char* name1,
                                       const T1& x1,
                                       const char* name2,
                                       const T2& x2,
                                       const char* name3,
                                       const T3& x3,
                                       const char* name4,
                                       const T4& x4) {
      size_t max_size
        = std::max(is_vector<T1>::value * size_of(x1),
                   std::max(is_vector<T2>::value * size_of(x2),
                            std::max(is_vector<T3>::value * size_of(x3),
                                     is_vector<T4>::value * size_of(x4))));
      return check_consistent_size(function, name1, x1, max_size)
        && check_consistent_size(function, name2, x2, max_size)
        && check_consistent_size(function, name3, x3, max_size)
        && check_consistent_size(function, name4, x4, max_size);
    }

  }
}
#endif
