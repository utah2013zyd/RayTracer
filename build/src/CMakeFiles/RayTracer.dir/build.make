# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/stow/cmake/cmake-2.8.2/bin/cmake

# The command to remove a file.
RM = /usr/local/stow/cmake/cmake-2.8.2/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/stow/cmake/cmake-2.8.2/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yuedongz/RayTracer/RayTracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yuedongz/RayTracer/RayTracer/build

# Include any dependencies generated for this target.
include src/CMakeFiles/RayTracer.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/RayTracer.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/RayTracer.dir/flags.make

src/CMakeFiles/RayTracer.dir/main.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/main.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/main.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/main.cpp

src/CMakeFiles/RayTracer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/main.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/main.cpp > CMakeFiles/RayTracer.dir/main.cpp.i

src/CMakeFiles/RayTracer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/main.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/main.cpp -o CMakeFiles/RayTracer.dir/main.cpp.s

src/CMakeFiles/RayTracer.dir/main.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/main.cpp.o.requires

src/CMakeFiles/RayTracer.dir/main.cpp.o.provides: src/CMakeFiles/RayTracer.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/main.cpp.o.provides

src/CMakeFiles/RayTracer.dir/main.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/main.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/main.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/lights.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/lights.cpp.o: ../src/lights.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/lights.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/lights.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/lights.cpp

src/CMakeFiles/RayTracer.dir/lights.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/lights.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/lights.cpp > CMakeFiles/RayTracer.dir/lights.cpp.i

src/CMakeFiles/RayTracer.dir/lights.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/lights.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/lights.cpp -o CMakeFiles/RayTracer.dir/lights.cpp.s

src/CMakeFiles/RayTracer.dir/lights.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/lights.cpp.o.requires

src/CMakeFiles/RayTracer.dir/lights.cpp.o.provides: src/CMakeFiles/RayTracer.dir/lights.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/lights.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/lights.cpp.o.provides

src/CMakeFiles/RayTracer.dir/lights.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/lights.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/lights.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/Math.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/Math.cpp.o: ../src/Math.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/Math.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/Math.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/Math.cpp

src/CMakeFiles/RayTracer.dir/Math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/Math.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/Math.cpp > CMakeFiles/RayTracer.dir/Math.cpp.i

src/CMakeFiles/RayTracer.dir/Math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/Math.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/Math.cpp -o CMakeFiles/RayTracer.dir/Math.cpp.s

src/CMakeFiles/RayTracer.dir/Math.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/Math.cpp.o.requires

src/CMakeFiles/RayTracer.dir/Math.cpp.o.provides: src/CMakeFiles/RayTracer.dir/Math.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/Math.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/Math.cpp.o.provides

src/CMakeFiles/RayTracer.dir/Math.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/Math.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/Math.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/photonmap.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/photonmap.cpp.o: ../src/photonmap.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/photonmap.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/photonmap.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/photonmap.cpp

src/CMakeFiles/RayTracer.dir/photonmap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/photonmap.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/photonmap.cpp > CMakeFiles/RayTracer.dir/photonmap.cpp.i

src/CMakeFiles/RayTracer.dir/photonmap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/photonmap.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/photonmap.cpp -o CMakeFiles/RayTracer.dir/photonmap.cpp.s

src/CMakeFiles/RayTracer.dir/photonmap.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/photonmap.cpp.o.requires

src/CMakeFiles/RayTracer.dir/photonmap.cpp.o.provides: src/CMakeFiles/RayTracer.dir/photonmap.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/photonmap.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/photonmap.cpp.o.provides

src/CMakeFiles/RayTracer.dir/photonmap.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/photonmap.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/photonmap.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/Tracer.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/Tracer.cpp.o: ../src/Tracer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/Tracer.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/Tracer.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/Tracer.cpp

src/CMakeFiles/RayTracer.dir/Tracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/Tracer.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/Tracer.cpp > CMakeFiles/RayTracer.dir/Tracer.cpp.i

src/CMakeFiles/RayTracer.dir/Tracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/Tracer.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/Tracer.cpp -o CMakeFiles/RayTracer.dir/Tracer.cpp.s

src/CMakeFiles/RayTracer.dir/Tracer.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/Tracer.cpp.o.requires

src/CMakeFiles/RayTracer.dir/Tracer.cpp.o.provides: src/CMakeFiles/RayTracer.dir/Tracer.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/Tracer.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/Tracer.cpp.o.provides

src/CMakeFiles/RayTracer.dir/Tracer.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/Tracer.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/Tracer.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/object.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/object.cpp.o: ../src/object.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/object.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/object.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/object.cpp

