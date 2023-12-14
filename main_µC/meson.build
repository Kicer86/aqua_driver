
project('aqua driver', 'cpp')

avr_target = 'avr'
host_target = 'host'

avr_sources = ['src/main.cpp']

avr_exe = executable('main_uC', avr_sources, cpp_args : ['-DF_CPU=4000000', '-mmcu=attiny2313'])

avr_objdump_target = custom_target(
    'avr_objdump',
    command: ['avr-objdump', '-d', '@INPUT@', '>', '@OUTPUT@'],
    input: avr_exe,
    output: 'driver.lst',
    build_always: true
)
