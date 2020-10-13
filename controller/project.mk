PROJECT_MODULES = src/tmp_control.c  \

PROJECT_TESTS   = tests/test_tmp_control.c \
# C source files
PROJECT_CSRC 	= src/main.c $(PROJECT_MODULES) $(PROJECT_TESTS) 
# C++ source files
PROJECT_CPPSRC 	= 
# Directories to search headers in
PROJECT_INCDIR	= include/
# Additional libraries
PROJECT_LIBS	=
# Compiler options
PROJECT_OPT     =

# Additional .mk files are included here
