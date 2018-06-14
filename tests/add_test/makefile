SOURCES := $(wildcard ./*.cpp)
OBJECTS := $(patsubst ./%.cpp, ./%.o, $(SOURCES))
DEPENDS := $(patsubst ./%.cpp, ./%.dep, $(SOURCES))
DEPENDS += list.dep
IMPLEMENTATION := ../../src/list.cpp
HEADERS := -I../../src -I./

test : $(OBJECTS) list.o
	@g++ $^ -o $@
	@./test
%.o : %.cpp 
	@g++ -c $< $(HEADERS) -o $@ 

list.o : $(IMPLEMENTATION) 
	@g++ -c $< $(HEADERS) -o $@

%.dep : %.cpp
	@g++ -MM $< -MT "$@ $(patsubst %.dep, %.o, $@)" -o $@ $(HEADERS)

list.dep : $(IMPLEMENTATION)
	@g++ -MM $< -MT "$@ $(patsubst %.dep, %.o, $@)" -o $@ $(HEADERS)

-include $(DEPENDS)

.PHONY : clean

clean :
	@echo "cleaning up"
	@rm -rf  *.dep *.o test 
