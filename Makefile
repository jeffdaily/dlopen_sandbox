CXXFLAGS = -Wall -Wextra -fPIC

all: libruntime.so

runtime.o: runtime.cpp runtime.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

DynamicLibrary.o: DynamicLibrary.cpp DynamicLibrary.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

libruntime.so: runtime.o DynamicLibrary.o
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $@ $^ -ldl

clean:
	rm -f runtime.o libruntime.so DynamicLibrary.o
