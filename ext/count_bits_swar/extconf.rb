require 'mkmf'

$CFLAGS << ' -O3'
create_makefile("count_bits/count_bits_swar")

