require 'mkmf'

$CFLAGS << ' -O3 -march=corei7'
create_makefile("count_bits/count_bits_gcc")
