/* -*- c++ -*- */
/*
 * Copyright 2019-2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_FLL_FREQUENCY_LOCKED_LOOP_FF_IMPL_H
#define INCLUDED_FLL_FREQUENCY_LOCKED_LOOP_FF_IMPL_H

#include <gnuradio/fll/frequency_locked_loop_ff.h>

namespace gr {
namespace fll {

class frequency_locked_loop_ff_impl : public frequency_locked_loop_ff {
private:
  float d_rolloff;
  int d_samples;
  float d_delta_f;
  float d_derivative;
  int d_count;

public:
  frequency_locked_loop_ff_impl(float rolloff, int samples);
  ~frequency_locked_loop_ff_impl();

  // Where all the action really happens
  int work(int noutput_items, gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
};

} // namespace fll
} // namespace gr

#endif /* INCLUDED_FLL_FREQUENCY_LOCKED_LOOP_FF_IMPL_H */
