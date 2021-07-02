CXXFLAGS = -Wall -Wextra

all: libdriver.so libruntime.so

driver.o: driver.cpp driver.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

libdriver.so: driver.o
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $@ $<

runtime.o: runtime.cpp runtime.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

libruntime.so: runtime.o
	$(CXX) $(CXXFLAGS) -shared -fPIC -o $@ $< -ldl

clean:
	rm -f driver.o libdriver.so runtime.o libruntime.so
