CC = g++
CC_ARGS = -O3 -Wall -Wextra -pedantic -fPIC
INCLUDES = ${JAVA_HOME}/include ${JAVA_HOME}/include/linux

LD = g++
LD_ARGS = -shared
LD_LIBS = opencc

STRIP = strip

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = libopencc4j.so

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LD_ARGS) -o $@ $^ $(addprefix -l, $(LD_LIBS))
	$(STRIP) $@

%.o: %.cpp
	$(CC) $(addprefix -I, $(INCLUDES)) $(CC_ARGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf *.o $(TARGET)
