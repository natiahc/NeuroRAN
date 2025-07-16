# NeuroRAN Architecture

**NeuroRAN** is an AI-native runtime agent designed to operate at the edge, inside 6G RAN nodes or telecom containers, enabling real-time policy enforcement, anomaly detection, and lightweight inference.

---

## 🔧 Components

### 1. **Syscall Monitor**
- Inspects `/proc/<pid>/exe` or uses ptrace/seccomp/eBPF
- Applies rules from YAML policy
- Can block, audit, or log syscall behavior

### 2. **Policy Engine**
- Reads YAML definitions at startup
- Rules specify syscall type, file paths, network domains
- Extensible for per-process and per-container scoping

### 3. **Causal Logger**
- Tamper-evident event logs using SHA256 hash chaining
- Logs every action taken with timestamp, syscall, reason
- Optionally write to SQLite or remote server

### 4. **ONNX Inference Runtime (Planned)**
- Will support classification tasks (e.g., anomaly scores, traffic types)
- Uses `onnxruntime` or `InferLite` backend

---

## 🚀 Deployment Modes

| Mode        | Use Case                      | Runtime        |
|-------------|-------------------------------|----------------|
| Bare-metal  | High-trust telecom appliance  | Static binary  |
| Container   | K8s DaemonSet on RAN cluster  | Docker image   |
| Offline RT  | Edge RTOS system (planned)    | Custom C/C++   |

---

## 🔒 Security Features

- Deny execution of unapproved binaries (e.g., netcat, ssh)
- Limit socket creation rates per syscall
- Audit model loading and sensitive I/O
- Optional support for TPM-attested boot (future)

---

## 📡 Target Use Cases

- 6G/5G RAN edge security
- Telecom site AI-assisted monitoring
- Lightweight observability for embedded Linux
- Self-enforcing policy agent for startup appliances

---

## 🧠 Future Roadmap

- eBPF syscall filtering
- AI-based behavior scoring
- Rust/C hybrid runtime for safety and performance
- Integration with OpenRAN orchestration APIs

---

For further details, see `docs/getting-started.md` and `k8s/` folder for deployment.

