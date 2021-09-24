#include "ruby.h"

uint64_t number;

void Init_count_bits_swar();
VALUE method_count_bits_swar(VALUE self, VALUE num);

void Init_count_bits_swar() {
  rb_define_global_function("count_bits", method_count_bits_swar, 1);
  rb_define_global_function("count_bits_swar", method_count_bits_swar, 1);
}

int pop_cnt_64(uint64_t i) {
  i = i - ((i >> 1) & 0x5555555555555555);
  i = (i & 0x3333333333333333) + ((i >> 2) & 0x3333333333333333);
  return (((i + (i >> 4)) & 0x0F0F0F0F0F0F0F0F) * 0x0101010101010101) >> 56;
}

VALUE method_count_bits_swar(VALUE self, VALUE num) {
  number = NUM2ULL(num);
  return INT2NUM(pop_cnt_64(number));
}
