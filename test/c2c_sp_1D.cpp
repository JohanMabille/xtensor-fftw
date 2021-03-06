/*
 * xtensor-fftw
 * 
 * Copyright 2017 Patrick Bos
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#include <stdexcept> // workaround for xt bug, where only including xarray does not include stdexcept; TODO: remove this include when bug is fixed!
#include <xtensor/xarray.hpp>
#include <iostream>
#include <xtensor/xio.hpp>

#include <xtensor-fftw/fft.hpp>

#include "gtest/gtest.h"

TEST(fftC2CFloat1D,TransformAndInvert) {
  xt::xarray<float> a = xt::arange<float>(8);

  auto a_fourier = xt::fftw::fft(a);

  auto should_be_a = xt::fftw::ifft(a_fourier);

  std::cout << "real input:  " << a << std::endl;
  std::cout << "fourier transform of input: " << a_fourier << std::endl;
  std::cout << "real output: " << should_be_a << std::endl;
  ASSERT_EQ(a, should_be_a);
}