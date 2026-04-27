# Neon Sovereign IDE

## The Neural OS for Engineering 🌐🧠🚀

**Neon Sovereign** is a high-performance, fully native **C++20 AI-powered IDE** built from first principles to eliminate the inefficiencies, latency, and architectural limitations of Electron-based development environments.

This is not a "chat assistant inside an editor."

This is an **Autonomous Engineering System** — a deterministic, self-correcting, multi-agent workstation that plans, executes, verifies, and adapts in real-time.

It combines:
* A **sub-millisecond editor engine**
* An **orchestrated, parallelized AI swarm ("The Infinite Swarm")**
* A **compiler-driven verification loop**
* A **zero-compromise native UI (Slint + DirectX/Vulkan)**
* A **defensive, industrial-grade execution model**

---

## 🚫 Why Neon Sovereign Exists

Modern AI IDEs are fundamentally flawed:
* Built on **Electron** → inherent latency, memory bloat, poor rendering
* Built as **plugins to VSCode** → limited control, sandboxed capability
* Built around **chat workflows** → inefficient, linear, context-wasting
* Built without **true compiler integration** → hallucinations leak into code

**Neon Sovereign rejects all of this.**

Instead, it introduces a new model:
> **AI is not an assistant. AI is an autonomous engineer operating inside a deterministic control system.**

---

## 🧠 Hardware Requirements (Optimised for 2026)

This system is **not lightweight by design**. Running the full 26B Architect + Sentinel locally requires high-end hardware. Lower-end systems must fall back to smaller models or use hybrid cloud routing.

| Component | Minimum | Recommended (Sovereign Elite) | Notes |
| :--- | :--- | :--- | :--- |
| **CPU** | 8-core (Ryzen 3700X / i7-9700K) | **16-core+ (Ryzen 7950X / i9-11900K)** | Agent parallelism + NUMA affinity |
| **RAM** | 32GB | 64GB+ | Prevents context thrashing |
| **GPU** | 12GB VRAM | **24GB VRAM (RTX 3090 / 4090)** | Local LLM execution |
| **Storage** | SSD | **NVMe Gen4** | High-speed LSH indexing + builds |
| **OS** | Windows 11 + WSL2 | Same | Native host |

---

## 🔥 Ignition Sequence (Quickstart)

This is the **minimum viable path** to compile and launch Neon Sovereign on a clean system.

### 🧰 Prerequisites
* Windows 11 (23H2+)
* Visual Studio 2022 (Desktop C++ workload)
* CMake ≥ 3.28
* Git
* WSL2 with Ubuntu 22.04+
* Vulkan SDK
* GPU drivers with Vulkan 1.3 support

### ⚙️ Step 1 — Clone the Repository
```bash
git clone https://github.com/your-org/neon-sovereign.git
cd neon-sovereign
```

### ⚙️ Step 2 — Bootstrap Dependencies

**Windows (Host)**
```bash
cmake -S . -B build/windows -G "Visual Studio 17 2022" -A x64
cmake --build build/windows --config Release
```

**WSL (Linux Toolchain Layer)**
```bash
wsl
sudo apt update
sudo apt install build-essential clang lld ninja-build pkg-config \
                 libvulkan-dev libxkbcommon-dev libwayland-dev
cd /mnt/c/path/to/neon-sovereign
cmake -S . -B build/linux -G Ninja
cmake --build build/linux
```

### ⚙️ Step 3 — Provision the Neural Weights

Neon Sovereign is **air-gapped by default**. No API keys. No hidden cloud calls. No fallback magic. You must provide the models locally.

**📦 Directory Layout & Download**
```bash
mkdir -p models/
wget -O models/architect-26b.gguf <ARCHITECT_MODEL_URL>
wget -O models/sentinel-2b.gguf <SENTINEL_MODEL_URL>
```

**⚡ Recommended Quantization**
| Model | Recommended | Notes |
| :--- | :--- | :--- |
| **Architect (26B)** | Q4_K_M | Best balance of reasoning vs VRAM |
| **Sentinel (2B)** | Q5_K_M | Keeps audit precision high |

**🧠 VRAM Mapping Expectations**
| GPU VRAM | Behaviour |
| :--- | :--- |
| **24GB (e.g. NVIDIA RTX 3090 / 4090)** | Full local swarm (Architect + Sentinel) |
| **12–16GB** | Architect offloaded / quantized |
| **<12GB** | Sentinel-only or hybrid mode |