src/CMakeFiles/RayTracer.dir/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/object.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/object.cpp > CMakeFiles/RayTracer.dir/object.cpp.i

src/CMakeFiles/RayTracer.dir/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/object.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/object.cpp -o CMakeFiles/RayTracer.dir/object.cpp.s

src/CMakeFiles/RayTracer.dir/object.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/object.cpp.o.requires

src/CMakeFiles/RayTracer.dir/object.cpp.o.provides: src/CMakeFiles/RayTracer.dir/object.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/object.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/object.cpp.o.provides

src/CMakeFiles/RayTracer.dir/object.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/object.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/object.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/Renderer.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/Renderer.cpp.o: ../src/Renderer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/Renderer.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/Renderer.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/Renderer.cpp

src/CMakeFiles/RayTracer.dir/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/Renderer.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/Renderer.cpp > CMakeFiles/RayTracer.dir/Renderer.cpp.i

src/CMakeFiles/RayTracer.dir/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/Renderer.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/Renderer.cpp -o CMakeFiles/RayTracer.dir/Renderer.cpp.s

src/CMakeFiles/RayTracer.dir/Renderer.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/Renderer.cpp.o.requires

src/CMakeFiles/RayTracer.dir/Renderer.cpp.o.provides: src/CMakeFiles/RayTracer.dir/Renderer.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/Renderer.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/Renderer.cpp.o.provides

src/CMakeFiles/RayTracer.dir/Renderer.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/Renderer.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/Renderer.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/xmlload.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/xmlload.cpp.o: ../src/xmlload.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/xmlload.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/xmlload.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/xmlload.cpp

src/CMakeFiles/RayTracer.dir/xmlload.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/xmlload.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/xmlload.cpp > CMakeFiles/RayTracer.dir/xmlload.cpp.i

src/CMakeFiles/RayTracer.dir/xmlload.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/xmlload.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/xmlload.cpp -o CMakeFiles/RayTracer.dir/xmlload.cpp.s

src/CMakeFiles/RayTracer.dir/xmlload.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/xmlload.cpp.o.requires

src/CMakeFiles/RayTracer.dir/xmlload.cpp.o.provides: src/CMakeFiles/RayTracer.dir/xmlload.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/xmlload.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/xmlload.cpp.o.provides

src/CMakeFiles/RayTracer.dir/xmlload.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/xmlload.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/xmlload.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/materials.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/materials.cpp.o: ../src/materials.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/materials.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/materials.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/materials.cpp

src/CMakeFiles/RayTracer.dir/materials.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/materials.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/materials.cpp > CMakeFiles/RayTracer.dir/materials.cpp.i

src/CMakeFiles/RayTracer.dir/materials.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/materials.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/materials.cpp -o CMakeFiles/RayTracer.dir/materials.cpp.s

src/CMakeFiles/RayTracer.dir/materials.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/materials.cpp.o.requires

src/CMakeFiles/RayTracer.dir/materials.cpp.o.provides: src/CMakeFiles/RayTracer.dir/materials.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/materials.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/materials.cpp.o.provides

src/CMakeFiles/RayTracer.dir/materials.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/materials.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/materials.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o: ../src/PhotonGenerator.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/PhotonGenerator.cpp

src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/PhotonGenerator.cpp > CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.i

src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/PhotonGenerator.cpp -o CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.s

src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o.requires

src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o.provides: src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o.provides

src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/texture.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/texture.cpp.o: ../src/texture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/texture.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/texture.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/texture.cpp

src/CMakeFiles/RayTracer.dir/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/texture.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/texture.cpp > CMakeFiles/RayTracer.dir/texture.cpp.i

src/CMakeFiles/RayTracer.dir/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/texture.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/texture.cpp -o CMakeFiles/RayTracer.dir/texture.cpp.s

src/CMakeFiles/RayTracer.dir/texture.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/texture.cpp.o.requires

src/CMakeFiles/RayTracer.dir/texture.cpp.o.provides: src/CMakeFiles/RayTracer.dir/texture.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/texture.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/texture.cpp.o.provides

src/CMakeFiles/RayTracer.dir/texture.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/texture.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/texture.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/tinystr.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/tinystr.cpp.o: ../src/tinystr.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/tinystr.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/tinystr.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/tinystr.cpp

src/CMakeFiles/RayTracer.dir/tinystr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/tinystr.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/tinystr.cpp > CMakeFiles/RayTracer.dir/tinystr.cpp.i

src/CMakeFiles/RayTracer.dir/tinystr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/tinystr.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/tinystr.cpp -o CMakeFiles/RayTracer.dir/tinystr.cpp.s

src/CMakeFiles/RayTracer.dir/tinystr.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/tinystr.cpp.o.requires

