#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP
#include <cassert>
#include <iostream>

struct State {
  double s;
  double i;
  double r;

  State(double sus, double inf, double rec) : s{sus}, i{inf}, r{rec} {
    assert(!(s < 0));
    assert(!(i < 0));
    assert(!(r < 0));
  }
  State() {
    s = 0.;
    i = 0.;
    r = 0.;
  }
};

#endif
