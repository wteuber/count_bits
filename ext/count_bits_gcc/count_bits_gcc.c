#include "ruby.h"
#include <smmintrin.h>

uint64_t number;

void Init_count_bits_gcc();
VALUE method_count_bits_gcc(VALUE self, VALUE num);

void Init_count_bits_gcc() {
  rb_define_global_function("count_bits", method_count_bits_gcc, 1);
  rb_define_global_function("count_bits_gcc", method_count_bits_gcc, 1);
}

VALUE method_count_bits_gcc(VALUE self, VALUE num) {
  number = NUM2ULL(num);
  return INT2NUM(__builtin_popcountll(number));
}
