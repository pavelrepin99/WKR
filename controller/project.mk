PROJECT_TESTS   = tests/testGPT.c     \
                  tests/testLED1.c    \
                  tests/testLED2.c    \
                  tests/testPORT.c    \
# C source files
PROJECT_CSRC 	= src/main.c          \
                  $(PROJECT_TESTS)
  
# C++ source files
PROJECT_CPPSRC 	= 
# Directories to search headers in
PROJECT_INCDIR	= include/
# Additional libraries
PROJECT_LIBS	=
# Compiler options
PROJECT_OPT     =

# Additional .mk files are included here
