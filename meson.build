project(
  'testproject',
  'cpp',
  version: '0.1',
  default_options: [
    'warning_level=2',
    'cpp_std=c++20',
    'c_std=c17',
    'default_library=static',
  ],
)

# Windows compilation has no pre-packaged SDL2 available, and compilation takes a while.
# If you want to compile from source, remove everything but the contents of the else clause.


if host_machine.system() == 'linux'
  compiler_flags = [
    '-Wconversion',
    '-fdiagnostics-color=always',
    '-Werror=return-type',
  ]
else
  compiler_flags = [
    '-Wconversion',
    '-fdiagnostics-color=always',
    '-Werror=return-type',
    '-fcolor-diagnostics',
    '-fansi-escape-codes',
  ]
endif

src = []

exe = executable(
  'program',
  src,
  'main.cpp',
  'bingoCardGenerator.cpp',
  cpp_args: compiler_flags,
)
