sysinc = '/usr/include/'
syslib = '/usr/lib/'
localinc = ['src/', 'include/']
libs = ['raylib', 'glfw', 'GL']

flags =['-fPIC', '-O2', '-std=gnu17', '-w']

basefiles = ['src/pch.h', Glob('src/engine/*.c'), Glob('src/basegame/*.c'), Glob('src/common/*.c')]

clientfiles = [Glob('src/client/*.c')]
Program('bin/engine.e', basefiles + clientfiles,CCFLAGS=flags, CPPPATH=[sysinc, localinc], LIBPATH=[syslib],LIBS=[libs])
