gtest = dependency('gtest', main: true)
prjct_src = files(['vector.cc'])
prjct_tests = files(['vector_test.cc'])

test(
  'vector_tests',
  executable(
    'vector_test',
     include_directories: src,
     sources : prjct_tests,
     dependencies : [gtest],
  )
)  
