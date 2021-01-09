executable(
  'vector',
  include_directories : src,
  sources : ['main.cc'],
  install : true
  )
gtest = dependency('gtest', main : true)
test(
  'vector',
  executable(
    'vector_tests',
    sources : ['vector_test.cc'],
    include_directories : src,
    dependencies : [gtest]
    )
)
