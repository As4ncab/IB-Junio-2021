# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author S4yuM4ng0  (s4yum4ng0@random.com)
# @date Jun 24 2021

CXX = g++						         # The C++ compiler command
CXXFLAGS = -std=c++17 -Wall	 # The C++ compiler options (C++17, and warn all)
LDFLAGS =						         # The linker options (if any)

# The all target builds all of the programs handled by the makefile.
# This target has the dependency chain:
#     all -> switch-case -> switch-case.o -> switch-case.cc
all: switch-case 

# The switch-case target builds the switch-case executable.
switch-case: switch-case.o switch-case-main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Indicate that the all and clean targets do not
# correspond to actual files.
.PHONY: all clean

# The following rule is effectively built into make and
# therefore need not be explicitly specified:
# switch-case.o: switch-case.cc
	$(CXX) $(CXXFLAGS) -c $<

# The clean target removes all of the executable files
# and object files produced by the build process
# We can use it for additional housekeeping purposes
clean :
	rm -f switch-case *.o
	rm -rf *~ basura* b i
	rm -rf a.out
	find . -name '*~' -exec rm {} \;
	find . -name basura -exec rm {} \;
