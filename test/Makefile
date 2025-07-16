CXX = g++
CXXFLAGS = -std=c++17 -I../include
LDFLAGS = -lyaml-cpp
SRC = test_policy_loader.cpp
OUT = test_policy_loader

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)
