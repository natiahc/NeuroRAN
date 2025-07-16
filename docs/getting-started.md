# Getting Started with NeuroRAN

Welcome to **NeuroRAN** — a lightweight runtime security and AI policy enforcement agent for 6G/edge systems.

---

## 🛠 Requirements

- Linux host (or WSL2 / Docker on Mac/Windows)
- `g++`, `make`, `cmake`, `libyaml-cpp-dev`, `onnxruntime`
- Docker (for containerized development)
- Kubernetes (optional: minikube)

---

## 🐳 Run with Docker

```bash
# Build the Docker image
docker build -t neuroran-dev -f docker/Dockerfile .

# Run the container
docker run -it --privileged -v /proc:/host/proc neuroran-dev
