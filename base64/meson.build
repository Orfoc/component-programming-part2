project(
  'base64',
  'cpp',
  version: '0.1.0',
  meson_version: '>=0.50.0',
  default_options: ['cpp_std=c++2a']
)
subdir('src')

doxygen = find_program('doxygen', required : false)
run_target('docs', command : [doxygen, meson.source_root() + '/doxygen_config'])
