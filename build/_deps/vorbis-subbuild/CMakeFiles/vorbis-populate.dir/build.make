# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild

# Utility rule file for vorbis-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/vorbis-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/vorbis-populate.dir/progress.make

CMakeFiles/vorbis-populate: CMakeFiles/vorbis-populate-complete

CMakeFiles/vorbis-populate-complete: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-install
CMakeFiles/vorbis-populate-complete: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-mkdir
CMakeFiles/vorbis-populate-complete: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-download
CMakeFiles/vorbis-populate-complete: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update
CMakeFiles/vorbis-populate-complete: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-patch
CMakeFiles/vorbis-populate-complete: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-configure
CMakeFiles/vorbis-populate-complete: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-build
CMakeFiles/vorbis-populate-complete: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-install
CMakeFiles/vorbis-populate-complete: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'vorbis-populate'"
	"C:\Program Files\CMake\bin\cmake.exe" -E make_directory C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/CMakeFiles
	"C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/CMakeFiles/vorbis-populate-complete
	"C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-done

vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update:
.PHONY : vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update

vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-build: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'vorbis-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-build && "C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-build && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-build

vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-configure: vorbis-populate-prefix/tmp/vorbis-populate-cfgcmd.txt
vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-configure: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'vorbis-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-build && "C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-build && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-configure

vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-download: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-gitinfo.txt
vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-download: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'vorbis-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps && "C:\Program Files\CMake\bin\cmake.exe" -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/tmp/vorbis-populate-gitclone.cmake
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-download

vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-install: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'vorbis-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-build && "C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-build && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-install

vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'vorbis-populate'"
	"C:\Program Files\CMake\bin\cmake.exe" -Dcfgdir= -P C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/tmp/vorbis-populate-mkdirs.cmake
	"C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-mkdir

vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-patch: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-patch-info.txt
vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-patch: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing patch step for 'vorbis-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-src && "C:\Program Files\CMake\bin\cmake.exe" -DVORBIS_DIR=C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-src -P C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/sfml-src/tools/vorbis/PatchVorbis.cmake
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-src && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-patch

vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update:
.PHONY : vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update

vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-test: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'vorbis-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-build && "C:\Program Files\CMake\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-build && "C:\Program Files\CMake\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-test

vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update: vorbis-populate-prefix/tmp/vorbis-populate-gitupdate.cmake
vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update-info.txt
vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'vorbis-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-src && "C:\Program Files\CMake\bin\cmake.exe" -Dcan_fetch=YES -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P C:/Users/sdwor/Desktop/COMP345/Comp345_Groupe_project/build/_deps/vorbis-subbuild/vorbis-populate-prefix/tmp/vorbis-populate-gitupdate.cmake

CMakeFiles/vorbis-populate.dir/codegen:
.PHONY : CMakeFiles/vorbis-populate.dir/codegen

vorbis-populate: CMakeFiles/vorbis-populate
vorbis-populate: CMakeFiles/vorbis-populate-complete
vorbis-populate: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-build
vorbis-populate: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-configure
vorbis-populate: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-download
vorbis-populate: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-install
vorbis-populate: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-mkdir
vorbis-populate: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-patch
vorbis-populate: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-test
vorbis-populate: vorbis-populate-prefix/src/vorbis-populate-stamp/vorbis-populate-update
vorbis-populate: CMakeFiles/vorbis-populate.dir/build.make
.PHONY : vorbis-populate

# Rule to build all files generated by this target.
CMakeFiles/vorbis-populate.dir/build: vorbis-populate
.PHONY : CMakeFiles/vorbis-populate.dir/build

CMakeFiles/vorbis-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\vorbis-populate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/vorbis-populate.dir/clean

CMakeFiles/vorbis-populate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild C:\Users\sdwor\Desktop\COMP345\Comp345_Groupe_project\build\_deps\vorbis-subbuild\CMakeFiles\vorbis-populate.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/vorbis-populate.dir/depend