src/CMakeFiles/RayTracer.dir/tinystr.cpp.o.provides: src/CMakeFiles/RayTracer.dir/tinystr.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/tinystr.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/tinystr.cpp.o.provides

src/CMakeFiles/RayTracer.dir/tinystr.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/tinystr.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/tinystr.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o: ../src/tinyxml.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/tinyxml.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/tinyxml.cpp

src/CMakeFiles/RayTracer.dir/tinyxml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/tinyxml.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/tinyxml.cpp > CMakeFiles/RayTracer.dir/tinyxml.cpp.i

src/CMakeFiles/RayTracer.dir/tinyxml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/tinyxml.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/tinyxml.cpp -o CMakeFiles/RayTracer.dir/tinyxml.cpp.s

src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o.requires

src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o.provides: src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o.provides

src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o: ../src/tinyxmlerror.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/tinyxmlerror.cpp

src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/tinyxmlerror.cpp > CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.i

src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/tinyxmlerror.cpp -o CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.s

src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o.requires

src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o.provides: src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o.provides

src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o.provides.build

src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o: src/CMakeFiles/RayTracer.dir/flags.make
src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o: ../src/tinyxmlparser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yuedongz/RayTracer/RayTracer/build/CMakeFiles $(CMAKE_PROGRESS_15)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o -c /home/yuedongz/RayTracer/RayTracer/src/tinyxmlparser.cpp

src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.i"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yuedongz/RayTracer/RayTracer/src/tinyxmlparser.cpp > CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.i

src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.s"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yuedongz/RayTracer/RayTracer/src/tinyxmlparser.cpp -o CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.s

src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o.requires:
.PHONY : src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o.requires

src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o.provides: src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/RayTracer.dir/build.make src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o.provides.build
.PHONY : src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o.provides

src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o.provides.build: src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o
.PHONY : src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o.provides.build

# Object files for target RayTracer
RayTracer_OBJECTS = \
"CMakeFiles/RayTracer.dir/main.cpp.o" \
"CMakeFiles/RayTracer.dir/lights.cpp.o" \
"CMakeFiles/RayTracer.dir/Math.cpp.o" \
"CMakeFiles/RayTracer.dir/photonmap.cpp.o" \
"CMakeFiles/RayTracer.dir/Tracer.cpp.o" \
"CMakeFiles/RayTracer.dir/object.cpp.o" \
"CMakeFiles/RayTracer.dir/Renderer.cpp.o" \
"CMakeFiles/RayTracer.dir/xmlload.cpp.o" \
"CMakeFiles/RayTracer.dir/materials.cpp.o" \
"CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o" \
"CMakeFiles/RayTracer.dir/texture.cpp.o" \
"CMakeFiles/RayTracer.dir/tinystr.cpp.o" \
"CMakeFiles/RayTracer.dir/tinyxml.cpp.o" \
"CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o" \
"CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o"

# External object files for target RayTracer
RayTracer_EXTERNAL_OBJECTS =

bin/RayTracer: src/CMakeFiles/RayTracer.dir/main.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/lights.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/Math.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/photonmap.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/Tracer.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/object.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/Renderer.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/xmlload.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/materials.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/texture.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/tinystr.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o
bin/RayTracer: src/CMakeFiles/RayTracer.dir/build.make
bin/RayTracer: src/CMakeFiles/RayTracer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/RayTracer"
	cd /home/yuedongz/RayTracer/RayTracer/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RayTracer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/RayTracer.dir/build: bin/RayTracer
.PHONY : src/CMakeFiles/RayTracer.dir/build

src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/main.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/lights.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/Math.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/photonmap.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/Tracer.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/object.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/Renderer.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/xmlload.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/materials.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/PhotonGenerator.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/texture.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/tinystr.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/tinyxml.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/tinyxmlerror.cpp.o.requires
src/CMakeFiles/RayTracer.dir/requires: src/CMakeFiles/RayTracer.dir/tinyxmlparser.cpp.o.requires
.PHONY : src/CMakeFiles/RayTracer.dir/requires

src/CMakeFiles/RayTracer.dir/clean:
	cd /home/yuedongz/RayTracer/RayTracer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/RayTracer.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/RayTracer.dir/clean

src/CMakeFiles/RayTracer.dir/depend:
	cd /home/yuedongz/RayTracer/RayTracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuedongz/RayTracer/RayTracer /home/yuedongz/RayTracer/RayTracer/src /home/yuedongz/RayTracer/RayTracer/build /home/yuedongz/RayTracer/RayTracer/build/src /home/yuedongz/RayTracer/RayTracer/build/src/CMakeFiles/RayTracer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/RayTracer.dir/depend