**🔌 Configure Model Paths**

Create or edit `config/neural.toml`:
```toml
[models]
architect = "models/architect-26b.gguf"
sentinel  = "models/sentinel-2b.gguf"

[execution]
mode = "local"        # local | hybrid | remote
vram_budget_gb = 22
```

### ⚡ Step 4 — Launch & Verify

Launch the IDE:
```bash
./build/windows/Release/NeonSovereign.exe
```

From inside the IDE terminal, validate the neural engine:
```bash
neonctl doctor
```

**Expected output:**
```text
[OK] Vulkan backend initialized
[OK] WSL toolchains mapped
[OK] Architect model loaded (26B)
[OK] Sentinel model loaded (2B)
[OK] VRAM allocation within budget
[OK] Neural Bridge active
[OK] Sentinel thread online
```

**⚠️ Failure Modes (Explicit by Design)**

Neon Sovereign will **not silently degrade**. Missing models trigger hard failures. Insufficient VRAM yields explicit warnings. Corrupt GGUFs are rejected at load. **Determinism > convenience.**

---

## 🐝 Hello World: Autonomous Swarm in Action

This is where the system proves itself.

**🎯 Task:** *Create a cross-platform C++ TCP client with reconnect logic and exponential backoff.*

1. **Architect Decomposition:** The 26B Architect defines cross-platform abstractions, reconnect strategies, and backoff math. It emits a JSON Task DAG — no implementation code written at this stage.
2. **Parallel Execution:** Worker agents generate code, patch AST nodes directly, and submit completed patches to the Crucible buffer.
3. **Sentinel Audit:** The Sentinel catches a missing `closesocket()` on a failure path and issues a `[COMPILER_FIX_MANDATE]`.
4. **Autonomous Retry:** Agents adapt, adding RAII wrappers informed by historical SQLite knowledge from the Project Ledger.
5. **Sovereignty Gate (HITL):**
```text
⚠️ Proposed Structural Changes
+ class SocketGuard { ... }
+ Added exponential_backoff()
~ Modified connect_loop()
Accept changes? [Enter] / Reject [Esc]
```

**Result:** Code that compiles cleanly, is memory-safe, cross-platform, and fully verified before it ever touches your disk.

---

## ⚡ Core Architecture & AI Capabilities

### 🧩 Native Rendering Stack & Bridge
* **C++20 + Slint UI:** DirectX / Vulkan backend delivering 120FPS "Liquid Glass" interfaces.
* **Sub-Millisecond Editing:** Skip-list Rope Data Structure ensures O(log n) edits, handling 100MB+ files with microsecond latency.
* **Zero-Copy Neural Bridge:** Native `llama.cpp` integration. VRAM-resident inference means zero HTTP/IPC overhead.

### ⚙️ Deterministic CPU Offloading (The Non-LLM Brain)

Neon Sovereign uses hyper-fast C++ algorithms to handle reasoning *before* engaging the LLM:
* **Kahn's Algorithm:** Mathematical topological sorting of the Task DAG ensures optimal parallel execution and resolves all architectural dependencies before any implementation begins.
* **Tree-sitter Complexity Routing:** Cyclomatic complexity > 15 automatically escalates the task to the 26B Architect; simpler tasks route to 2B models.
* **BM25 Lexical Search:** O(1) instant historical memory retrieval via SQLite, bypassing expensive vector embeddings entirely.

### 🐝 The Infinite Swarm: High-Concurrency Orchestration

Neon Sovereign replaces linear chat with a **dynamically pooling, parallelized engineering company**:

* **NUMA-Aware Core Affinity:** Agents are pinned to specific CPU cores using `SetThreadAffinityMask` to eliminate cache-thrashing and maximise throughput on high-performance hardware such as the i9-11900K.
* **Tiered Work-Stealing (Chase-Lev):** A tiered work-stealing architecture ensures zero idle time. Agents first pop tasks from their local deque, then attempt to steal from sibling roles, then fall back to cross-role stealing.
* **Asymmetric Execution (Parallel Speculation):** The system initiates parallel speculative passes where a 2B Sentinel drafts code while a 26B Architect verifies and solidifies the logic in real-time.
* **Wait-Free Epoch Management:** Thread-local EBR (Epoch-Based Reclamation) registration ensures memory safety across the parallel swarm without traditional locking bottlenecks.

