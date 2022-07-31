/* -*- c++ -*- */
/*
 * Copyright 2019-2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "frequency_locked_loop_ff_impl.h"
#include <gnuradio/io_signature.h>

namespace gr {
namespace fll {

frequency_locked_loop_ff::sptr frequency_locked_loop_ff::make(float rolloff,
                                                              int samples) {
  return gnuradio::make_block_sptr<frequency_locked_loop_ff_impl>(rolloff,
                                                                  samples);
}

/*
 * The private constructor
 */
frequency_locked_loop_ff_impl::frequency_locked_loop_ff_impl(float rolloff,
                                                             int samples)
    : gr::sync_block(
          "frequency_locked_loop_ff",
          gr::io_signature::make(1, 1, sizeof(float)),
          gr::io_signature::make(1, 1, sizeof(float))) {

  d_rolloff = rolloff; /* default 1.6 */
  d_samples = samples;
  d_delta_f = 0.0;
  d_derivative = 0.0;
  d_count = 0.0;
  d_delta_f_key = pmt::string_to_symbol("delta_f");
  d_offset = 0;
}

/*
 * Our virtual destructor.
 */
frequency_locked_loop_ff_impl::~frequency_locked_loop_ff_impl() {}

int frequency_locked_loop_ff_impl::work(int noutput_items,
                                        gr_vector_const_void_star &input_items,
                                        gr_vector_void_star &output_items) {
  float *in = (float *)input_items[0];
  float *out = (float *)output_items[0];
  int i;

  // Do <+signal processing+>
  for (i=0; i<noutput_items; i++)
  {
    if ((in[i] < -3.0 + d_delta_f) && (in[i] > -3.0 + d_delta_f - d_rolloff))
    {
      d_derivative += sin((in[i] + 3.0 - d_delta_f)*M_PI/d_rolloff);
      d_count++;
    }
    else if ((in[i] > 3 + d_delta_f) && (in[i] < 3 + d_delta_f + d_rolloff))
    {
      d_derivative += sin((in[i] - 3.0 - d_delta_f)*M_PI/d_rolloff);
      d_count++;
    }

    out[i] = in[i] - d_delta_f;

    if (d_count == d_samples)
    {
      d_delta_f += d_derivative/((float) d_count);
      d_derivative = 0.0;
      d_count = 0;
      add_item_tag(0, d_offset + i, d_delta_f_key, pmt::from_float(d_delta_f));
    }
  }

  d_offset += noutput_items;
  // Tell runtime system how many output items we produced.
  return noutput_items;
}

} /* namespace fll */
} /* namespace gr */
