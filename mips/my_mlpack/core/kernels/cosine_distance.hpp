/**
 * @file cosine_distance.hpp
 * @author Ryan Curtin
 *
 * This implements the cosine distance (or cosine similarity) between two
 * vectors, which is a measure of the angle between the two vectors.
 *
 * This file is part of mlpack 1.0.12.
 *
 * mlpack is free software; you may redstribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef __MY_MLPACK_CORE_KERNELS_COSINE_DISTANCE_HPP
#define __MY_MLPACK_CORE_KERNELS_COSINE_DISTANCE_HPP

#include <mips/my_mlpack/core.hpp>

namespace mips {
namespace kernel {

/**
 * The cosine distance (or cosine similarity).  It is defined by
 *
 * @f[
 * d(a, b) = \frac{a^T b}{|| a || || b ||}
 * @f]
 *
 * and this class assumes the standard L2 inner product.
 */
class CosineDistance
{
 public:
  /**
   * Computes the cosine distance between two points.
   *
   * @param a First vector.
   * @param b Second vector.
   * @return d(a, b).
   */
  template<typename VecType>
  static double Evaluate(const VecType& a, const VecType& b);
};

//! Kernel traits for the cosine distance.
template<>
class KernelTraits<CosineDistance>
{
 public:
  //! The cosine kernel is normalized: K(x, x) = 1 for all x.
  static const bool IsNormalized = true;
};

}; // namespace kernel
}; // namespace mlpack

// Include implementation.
#include "cosine_distance_impl.hpp"

#endif
