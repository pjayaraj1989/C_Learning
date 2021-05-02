
env = Environment()

# gcc or clang
env.Replace(CC = "gcc")

#libraries
source_files = Glob('#src/*.c')

# exe file name
test_exe = 'test_exe'

# # c flags
cflags = ['-g', '-Wall']


# include paths
env.Append(CPPPATH='#include')


# exe creation
exe = env.Program(test_exe, source_files,)

