# NeuroRAN

🧠 NeuroRAN is an **AI-native runtime agent** for next-gen 6G, edge, and secure telecom systems.  
It enforces real-time policies, observes AI model behavior, and provides syscall-level telemetry for inference workloads.

## 🔍 What It Does
- Observes and logs AI model inference on edge nodes
- Detects abnormal syscall behavior (e.g. file access, fork bombs)
- Applies YAML-defined security & network policies
- Supports ONNX + InferLite runtimes

## 🚀 Goals
- Built for edge, 5G/6G RAN, embedded Linux systems
- Runs in Docker, K8s, or bare-metal
- Open-source, vendor-neutral alternative to closed security agents

## 🛠️ Quick Start
```bash
docker build -t neuroran-dev ./docker
docker run --rm -it neuroran-dev
