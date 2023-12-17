
project('aqua driver', 'cpp')

if not meson.is_cross_build()
  error('Cross-compilation for AVR is not enabled. Please configure with \'--cross-file avr.txt\' option')
endif

avr_sources = ['src/main.cpp']

avr_exe = executable('main_uC', avr_sources, cpp_args : ['-DF_CPU=4000000', '-mmcu=attiny2313'])

avr_objdump_target = custom_target(
    'avr_objdump',
    command: ['avr-objdump', '-d', '@INPUT@'],
    capture: true,
    input: avr_exe,
    output: 'driver.lst',
    build_always: true
)
