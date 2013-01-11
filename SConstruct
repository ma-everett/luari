
env=Environment(CCFLAGS = "-g")

lib_name = 'grt_ri'
list = Split( """
		./src/main.cpp 
		./src/context.cpp
		./src/stream.cpp
		./src/rib.cpp
		""")

lib = env.SharedLibrary(target=lib_name, source=list)
