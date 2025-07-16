#!/bin/bash

echo "[NeuroRAN] Building..."

g++ -std=c++17 -Iinclude \
    src/main.cpp \
    src/syscall_monitor.cpp \
    src/policy_loader.cpp \
    src/causal_logger.cpp \
    -lyaml-cpp -lonnxruntime -lssl -lcrypto \
    -o neuroran

echo "[NeuroRAN] Build complete. Run with: ./neuroran"
