#include "ruby.h"

uint8_t *pre_computed_25 = NULL;
uint64_t number;

void Init_count_bits_pre();
VALUE method_count_bits_pre(VALUE self, VALUE num);
int popcnt(unsigned long long i);

void Init_count_bits_pre() {
  uint32_t idx = (uint32_t) 0;
  uint32_t max = (1L << 25);

  pre_computed_25 = malloc((max + 1) * sizeof *pre_computed_25);
  if (pre_computed_25 == NULL) {
    rb_raise(rb_eRuntimeError, "Error: not enough memory\n");
  }

  for (idx = 0; idx < max; idx++) {
    pre_computed_25[idx] = popcnt(idx);
  }

  rb_define_global_function("count_bits", method_count_bits_pre, 1);
  rb_define_global_function("count_bits_pre", method_count_bits_pre, 1);
}

VALUE method_count_bits_pre(VALUE self, VALUE num) {
  number = NUM2ULL(num);
  return INT2NUM(pre_computed_25[(number & 0b1111111111111111111111111)] +
          pre_computed_25[(number >> 25 & 0b1111111111111111111111111)]);
}

//"bit_elimination_for"
int popcnt(unsigned long long i) {
  int c = 0;
  for (; i; c++) {
    i &= i - 1;
  }
  return c;
}