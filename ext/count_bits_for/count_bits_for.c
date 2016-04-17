#include "ruby.h"

uint64_t number;
int pop_count = 0;

void Init_count_bits_for();
VALUE method_count_bits_for(VALUE self, VALUE num);

void Init_count_bits_for() {
  rb_define_global_function("count_bits", method_count_bits_for, 1);
  rb_define_global_function("count_bits_for", method_count_bits_for, 1);
}

VALUE method_count_bits_for(VALUE self, VALUE num) {
  number = NUM2ULL(num);
  pop_count = 0;
  for (; number; pop_count++) {number &= number - 1;}
  return INT2NUM(pop_count);
}