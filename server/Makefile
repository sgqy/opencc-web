CC = g++
CC_ARGS = -O3 -Wall -Wextra -pedantic -fPIC
INCLUDES = ${JAVA_HOME}/include ${JAVA_HOME}/include/linux

LD = g++
LD_ARGS = -shared
LD_LIBS = opencc

STRIP = strip

SRC_DIR = src/main/cpp
DST_DIR = target/main/cpp
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(addprefix $(DST_DIR)/, $(notdir $(SOURCES:.cpp=.o)))
TARGET = $(DST_DIR)/libopencc4j.so

.PHONY: clean all

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LD_ARGS) -o $@ $^ $(addprefix -l, $(LD_LIBS))
	$(STRIP) $@

$(DST_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(addprefix -I, $(INCLUDES)) $(CC_ARGS) -c -o $@ $<

clean:
	rm -rf $(DST_DIR)
	mkdir -p $(DST_DIR)
