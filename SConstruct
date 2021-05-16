import os

env = Environment()

# gcc or clang
env.Replace(CC = "gcc")

# test
test_src = 'test_main.c'

# exe file name
test_exe = 'test_exe'

# # c flags
cflags = ['-g', '-Wall']

# include paths
inc_path = '#src/include'
env.Append(CPPPATH=inc_path)

# build lib
src_path = '#src'
libs = SConscript(os.path.join(src_path, 'SConscript'),)

# exe creation
exe = env.Program(test_exe, test_src, LIBS=libs)

