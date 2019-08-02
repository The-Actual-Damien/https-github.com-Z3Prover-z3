/*++
  Copyright (c) 2017 Microsoft Corporation

  Module Name:

  <name>

  Abstract:

  <abstract>

  Author:
  Nikolaj Bjorner (nbjorner)
  Lev Nachmanson (levnach)

  Revision History:


  --*/
#pragma once

#include "math/lp/nla_common.h"
#include "math/lp/nla_intervals.h"
#include "math/lp/nla_expr.h"

namespace nla {
class core;


class horner : common {
    intervals m_intervals;
public:
    typedef nla_expr<rational> nex;
    
    horner(core *core);
    void horner_lemmas();
    template <typename T> // T has an iterator of (coeff(), var())
    bool lemmas_on_row(const T&);
    template <typename T>  bool row_is_interesting(const T&) const;
    template <typename T> nex create_sum_from_row(const T&);
    intervals::interval interval_of_expr(const nex& e);
    
    nex nexvar(lpvar j) const;
    intervals::interval interval_of_sum(const nex&);
    intervals::interval interval_of_mul(const nex&);
    void set_interval_for_scalar(intervals::interval&, const rational&);
    void set_var_interval(lpvar j, intervals::interval&);
    bool lemmas_on_expr(nex &);
    
    template <typename T> // T has an iterator of (coeff(), var())
    bool row_has_monomial_to_refine(const T&) const;
    bool find_term_expr(rational& a, const lp::lar_term * & t, rational& b) const;
}; // end of horner
}