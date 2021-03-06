SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
DEPENDS := $(patsubst src/%.cpp, deps/%.dep, $(SOURCES))
TESTS = $(sort $(dir ./tests/*/))

bin/program : $(OBJECTS)
	@mkdir -p bin
	@g++ $(OBJECTS) -o $@


obj/%.o : src/%.cpp 
	@mkdir -p ./obj
	@g++ -c $< -I./src -std=c++11 -o $@

deps/%.dep : src/%.cpp
	@mkdir -p ./deps
	@g++ -MM $< -MT "$@ $(patsubst %.dep, %.o, $@)" -o $@ -I./src

-include $(DEPENDS)

.PHONY : clean docs test
clean :
	@echo "cleaning up"
	@rm -rf  deps obj bin docs/doxygen test_results.txt
	@for dir in $(TESTS); do \
	        $(MAKE) -C $$dir clean ; \
	        done
	
docs : 
	@mkdir -p docs/doxygen
	@doxygen docs/doxygen_config/config

test : 
	@touch test_results.txt
	@for dir in $(TESTS); do \
	        $(MAKE) -C $$dir; \
	        done
