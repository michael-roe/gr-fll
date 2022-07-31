/* -*- c++ -*- */
/*
 * Copyright 2022 Michael Roe.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_FLL_FREQUENCY_LOCKED_LOOP_FF_H
#define INCLUDED_FLL_FREQUENCY_LOCKED_LOOP_FF_H

#include <gnuradio/fll/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
namespace fll {

/*!
 * \brief <+description of block+>
 * \ingroup fll
 *
 */
class FLL_API frequency_locked_loop_ff : virtual public gr::sync_block {
public:
  typedef std::shared_ptr<frequency_locked_loop_ff> sptr;

  /*!
   * \brief Return a shared_ptr to a new instance of
   * fll::frequency_locked_loop_ff.
   *
   * To avoid accidental use of raw pointers, fll::frequency_locked_loop_ff's
   * constructor is in a private implementation
   * class. fll::frequency_locked_loop_ff::make is the public interface for
   * creating new instances.
   */
  static sptr make(float rolloff, int samples);
};

} // namespace fll
} // namespace gr

#endif /* INCLUDED_FLL_FREQUENCY_LOCKED_LOOP_FF_H */
