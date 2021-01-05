gtest = dependency('gtest', main:true)
executable(
  'base64',
  sources: ['main.cc'],
  include_directories: src
)

test(
  'base64',
  executable(
    'base64_tets', 
    sources : ['base64_test.cc'],
    include_directories : src,
    dependencies : [gtest]
  )
)
