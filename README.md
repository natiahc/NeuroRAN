# 🧠 NeuroRAN

**NeuroRAN** is a lightweight, open-source runtime AI policy enforcement and syscall-level security agent designed for modern 5G/6G edge infrastructure, embedded Linux devices, and secure cloud-native systems.

---

## 🔍 What It Does

- ⛔ Blocks unauthorized binaries (e.g., `netcat`, `ssh`)
- 🧠 Audits inference activity using ONNX runtime
- 🔐 Logs all events with cryptographic hash-chaining
- 📡 Deploys as a DaemonSet, service, or bare-metal agent

---

## 💡 Use Cases

- Telecom RAN security (6G/Edge)
- Embedded Linux appliances (RTOS, gateways)
- DevSecOps observability for inference nodes
- Lightweight endpoint security for startups

---

## 🚀 Quick Start

```bash
git clone https://github.com/yourname/NeuroRAN.git
cd NeuroRAN
make
sudo ./neuroran
