#ifndef STAN__MATH__REV__SCAL__FUN__STEP_HPP
#define STAN__MATH__REV__SCAL__FUN__STEP_HPP

#include <stan/math/rev/core.hpp>

namespace stan {
  namespace agrad {

    /**
     * Return the step, or heaviside, function applied to the
     * specified variable (stan).
     *
     * See stan::math::step() for the double-based version.
     *
     * The derivative of the step function is zero everywhere
     * but at 0, so for convenience, it is taken to be everywhere
     * zero,
     *
     * \f$\mbox{step}(x) = 0\f$.
     *
     * @param a Variable argument.
     * @return The constant variable with value 1.0 if the argument's
     * value is greater than or equal to 0.0, and value 0.0 otherwise.
     */
    inline var step(const stan::agrad::var& a) {
      return var(new vari(a.vi_->val_ < 0.0 ? 0.0 : 1.0));
    }

  }
}
#endif
