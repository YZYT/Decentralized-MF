# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake-3.21/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.21/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/research/RS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/research/RS/build

# Include any dependencies generated for this target.
include CMakeFiles/RS.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RS.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RS.dir/flags.make

CMakeFiles/RS.dir/main.cpp.o: CMakeFiles/RS.dir/flags.make
CMakeFiles/RS.dir/main.cpp.o: ../main.cpp
CMakeFiles/RS.dir/main.cpp.o: CMakeFiles/RS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/research/RS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RS.dir/main.cpp.o"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RS.dir/main.cpp.o -MF CMakeFiles/RS.dir/main.cpp.o.d -o CMakeFiles/RS.dir/main.cpp.o -c /root/research/RS/main.cpp

CMakeFiles/RS.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RS.dir/main.cpp.i"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/research/RS/main.cpp > CMakeFiles/RS.dir/main.cpp.i

CMakeFiles/RS.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RS.dir/main.cpp.s"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/research/RS/main.cpp -o CMakeFiles/RS.dir/main.cpp.s

CMakeFiles/RS.dir/Data.cpp.o: CMakeFiles/RS.dir/flags.make
CMakeFiles/RS.dir/Data.cpp.o: ../Data.cpp
CMakeFiles/RS.dir/Data.cpp.o: CMakeFiles/RS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/research/RS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RS.dir/Data.cpp.o"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RS.dir/Data.cpp.o -MF CMakeFiles/RS.dir/Data.cpp.o.d -o CMakeFiles/RS.dir/Data.cpp.o -c /root/research/RS/Data.cpp

CMakeFiles/RS.dir/Data.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RS.dir/Data.cpp.i"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/research/RS/Data.cpp > CMakeFiles/RS.dir/Data.cpp.i

CMakeFiles/RS.dir/Data.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RS.dir/Data.cpp.s"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/research/RS/Data.cpp -o CMakeFiles/RS.dir/Data.cpp.s

CMakeFiles/RS.dir/Client.cpp.o: CMakeFiles/RS.dir/flags.make
CMakeFiles/RS.dir/Client.cpp.o: ../Client.cpp
CMakeFiles/RS.dir/Client.cpp.o: CMakeFiles/RS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/research/RS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RS.dir/Client.cpp.o"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RS.dir/Client.cpp.o -MF CMakeFiles/RS.dir/Client.cpp.o.d -o CMakeFiles/RS.dir/Client.cpp.o -c /root/research/RS/Client.cpp

CMakeFiles/RS.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RS.dir/Client.cpp.i"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/research/RS/Client.cpp > CMakeFiles/RS.dir/Client.cpp.i

CMakeFiles/RS.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RS.dir/Client.cpp.s"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/research/RS/Client.cpp -o CMakeFiles/RS.dir/Client.cpp.s

CMakeFiles/RS.dir/Server.cpp.o: CMakeFiles/RS.dir/flags.make
CMakeFiles/RS.dir/Server.cpp.o: ../Server.cpp
CMakeFiles/RS.dir/Server.cpp.o: CMakeFiles/RS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/research/RS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RS.dir/Server.cpp.o"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RS.dir/Server.cpp.o -MF CMakeFiles/RS.dir/Server.cpp.o.d -o CMakeFiles/RS.dir/Server.cpp.o -c /root/research/RS/Server.cpp

CMakeFiles/RS.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RS.dir/Server.cpp.i"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/research/RS/Server.cpp > CMakeFiles/RS.dir/Server.cpp.i

CMakeFiles/RS.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RS.dir/Server.cpp.s"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/research/RS/Server.cpp -o CMakeFiles/RS.dir/Server.cpp.s

CMakeFiles/RS.dir/Base.cpp.o: CMakeFiles/RS.dir/flags.make
CMakeFiles/RS.dir/Base.cpp.o: ../Base.cpp
CMakeFiles/RS.dir/Base.cpp.o: CMakeFiles/RS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/research/RS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RS.dir/Base.cpp.o"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RS.dir/Base.cpp.o -MF CMakeFiles/RS.dir/Base.cpp.o.d -o CMakeFiles/RS.dir/Base.cpp.o -c /root/research/RS/Base.cpp

CMakeFiles/RS.dir/Base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RS.dir/Base.cpp.i"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/research/RS/Base.cpp > CMakeFiles/RS.dir/Base.cpp.i

CMakeFiles/RS.dir/Base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RS.dir/Base.cpp.s"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/research/RS/Base.cpp -o CMakeFiles/RS.dir/Base.cpp.s

CMakeFiles/RS.dir/Builder.cpp.o: CMakeFiles/RS.dir/flags.make
CMakeFiles/RS.dir/Builder.cpp.o: ../Builder.cpp
CMakeFiles/RS.dir/Builder.cpp.o: CMakeFiles/RS.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/research/RS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RS.dir/Builder.cpp.o"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RS.dir/Builder.cpp.o -MF CMakeFiles/RS.dir/Builder.cpp.o.d -o CMakeFiles/RS.dir/Builder.cpp.o -c /root/research/RS/Builder.cpp

CMakeFiles/RS.dir/Builder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RS.dir/Builder.cpp.i"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/research/RS/Builder.cpp > CMakeFiles/RS.dir/Builder.cpp.i

CMakeFiles/RS.dir/Builder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RS.dir/Builder.cpp.s"
	/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/research/RS/Builder.cpp -o CMakeFiles/RS.dir/Builder.cpp.s

# Object files for target RS
RS_OBJECTS = \
"CMakeFiles/RS.dir/main.cpp.o" \
"CMakeFiles/RS.dir/Data.cpp.o" \
"CMakeFiles/RS.dir/Client.cpp.o" \
"CMakeFiles/RS.dir/Server.cpp.o" \
"CMakeFiles/RS.dir/Base.cpp.o" \
"CMakeFiles/RS.dir/Builder.cpp.o"

# External object files for target RS
RS_EXTERNAL_OBJECTS =

RS: CMakeFiles/RS.dir/main.cpp.o
RS: CMakeFiles/RS.dir/Data.cpp.o
RS: CMakeFiles/RS.dir/Client.cpp.o
RS: CMakeFiles/RS.dir/Server.cpp.o
RS: CMakeFiles/RS.dir/Base.cpp.o
RS: CMakeFiles/RS.dir/Builder.cpp.o
RS: CMakeFiles/RS.dir/build.make
RS: CMakeFiles/RS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/research/RS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable RS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RS.dir/build: RS
.PHONY : CMakeFiles/RS.dir/build

CMakeFiles/RS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RS.dir/clean

CMakeFiles/RS.dir/depend:
	cd /root/research/RS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/research/RS /root/research/RS /root/research/RS/build /root/research/RS/build /root/research/RS/build/CMakeFiles/RS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RS.dir/depend

