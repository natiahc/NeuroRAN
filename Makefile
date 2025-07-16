CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
LDFLAGS = -lyaml-cpp -lonnxruntime -lssl -lcrypto
SRC = src/main.cpp src/syscall_monitor.cpp src/policy_loader.cpp src/causal_logger.cpp
OUT = neuroran

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)
