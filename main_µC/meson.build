
project('aqua driver', 'cpp')

if not meson.is_cross_build()
  error('Cross-compilation for AVR is not enabled. Please configure with \'--cross-file avr.txt\' option')
endif

avr_sources = ['src/main.cpp']

incdir  = include_directories(
  'avr-libstdcpp/include',
  'avr-lib/include'
)

avr_exe = executable(
  'main_uC',
  avr_sources,
  cpp_args : [
    '-DF_CPU=8000000',
    '-mmcu=attiny2313',
    '-std=c++20',
    '--param=min-pagesize=0'                      # TODO: without it gcc generates warnings like here: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=105523 but only in certain files
  ],
  include_directories : incdir,
  link_args : ['-mmcu=attiny2313']
)

avr_objdump_target = custom_target(
    'avr_objdump',
    command: ['avr-objdump', '-d', '@INPUT@'],
    capture: true,
    input: avr_exe,
    output: 'driver.lst',
    build_always: true
)
