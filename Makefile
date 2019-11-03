# Author: Michael J. Fischer
# Date: September 4, 2018
# Modified by Ferhat Erata <ferhat@cs.yale.edu> on October 10, 2019

#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -std=c++17
OBJ = tools.o vcgen.o imp/imp-driver.o imp/ast/imp.o \
 imp/recognizer/imp-parser.o imp/recognizer/imp-scanner.o \
 gc/gc-driver.o gc/recognizer/gc-parser.o gc/ast/gc.o \
 gc/recognizer/gc-scanner.o
# gc/test.o
TARGET = vcgen
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)

debug: CXXFLAGS += -DDEBUG -g -Wall
debug: $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET) $(DEBUG)
#-----------------------------------------------------------
# Dependencies
# c++ -MM *.cpp >> Makefile
# c++ -MM imp/*.cpp >> Makefile
# c++ -MM imp/ast/*.cpp >> Makefile
# c++ -MM imp/recognizer/*.cpp >> Makefile
# ---
# c++ -MM  gc/*.cpp >> Makefile
# c++ -MM  gc/recognizer/*.cpp >> Makefile
# c++ -MM  gc/ast/*.cpp >> Makefile
tools.o: tools.cpp tools.hpp
vcgen.o: vcgen.cpp gc/compiler/smt-compiler.hpp \
 gc/compiler/../ast/visitor.hpp gc/compiler/../ast/gc.hpp \
 gc/gc-driver.hpp gc/recognizer/gc-parser.hpp gc/recognizer/../ast/gc.hpp \
 gc/recognizer/location.hh imp/ast/printer-visitor.hpp \
 imp/ast/visitor.hpp imp/ast/imp.hpp imp/compiler/gc-compiler.hpp \
 imp/compiler/../ast/visitor.hpp imp/imp-driver.hpp \
 imp/recognizer/imp-parser.hpp imp/recognizer/../ast/imp.hpp \
 imp/recognizer/location.hh solver/z3-solver.hpp tools.hpp
imp-driver.o: imp/imp-driver.cpp imp/imp-driver.hpp \
 imp/recognizer/imp-parser.hpp imp/recognizer/../ast/imp.hpp \
 imp/recognizer/../ast/visitor.hpp imp/recognizer/../ast/imp.hpp \
 imp/recognizer/location.hh imp/ast/imp.hpp
imp.o: imp/ast/imp.cpp imp/ast/imp.hpp imp/ast/visitor.hpp
imp-parser.o: imp/recognizer/imp-parser.cpp imp/recognizer/imp-parser.hpp \
 imp/recognizer/../ast/imp.hpp imp/recognizer/../ast/visitor.hpp \
 imp/recognizer/../ast/imp.hpp imp/recognizer/location.hh \
 imp/recognizer/../imp-driver.hpp \
 imp/recognizer/../recognizer/imp-parser.hpp
imp-scanner.o: imp/recognizer/imp-scanner.cpp \
 imp/recognizer/../imp-driver.hpp \
 imp/recognizer/../recognizer/imp-parser.hpp \
 imp/recognizer/../recognizer/../ast/imp.hpp \
 imp/recognizer/../recognizer/../ast/visitor.hpp \
 imp/recognizer/../recognizer/../ast/imp.hpp \
 imp/recognizer/../recognizer/location.hh imp/recognizer/imp-parser.hpp
gc-driver.o: gc/gc-driver.cpp gc/gc-driver.hpp \
 gc/recognizer/gc-parser.hpp gc/recognizer/../ast/gc.hpp \
 gc/recognizer/location.hh gc/ast/gc.hpp
test.o: gc/test.cpp gc/ast/printer-visitor.hpp gc/ast/visitor.hpp \
 gc/ast/gc.hpp gc/compiler/smt-compiler.hpp \
 gc/compiler/../ast/visitor.hpp gc/gc-driver.hpp \
 gc/recognizer/gc-parser.hpp gc/recognizer/../ast/gc.hpp \
 gc/recognizer/location.hh gc/../solver/z3-solver.hpp gc/../tools.hpp
gc-parser.o: gc/recognizer/gc-parser.cpp gc/recognizer/gc-parser.hpp \
 gc/recognizer/../ast/gc.hpp gc/recognizer/location.hh \
 gc/recognizer/../gc-driver.hpp gc/recognizer/../recognizer/gc-parser.hpp
gc-scanner.o: gc/recognizer/gc-scanner.cpp gc/recognizer/../gc-driver.hpp \
 gc/recognizer/../recognizer/gc-parser.hpp \
 gc/recognizer/../recognizer/../ast/gc.hpp \
 gc/recognizer/../recognizer/location.hh gc/recognizer/gc-parser.hpp
gc.o: gc/ast/gc.cpp gc/ast/gc.hpp gc/ast/../../tools.hpp
