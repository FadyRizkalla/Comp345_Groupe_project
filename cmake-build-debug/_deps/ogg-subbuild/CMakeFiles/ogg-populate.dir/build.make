# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild

# Utility rule file for ogg-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/ogg-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ogg-populate.dir/progress.make

CMakeFiles/ogg-populate: CMakeFiles/ogg-populate-complete

CMakeFiles/ogg-populate-complete: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-install
CMakeFiles/ogg-populate-complete: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-mkdir
CMakeFiles/ogg-populate-complete: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-download
CMakeFiles/ogg-populate-complete: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update
CMakeFiles/ogg-populate-complete: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-patch
CMakeFiles/ogg-populate-complete: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-configure
CMakeFiles/ogg-populate-complete: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-build
CMakeFiles/ogg-populate-complete: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-install
CMakeFiles/ogg-populate-complete: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'ogg-populate'"
	"C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E make_directory C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/CMakeFiles
	"C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/CMakeFiles/ogg-populate-complete
	"C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-done

ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update:
.PHONY : ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update

ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-build: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'ogg-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-build && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-build && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-build

ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-configure: ogg-populate-prefix/tmp/ogg-populate-cfgcmd.txt
ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-configure: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'ogg-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-build && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-build && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-configure

ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-download: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-gitinfo.txt
ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-download: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'ogg-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/tmp/ogg-populate-gitclone.cmake
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-download

ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-install: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'ogg-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-build && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-build && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-install

ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'ogg-populate'"
	"C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -Dcfgdir= -P C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/tmp/ogg-populate-mkdirs.cmake
	"C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-mkdir

ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-patch: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-patch-info.txt
ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-patch: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing patch step for 'ogg-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-src && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -DOGG_DIR=C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-src -P C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/sfml-src/tools/ogg/PatchOgg.cmake
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-src && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-patch

ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update:
.PHONY : ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update

ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-test: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'ogg-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-build && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E echo_append
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-build && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -E touch C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-test

ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update: ogg-populate-prefix/tmp/ogg-populate-gitupdate.cmake
ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update-info.txt
ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'ogg-populate'"
	cd /d C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-src && "C:\Program Files\JetBrains\CLion 2024.3.4\bin\cmake\win\x64\bin\cmake.exe" -Dcan_fetch=YES -DCMAKE_MESSAGE_LOG_LEVEL=VERBOSE -P C:/Users/sdwor/Desktop/COMP345A1/Comp345_Groupe_project/cmake-build-debug/_deps/ogg-subbuild/ogg-populate-prefix/tmp/ogg-populate-gitupdate.cmake

ogg-populate: CMakeFiles/ogg-populate
ogg-populate: CMakeFiles/ogg-populate-complete
ogg-populate: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-build
ogg-populate: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-configure
ogg-populate: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-download
ogg-populate: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-install
ogg-populate: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-mkdir
ogg-populate: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-patch
ogg-populate: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-test
ogg-populate: ogg-populate-prefix/src/ogg-populate-stamp/ogg-populate-update
ogg-populate: CMakeFiles/ogg-populate.dir/build.make
.PHONY : ogg-populate

# Rule to build all files generated by this target.
CMakeFiles/ogg-populate.dir/build: ogg-populate
.PHONY : CMakeFiles/ogg-populate.dir/build

CMakeFiles/ogg-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ogg-populate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ogg-populate.dir/clean

CMakeFiles/ogg-populate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild C:\Users\sdwor\Desktop\COMP345A1\Comp345_Groupe_project\cmake-build-debug\_deps\ogg-subbuild\CMakeFiles\ogg-populate.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ogg-populate.dir/depend

