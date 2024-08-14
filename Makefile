# Define the compiler
CXX = g++

# Define the flags for the compiler
CXXFLAGS = -Wall -std=c++17

# Define the directory containing the source files
SRC_DIR = src
BUILDDIR = build

# Define the executable file name
TARGET = $(BUILDDIR)/output

# Define the source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Define the object files (same names as source files but with .o extension in the build directory)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

# Default rule to build the project
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
$(BUILDDIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)


# Rule to clean the directory (remove object files and the executable)
clean:
	rm -f $(BUILDDIR)/*.o $(TARGET)
	
# Phony targets (these don't correspond to actual files)
.PHONY: all clean