### 🧑‍💼 The Specialist Roster

| Agent | Role | Constraints |
| :--- | :--- | :--- |
| **The Architect (26B+)** | Builds the JSON Task DAG. Defines strategy, decomposition, abstractions. | Prohibited from writing implementation code. |
| **The Developers** | Dynamic horizontal pool of worker agents executing parallel tasks. | Operate only on assigned AST node ranges. |
| **The Forge Master** | DevOps specialist. Writes CMakeLists, Ninja scripts, handles cross-compilation. | Exclusively controls the build layer. |
| **The Binary Analyst** | Controls Ghidra Headless to verify AVX2/NEON optimisations at silicon level. | Read-only on live binaries. |
| **The Network Scout** | Parses TShark hex-dumps and validates cryptographic handshakes. | Sandboxed network access. |
| **The Sentinel Auditor (2B)** | Hostile, adversarial auditor. Validates structural integrity, issues mandates. | Can block any patch from promotion. |

---

## 🧠 The Blackboard: Deterministic Decision Logic

The **Blackboard Manager** acts as the central "CPU Brain," coordinating all agent interactions through rigorous mathematical protocols:

* **Topological Task Sorting (Kahn's Algorithm):** Sorts the Task DAG so that architectural dependencies are always resolved before implementation begins. No agent can start work on a node whose parents are unsettled.
* **Hierarchical AST Locking:** To prevent parallel mutation conflicts, the blackboard enforces hierarchical locks. Locking a parent node (e.g., a `Class`) automatically blocks child node edits (e.g., `Methods`), ensuring structural integrity across concurrent agents.
* **Supreme Architect Hard Flush:** When context pressure peaks, the system executes a "Hard Flush" — purging stale agential memory and summarising the execution history into a high-density "Agential Memory" block to free headroom without losing critical state.
* **Tactile Resistance Tracing:** If an agent encounters a resource lock, the system logs a "Sensory Trace," providing an ETA for resource availability instead of failing or spinning.

---

## 🛡️ The Crucible: 8-Stage Verification & Defence

No code reaches the live editor without clearing the **Crucible**, a hardened verification gate:

* **Adversarial Debate Protocol:** If a Sentinel rejects a patch, the system enters a multi-round debate. The "Builder" must defend the implementation against "Sentinel" mandates until consensus is reached or escalation triggers.
* **Asynchronous Steering Protocol (ASP):** A dedicated Sentinel thread monitors user intent at 100ms intervals, enabling real-time `PIVOT` or `CONTINUE` signals to interrupt the swarm mid-execution.
* **Silicon Retina (VLM) Aesthetic Audit:** The system captures viewport screenshots and uses Vision Language Models to perform aesthetic audits — catching overlapping text or layout failures at the "retina" level before promotion.
* **Symbolic Execution Pass:** A mandate-driven logic audit analyses code for unreachable branches, division-by-zero, and null dereference paths before any patch is promoted.

### 🔒 Crucible Shadow Buffer & AST Bounding

All AI edits operate on **AST nodes only** to prevent line-number drift. Code is applied in-memory, compiled via `clangd` in the Shadow Buffer, and verified *before* the UI is ever updated.

### 🔐 The Sovereignty Gate (HITL) & AST Locks

All destructive actions require explicit human approval. The Blackboard enforces a strict **Transactional AST Locking Model** to prevent parallel agents from mutating overlapping syntax nodes.

### ⚖️ The Executive Scheduler (Governor)

Samples `SysProbe` metrics at 120FPS. If CPU/GPU load exceeds 90%, the Swarm is automatically throttled or halted to protect the human operator's UI performance budget.

---

## 🔁 The Deterministic Control Loop

Every agent task cycles through the same seven-stage execution model:

1. **PLAN** → Select tools, define steps
2. **ACT** → Execute atomic operations
3. **OBSERVE** → Capture raw outputs (compiler, logs, stderr)
4. **ANALYZE** → Convert raw output into structured failure types
5. **ADAPT** → Modify strategy based on failure classification
6. **RETRY** → Iterate (max bounded attempts)
7. **LOCK-IN** → Persist successful strategy to the Project Ledger

---

## 🧬 Symbolic Intelligence & Context Engine

* **JIT AST Node Resolution:** The AI Gateway dynamically "hydrates" prompts by resolving AST pointers (e.g., `AST-uuid`) into raw code snippets just-in-time, keeping context lean without sacrificing precision.
* **Naming Guard (Symbolic Integrity):** Uses LSH (Locality Sensitive Hashing) for project-wide semantic similarity queries, allowing the Sentinel to instantly catch redundant logic re-implementations before they propagate.
* **Skeleton & Muscle Compression:** Uses Tree-sitter parsing to reduce 10,000 lines of code into <3KB of structured context. Sends only skeleton structure and the targeted mutation zone.
* **Context Pressure Gauges:** The Hive UI visualises "Context Pressure" and "Semantic Decay" — showing the mathematical exclusion of stale facts as the IDE dynamically maintains focus across long sessions.
* **Watchdog Indexing:** OS-native hooks (`ReadDirectoryChangesW` on Windows, `inotify` on Linux) provide zero-polling, instantaneous reactions to filesystem mutations, triggering immediate AST state-lock re-evaluations.
* **Autonomous Research Scout:** A native WinHTTP C++ crawler autonomously fetches web documentation via SearxNG/Brave, strips HTML, and injects raw reference material directly into agent context to prevent API hallucinations.

---

## 🧪 Systems Laboratory & Tooling

### 🔬 Silicon Perception Labs

* **Binary Lab:** Ghidra Headless specialist integration verifying AVX2/NEON optimisations and structural layouts at the silicon level.
* **Telemetry Mode:** VRAM Stacking visualiser and ETW real-time cache miss / branch prediction tracking.
* **Network Lab:** TShark packet inspection and cryptographic handshake validation.
* **Master Forge:** Dual-target CI/CD pipeline dynamically switching between Windows native (MSVC/Ninja) and Linux (CMake/WSL).

### 🔧 Universal Tool Registry

A deterministic AI tool system (`read_file`, `search`, `patch`, `build_project`, `exec`). All tools are explicitly registered — no agent can invoke an unregistered capability.

* **Terminal Auto-Heal Loop:** Physically intercepts `stderr` for `error:` or `fatal:` strings and autonomously triggers the Sentinel to generate a fix mandate without user intervention.
* **Ghost Fix Engine:** Pairs a Sovereign Provisioner (VHDX-based) with the Binary Analyst to perform "Ghost Fixes" in isolated virtual environments — dangerous or experimental patches run in the ghost before ever touching the live workspace.

---

## 🌐 Decentralised Collaboration & Identity (C-Lab Zero)

* **Post-Quantum Security:** X25519 + ML-KEM-768 hybrid encryption for all peer-to-peer channels.
* **CRDT Synchronisation:** Conflict-free editing across humans and AI agents via Loro + Fugue — every operation is commutative and merge-safe.
* **Sovereign Identity:** Fully offline, BIP39-based 12-word identity system generated locally. No external auth providers, no cloud registration, no revocation dependency.

---

## 🎙️ The Vocal Matrix & Memory

### 🎭 The Custodial Persona

A fully integrated voice interaction system. Deadpan, high-intelligence interaction featuring real-time barge-in interruption and **Tactical Voice Steering**:
* `"Custodian, throttle the swarm"` — immediately engages the Governor
* `"Custodian, hard flush"` — triggers Blackboard memory compaction
* `"Custodian, pivot"` — issues an ASP interrupt to the active swarm

### 🗂️ Persistent Intelligence Layer — The Project Ledger

The **Memory Web** is a visual Nodal Knowledge Graph replacing flat tables. It stores:
* Build commands and resolved toolchain configurations
* Problem → Fix → Context tuples from past compiler cycles
* BM25-indexed historical decisions enabling near O(1) resolution for recurring failure patterns

---

## ⚙️ Design Philosophy

Neon Sovereign is built on strict, non-negotiable principles:

* **Determinism over guesswork** — every decision has a traceable mathematical cause
* **Verification over generation** — code is proven before it is promoted
* **Parallelism over linear chat** — the swarm operates concurrently, not sequentially
* **Native performance over abstraction** — no Electron, no JVM, no managed runtime overhead
* **Control over convenience** — the human operator remains sovereign at all times

---

## 🧨 Final Statement

Neon Sovereign is not trying to improve existing AI IDEs.

It replaces them entirely.

> If your IDE is built on Electron, constrained by plugins, and driven by chat…
> it is already obsolete.
