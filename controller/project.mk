PROJECT_MODULES = src/lld_drive_control.c  src/debug.c src/lld_encoder.c src/robot_odometry.c \

PROJECT_TESTS   = tests/test_lld_drive_control.c tests/test_debug.c \
                  tests/test_lld_encoder.c \
                  tests/test_robot_odometry.c \
                  tests/test_robot_odometry_speed.c\
# C source files
PROJECT_CSRC 	= src/main.c src/common.c $(PROJECT_MODULES) $(PROJECT_TESTS) 
# C++ source files
PROJECT_CPPSRC 	= 
# Directories to search headers in
PROJECT_INCDIR	= include/
# Additional libraries
PROJECT_LIBS	=
# Compiler options
PROJECT_OPT     =

# Additional .mk files are included here
