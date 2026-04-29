# Neon Sovereign

## The Neural OS for Engineering 🌐🧠🚀

**Neon Sovereign** is a high-performance, fully native **C++20 AI-powered IDE** built from first principles.

Not a chat assistant. Not a copilot. Not a plugin.

**A complete autonomous software house** — a parallelised, role-locked team of AI engineers that plans, writes, reviews, verifies, debugs, and ships code across every platform, language, and target that has ever existed. Governed by a deterministic control system. Checked at every step. Handed to you only when it's right.

It doesn't matter whether you're building a React web app, a RISC-V firmware image, a Solaris kernel module, a mobile game, or a cross-platform CLI tool. Neon Sovereign operates the same way a professional software house does: **specialists working in parallel, with their work independently verified before it ships.**

It combines:
* A **sub-millisecond editor engine** (skip-list rope, O(log n) edits on 100MB+ files)
* **The Infinite Swarm** — a dynamically pooling, parallelised AI engineering company
* A **compiler-driven verification loop** that catches hallucinations before they touch disk
* A **zero-compromise native UI** (Slint + DirectX/Vulkan, 120FPS)
* A **defensive, industrial-grade execution model** built on deterministic C++ algorithms
* A **SIMD-accelerated core** (AVX2/AVX-512 hardware dispatching for rope edits and indexing)
* A **universal execution window** (SpiceViewport) with eyes inside every environment
* An **IOCP-driven I/O subsystem** (Windows-native completion ports for sub-millisecond task scaling)

---

## 🚫 Why Neon Sovereign Exists

Modern AI IDEs are architecturally flawed at the foundation:

| Problem | Root Cause |
| :--- | :--- |
| Latency & memory bloat | Built on Electron |
| Limited control & sandboxed capability | Built as VSCode plugins |
| Inefficient, context-wasting, linear workflows | Built around chat |
| Hallucinations leak into production code | No real compiler integration |
| Locked to specific languages or ecosystems | Built around one toolchain |
| One AI doing everything sequentially | No parallel specialisation |

**Neon Sovereign rejects all of this.**

> **AI is not an assistant. AI is an autonomous engineering company operating inside a deterministic control system — for any language, any platform, any target.**

---

## 🌍 Universal Scope — Every Platform. Every Language. Every Target.

Neon Sovereign is not a C++ IDE. It is not a web IDE. It is not a firmware IDE.

It is a **universal engineering system** that operates wherever code runs. The Swarm adapts its toolchain, language model routing, compiler integration, and verification strategy to match the target — automatically.

| Domain | Examples |
| :--- | :--- |
| **Systems & Native** | C, C++, Rust, Zig — Linux, Windows, macOS |
| **Web & Frontend** | TypeScript, JavaScript, React, Vue, WASM |
| **Mobile** | Swift/Obj-C (iOS), Kotlin/Java (Android), ADB integration for direct device deployment |
| **Embedded & Firmware** | C/C++/Rust on ARM Cortex-M, RISC-V, AVR, ESP32, bare-metal |
| **Games & Graphics** | C++ (Unreal), C# (Unity), GLSL/HLSL shaders, Vulkan/DirectX |
| **Data & ML** | Python, CUDA, ROCm, Triton, ONNX pipelines |
| **Legacy & Exotic** | COBOL, Fortran, Ada, PL/I, assembly (x86, ARM, MIPS) |
| **Scripting & DevOps** | Bash, PowerShell, Lua, Ruby, Go, Dockerfile, Terraform |
| **Mainframe & Enterprise** | z/OS, JCL, CICS, AS/400 RPG |
| **Virtualised Targets** | SGI IRIX, Solaris, VAX/VMS, any QEMU-bootable OS |

The Architect doesn't know "C++ only." The Developers don't care which compiler is in the `ToolRegistry`. The Sentinel audits logic, not language. **The system scales to the target, not the other way around.**

---

## 🏢 The Software House Model

This is the fundamental shift. Neon Sovereign doesn't give you smarter autocomplete. It gives you a **team**.

In a professional software house, work flows through a defined structure:
1. A **Technical Architect** designs the system and breaks it into parallel workstreams
2. **Specialist developers** execute those workstreams in parallel, each in their domain
3. A **QA team** independently reviews the output for correctness, safety, and edge cases
4. A **DevOps engineer** handles builds, environments, and deployment pipelines
5. A **Tech Lead** reviews the final output before anything ships

Neon Sovereign runs this entire structure autonomously, in real-time, on your machine:

```
You give a task
       ↓
Architect designs the system → produces a JSON Task DAG
       ↓
Kahn's Algorithm calculates optimal parallel execution order
       ↓
Specialist Developers execute workstreams in parallel
       ↓
Sentinel Auditor independently reviews every output (adversarially)
       ↓
Forge Master handles cross-compilation, build scripts, environments
       ↓
Binary Analyst + Network Scout verify at silicon and protocol level
       ↓
Crucible Shadow Buffer compiles and verifies before touching disk
       ↓
Sovereignty Gate presents changes for your approval
       ↓
You accept or reject. Nothing ships without your sign-off.
```

The key word is **independently**. The Sentinel does not share context with the Developers. It receives their output cold and reviews it the way a hostile senior engineer would — looking for what's wrong, not what's right. That independence is what makes the verification meaningful.

---

## 🧠 Hardware Requirements

This system is **not lightweight by design**. The full 26B Architect + Sentinel local swarm requires high-end hardware. Lower-end systems fall back to smaller models or hybrid cloud routing automatically.

| Component | Minimum | Recommended | Notes |
| :--- | :--- | :--- | :--- |
| **CPU** | 8-core (Ryzen 3700X / i7-9700K) | 16-core+ (Ryzen 7950X / i9-13900K) | Agent parallelism |
| **RAM** | 32GB | 64GB+ | Prevents context thrashing |
| **GPU** | 12GB VRAM | 24GB VRAM (RTX 3090+) | Local LLM execution |
| **Storage** | SSD | NVMe Gen4 | Indexing + builds |
| **OS** | Windows 11 + WSL2 | Same | Native host |

> ⚠️ **VRAM Reality Check:** A 26B model at Q4_K_M requires ~16GB VRAM to load. The 12GB minimum tier runs Sentinel-only or heavily offloaded. The recommended 24GB tier runs the full swarm uncompromised.

---

## 🔥 Ignition Sequence (Quickstart)

### 🧰 Prerequisites
* Windows 11 (23H2+)
* Visual Studio 2022 (Desktop C++ workload)
* CMake ≥ 3.28
* Git
* WSL2 with Ubuntu 22.04+
* Vulkan SDK + drivers with Vulkan 1.3 support
* Rust toolchain (stable) with `x86_64-pc-windows-msvc` target

### ⚙️ Step 1 — Clone
```bash
git clone https://github.com/your-org/neon-sovereign.git
cd neon-sovereign
```

### ⚙️ Step 2 — Build

**Windows (Native MSVC)**
```bash
cmake -S . -B build/windows -G "Visual Studio 17 2022" -A x64
cmake --build build/windows --config Release
```

### ⚙️ Step 2.1 — Inference Engine Selection
Neon Sovereign supports multiple local and hybrid providers. By default, it prioritises high-throughput local providers:
* **Ollama (Primary)**: Deeply integrated via a native C++ bridge. Supports automatic retries and failover for transient inference failures.
* **llama.cpp (Integrated)**: The zero-copy neural bridge for direct VRAM-resident inference.
* **Agents SDK**: A hybrid bridge allowing delegation of complex sub-tasks to specialized autonomous agents.
```

**WSL (Linux Cross-Compile Layer)**
```bash
wsl
sudo apt update && sudo apt install build-essential clang lld ninja-build \
    pkg-config libvulkan-dev libxkbcommon-dev libwayland-dev
cd /mnt/c/path/to/neon-sovereign
cmake -S . -B build/linux -G Ninja
cmake --build build/linux
```

### ⚙️ Step 3 — Provision Neural Weights

Neon Sovereign is **air-gapped by default**. No API keys. No cloud fallback. No hidden telemetry. You own the weights.

```bash
mkdir -p models/
wget -O models/architect-26b.gguf <ARCHITECT_MODEL_URL>
wget -O models/sentinel-2b.gguf  <SENTINEL_MODEL_URL>
```

**Recommended Quantization**
| Model | Quantization | Notes |
| :--- | :--- | :--- |
| **Architect (26B)** | Q4_K_M | Best reasoning/VRAM balance |
| **Sentinel (2B)** | Q5_K_M | Maximises audit precision |

**Configure `config/neural.toml`:**
```toml
[models]
architect = "models/architect-26b.gguf"
sentinel  = "models/sentinel-2b.gguf"

[execution]
mode           = "local"   # local | hybrid | remote
vram_budget_gb = 24

[vram_budget]
inference_gb   = 18   # Architect + Sentinel resident
renderer_gb    =  2   # Vulkan/DirectX framebuffers
viewport_gb    =  2   # SpiceViewport QEMU framebuffer
system_reserve =  2   # Driver overhead, OS, headroom

[governance]
# Dynamic hardware detection (overrides static toml if VRAM < budget)
auto_scale_concurrency = true
max_concurrent_agents  = 4
inference_retry_limit  = 3
telemetry_enabled      = true
```

> **Dynamic VRAM Scaling:** On launch, Neon Sovereign probes the GPU topology. If detected VRAM is insufficient for the static `neural.toml` budget, the system automatically recalibrates `max_concurrent_agents` and `inference_retry_limit` in the UI to ensure stability.

[compilation_mode]
# Automatically engaged when build_project is active
inference_batch_scale = 0.5   # Halve inference batch size during compile
pause_non_critical    = true  # Suspend background agents
viewport_fps_cap      = 0     # Freeze SpiceViewport to static thumbnail
```

### ⚡ Step 4 — Launch & Verify

```bash
./build/windows/Release/NeonSovereign.exe
```

From inside the IDE terminal:
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
[OK] SpiceViewport ready
[OK] ToolRegistry populated
[OK] VCG Auction Loop active
[OK] NUMA-Aware Thread Affinity pinned
[OK] Universal target scope: ALL
```

**⚠️ Failure Modes Are Explicit by Design.** Missing models trigger hard failures. Insufficient VRAM yields precise diagnostics. Corrupt GGUFs are rejected at load time. **Determinism over convenience. Always.**

---

## 🐝 The Infinite Swarm in Action

Three tasks across three entirely different domains. Same system. Same control loop. Same guarantees.

---

**🎯 Task 1:** *Cross-platform C++ TCP client with reconnect logic and exponential backoff.*

1. **Architect** builds a Task DAG — platform abstraction layer, reconnect strategy, backoff algorithm, RAII socket wrapper
2. **Kahn's Algorithm** calculates the optimal parallel execution order
3. **Developers** execute in parallel — each owns one workstream
4. **Sentinel** catches a missing `closesocket()` on a failure path. Issues `[COMPILER_FIX_MANDATE]`
5. **Agents** pull the RAII fix pattern from `ProjectLedger` via BM25. Adapt and retry
6. **Sovereignty Gate** presents the structural diff for your approval

---

**🎯 Task 2:** *RISC-V bare-metal firmware — interrupt-driven ADC sampling with DMA transfer to UART.*

1. **Architect** decomposes into linker script, startup assembly, peripheral register maps, ISR, DMA config, UART framing
2. **Forge Master** provisions the RISC-V GCC cross-compile chain via `ToolRegistry` — automatically
3. **Developers** write startup code, ISR, and DMA routines in parallel
4. **Binary Analyst** runs Ghidra Headless against the ELF — verifies interrupt vector alignment, confirms no stack overflow in the ISR frame
5. **Sentinel** audits for `volatile`-correctness on every memory-mapped register access
6. **SpiceViewport** opens a QEMU RISC-V guest — the swarm boots the firmware and observes UART output in real-time without leaving the IDE

---

**🎯 Task 3:** *Full-stack web app — TypeScript React frontend, Go REST API, PostgreSQL, Dockerised.*

1. **Architect** defines the service boundary DAG — API contracts first, then parallel frontend/backend workstreams, then Docker composition
2. **Developers** execute frontend components, API handlers, and DB schema migrations simultaneously
3. **Forge Master** writes `Dockerfile`, `docker-compose.yml`, and CI pipeline config
4. **Network Scout** captures the HTTP handshake between frontend and API, validates CORS headers and auth token flow via TShark
5. **Sentinel** audits SQL queries for injection vectors and checks JWT expiry handling
6. **Sovereignty Gate** presents the full changeset — schema, API, UI, infrastructure — before a single file is written to disk

---

Same system. Same loop. **The target is irrelevant. The process is invariant.**

---

## ⚡ Core Architecture

### 🧩 The Non-LLM Brain — Deterministic CPU Offloading

The system's intelligence does not begin with the LLM. Fast, deterministic C++ algorithms handle reasoning *before* any model is invoked:

* **Kahn's Algorithm (`BlackboardManager`)** — Topological sorting of the Task DAG. The swarm never guesses execution order; it calculates the mathematically optimal parallel path.
* **Tree-sitter Complexity Router (`ASTContextManager`)** — Cyclomatic complexity > 15 automatically escalates to the 26B Architect. Simpler tasks route to 2B models. Zero wasted VRAM on trivial work. Works across any Tree-sitter-supported language grammar.
* **BM25/TF-IDF Memory (`ProjectLedger`)** — Historical fixes stored in SQLite, retrieved via a native C++ BM25 ranker. O(1) lookup. No vector embeddings. No GPU cost. Learns your codebase, your toolchains, your recurring failure patterns.
* **Semantic Decay & Context Augmentation (`ContextCompactor`)** — As the task window fills, the system generates "Compactor Packets" that preserve critical structural AST signatures while decaying less relevant logs. This ensures the 26B Architect always has a mathematically dense view of the project state.

### 🐝 The Infinite Swarm — Role-Locked Specialisation

A dynamically pooling, horizontally scaled engineering company (`m_agent_pool` in `SwarmController`). Every role has hard, enforced boundaries:

| Agent | Role | Hard Constraint |
| :--- | :--- | :--- |
| **The Architect (26B+)** | Designs the system. Builds the JSON Task DAG | Barred from writing implementation code |
| **The Developers** | Execute parallel implementation workstreams | Cannot modify the DAG |
| **The Forge Master** | Build systems, cross-compilation, CI/CD, environments | DevOps scope only |
| **The Binary Analyst** | Ghidra Headless — silicon-level verification | Read-only analysis |
| **The Network Scout** | TShark — packet inspection, protocol validation | Network scope only |
| **The Sentinel Auditor (2B)** | Adversarial, independent code review | Auditing only — never generates code |

### 🎮 Agential Intent Modes (The Brain & The Hands)

Neon Sovereign is not a static UI; it is a reconfigurable agential organism. The mode you select dictates how the AI's "Brain" (logic) and "Hands" (tool usage) behave:

*   **CHAT (Brainstorming & Architecture)**: 
    *   **The Brain**: Consultant mode. The AI provides prose, architectural theory, and high-level design patterns.
    *   **The Hands**: **Interdicted**. Tool usage is suppressed at the hardware level, ensuring a safe conversation space without accidental file mutations.
*   **BUILD (Autonomous Construction)**: 
    *   **The Brain**: Lead Engineer mode. Triggers the Swarm to generate a Task DAG and begin parallelised construction.
    *   **The Hands**: Full agential autonomy. The swarm can search, read, write, and execute across the workspace.
*   **DEBUG (Forensic Troubleshooting)**: 
    *   **The Brain**: Forensic Auditor mode. Prioritizes the Sentinel and Binary Analyst roles to find the "Crime Scene" in logs or binary traces.
    *   **The Hands**: Precision execution. The AI uses its hands specifically to set breakpoints, inspect memory, and analyze terminal failures.

### 🪟 Sovereign MDI (Program Manager Architecture)

To maintain a focused engineering workflow while handling massive multi-tasking, Neon Sovereign utilizes a **Sovereign MDI (Multiple Document Interface)**. Inspired by the Windows 3.1 Program Manager, every major tool (Editor, Hive, Terminal, Lab) is a child window "forced" inside the main application frame.

*   **Boundary Locking**: MDI child windows cannot be dragged outside the coordinate space of the IDE, ensuring your workspace remains cohesive.
*   **Z-Order Promotion**: Switching agential intent modes automatically promotes the relevant tool windows to the front (e.g., bringing the Hive Mind Hub to the top when switching to BUILD).
*   **Deterministic Docking**: Windows can be snapped to 60px "Liquid Glass" zones (Left, Right, Bottom) or floated for custom window arrangements.

### 🧬 Neon Sovereign SDK — Native Autonomous Nervous System

The defunct, third-party `agents-cpp-sdk` binary has been purged and replaced with a **fully native C++20 sovereign reconstruction**. The SDK is no longer an external dependency; it is the nervous system of the IDE.

*   **Proprioceptive Agents**: Agents observe local CPU/GPU/VRAM vitals via `SysProbe` to modulate reasoning tier and task complexity in real-time.
*   **Proactive SIMD Compaction**: Integrated `SimdDispatcher` (AVX-512/VNNI) prunes and compresses context packets using neural-pass ranking, ensuring LLMs receive only high-fidelity AST fragments.
*   **Speculative Tree Search**: The `TreeSearchOrchestrator` manages parallel "What-If" branches, executing a "Speculative Shootout" to determine the optimal architectural path before committing changes.
*   **Forensic Memory (Autopsy)**: Failed branches are not discarded. The `CrashManager` and `Analyst` perform a forensic autopsy on every failure, persisting the "Crime Scene" into the `ProjectLedger` as a negative sample for future speculative reasoning.
*   **NUMA-Aware Core Pinning**: The SDK formalizes role-based hardware affinity. The **Lead Architect** is locked to high-performance P-cores with dedicated cache lanes, while **Sentinel** auditors are distributed across E-cores to preserve user UI responsiveness.

---

### 🔄 The High-Throughput Swarm Engine

* **Chase-Lev Work-Stealing Deques** — Every agent manages its own lock-free deque. If an agent becomes idle, it autonomously "steals" tasks from the back of other agents' queues, ensuring zero idle cycles during massive builds or refactors.
* **VCG (Vickrey-Clarke-Groves) Auction Loop** — Access to execution lanes is governed by a micro-auction. Agents bid based on task complexity and urgency; the VCG mechanism ensures that the most critical engineering tasks are allocated the highest-performing hardware lanes without resource contention.
* **NUMA-Aware Affinity** — The Executive Scheduler pins agent threads to specific CPU cores based on NUMA topology, minimizing L3 cache misses and maximizing instruction throughput during parallel compilation.

### 🔁 The Deterministic Control Loop

```
PLAN → ACT → OBSERVE → ANALYZE → ADAPT → RETRY → LOCK-IN
```

Every iteration is bounded. Stagnation (>3 retries on the same failure) triggers automatic context compression, agent thread reset, and strategy re-escalation to the Architect. The loop never spins forever. It either resolves or escalates — explicitly.

### 🧩 Native Rendering Stack

* **Slint UI + DirectX/Vulkan** — 120FPS "Liquid Glass" native interface. Zero Electron. Zero Chromium.
* **Skip-List Rope Engine** — O(log n) edits, microsecond latency on 100MB+ files.
* **SIMD Dispatcher** — Real-time CPU feature detection. Automatically dispatches rope operations and search kernels to **AVX2** or **AVX-512** instruction sets based on host silicon.
* **Zero-Copy Neural Bridge** — Native `llama.cpp` integration. VRAM-resident inference. Zero HTTP/IPC overhead.
* **Executive Scheduler (Governor)** — Samples `SysProbe` at 120FPS. If CPU/GPU load exceeds 90%, the Swarm is throttled to protect the operator's UI performance budget.
* **IOCP I/O Architecture** — Uses Windows Input/Output Completion Ports for massive scalability. Handles thousands of concurrent file events, LSP messages, and network packets with zero-thread-blocking latency.

### ⚖️ Resource Governor — Static VRAM Partitioning

Running a 26B inference engine, a 120FPS Vulkan renderer, and a live QEMU SpiceViewport simultaneously on a single GPU requires a hard budget enforcer — not runtime negotiation.

VRAM is **statically partitioned at startup** from `config/neural.toml`. The three consumers never bid against each other at runtime:

| Consumer | Priority | Budget (24GB example) | Behaviour at Limit |
| :--- | :--- | :--- | :--- |
| **Inference** (Architect + Sentinel) | 1 — Highest | 18GB | Re-quantize or CPU-offload the batch |
| **Renderer** (Vulkan/DirectX) | 2 | 2GB | Reduce framebuffer resolution |
| **SpiceViewport** (QEMU guest) | 3 — Lowest | 2GB | Drop to lower SPICE stream resolution |
| **System reserve** | — | 2GB | Driver overhead, OS, headroom |

The SpiceViewport is deliberately the lowest priority consumer. It is an observability surface — dropping its frame rate or resolution during a heavy swarm task has zero operational impact on the guest execution or the agents. A 30FPS cap on the viewport during active inference costs nothing.

**Compilation Mode** is the worst-case scenario: the Forge Master is hammering CPU/RAM with parallel compile jobs while the Swarm remains active. When `build_project` is called, the Governor automatically engages `[compilation_mode]`:

* Inference batch size is halved — the Swarm stays alive but consumes less VRAM pressure per cycle
* Non-critical background agents are suspended until the build completes
* The SpiceViewport is frozen to a static thumbnail — zero GPU cost
* Full budgets are restored the moment `build_project` returns

This is proactive isolation, not reactive throttling. The system never discovers it has run out of VRAM mid-inference — the partition prevents that state from being reachable.

---

## 🖥️ The SpiceViewport — Universal Execution Window

The `SpiceViewport` is Neon Sovereign's **native window into any execution context** — local, virtualised, or remote. It is not a terminal. It is not a log viewer. It is a live rendered feed of whatever environment the system is operating inside, giving both the AI agents and the human operator eyes inside any target the swarm needs to reach.

**AI Agent Observability**
* Live DAG visualiser — nodes light up as agents fire, amber on retry, red on failure
* Blackboard state inspector — real-time view of task graph, agent states, and AST lock contention
* Sentinel audit stream — live visual feed of adversarial decisions as they happen

**Virtualised & Exotic Targets**
* QEMU guests — SGI IRIX, Solaris, VMS, legacy Windows, any OS without modern LSP
* Bare-metal emulation — RISC-V, ARM Cortex-M, AVR boards via QEMU machine targets
* Wine sessions — test Windows-only tooling from the Linux layer
* Docker/VM guests — visual confirmation of runtime state inside the container

**Operator Transparency — Glass Box Mode**
* See exactly what the AI is doing, rendered — not just logged
* Side-by-side AST diff viewport at the Sovereignty Gate
* VRAM Stacking visualiser and ETW cache miss / branch prediction overlay

> Every execution context becomes a first-class observable surface — regardless of how exotic the target is.

---

## 🛡️ Defensive Engineering & Safety

### 🔒 Crucible Shadow Buffer & AST Bounding
All AI edits operate on **AST nodes only**, preventing line-number drift. Code is applied in-memory, compiled in the Shadow Buffer via the appropriate toolchain for the target language, and verified *before* the UI updates. Nothing reaches disk unverified.

### 🔐 The Sovereignty Gate (HITL) & Transactional AST Locks
All destructive actions require human approval. The Blackboard enforces a **Transactional AST Locking Model** — parallel agents cannot mutate overlapping syntax nodes. Race conditions between agents are impossible by construction.

### ⚖️ State-Lock Hashing & Transactional AST Locks
Detects human edits instantly, forces safe re-evaluation, and prevents stale agent context from causing divergent writes into code you've already changed. The Blackboard enforces a **Transactional AST Locking Model** — parallel agents cannot mutate overlapping syntax nodes. Race conditions between agents are impossible by construction.

### 🛡️ Hardware-Level Security
* **Encrypted Secret Store** — All API keys, SSH credentials, and environment secrets are encrypted at rest using OS-native security providers (NCrypt/DPAPI) and managed via the `SecretStore`.
* **Epoch-Based Consistency** — Uses an **Epoch Manager** for lock-free consistency across the project index and AST tree. The swarm can perform massive structural updates without stalling the operator's editor thread.

---

## 🧬 High-Performance Context Engine

* **Skeleton & Muscle Compression** — Tree-sitter reduces 10,000 lines to <3KB of context. Only structure and target zones are sent to the model. Works on any grammar Tree-sitter supports.
* **Sub-Millisecond Indexing (`ProjectIndexer`)** — Multithreaded, SIMD-accelerated indexing engine that builds a full symbol graph of 1M+ line codebases in seconds.
* **Autonomous Research Scout (`ResearchScout`)** — Native WinHTTP C++ crawler queries SearxNG/Brave, strips HTML, and injects raw documentation directly into agent context windows. When an agent encounters an unfamiliar API, SDK, or legacy platform, it fetches the docs autonomously before generating code. Hallucination is cut off at the source.
* **Zero-Polling Watchdog (`SovereignWatchdog`)** — OS-native hooks (`ReadDirectoryChangesW` / `inotify`) trigger sub-millisecond AST state-lock re-evaluations the instant a file mutates.

---

## 🧪 Systems Laboratory

### 🔬 Silicon Perception Labs
* **Binary Lab** — `analyze_binary` bridges Ghidra Headless into `ToolRegistry`. The Binary Analyst verifies vectorisation, instruction scheduling, and memory layout at the silicon level — for any architecture Ghidra supports: x86, ARM, RISC-V, MIPS, PowerPC, SPARC.
* **Network Lab** — `capture_network` bridges TShark for autonomous packet inspection, hex-dump parsing, and cryptographic handshake validation across any protocol.
* **Telemetry Mode** — ETW real-time cache miss and branch prediction tracking. VRAM Stacking visualiser for live GPU pressure monitoring.

### 🔧 Master Forge — Universal Cross-Compilation

`WSLManager` maps installed WSL distributions via `wsl.exe -l -v`. `ToolRegistry` injects the correct cross-compilation environment automatically:

| Target | Toolchain Injected |
| :--- | :--- |
| Windows native | `CC=cl`, MSVC/Ninja |
| Linux (WSL) | `CC=clang`, CMake/Ninja |
| RISC-V bare-metal | `CC=riscv64-unknown-elf-gcc` |
| ARM Cortex-M | `CC=arm-none-eabi-gcc` |
| WebAssembly | `CC=emcc`, Emscripten |
| Android NDK | `CC=clang`, NDK toolchain |

Single project. Any target. Environment provisioned automatically.

### 🔧 Universal Tool Registry
Atomic, permission-gated tools: `read_file`, `search`, `patch`, `build_project`, `exec`, `analyze_binary`, `capture_network`. The **Terminal Auto-Heal Loop** intercepts `stderr` for `error:` and `fatal:` strings and autonomously triggers the Sentinel to generate a fix mandate — regardless of which compiler, linker, or runtime produced the error.

---

## 🌐 Decentralised Collaboration — C-Lab Zero

* **Post-Quantum Security** — X25519 + ML-KEM-768 hybrid encryption, implemented in `MeshPeer`
* **CRDT Synchronisation** — Conflict-free editing across humans and AI agents via Loro + Fugue, wired in `SyncManager`. Sync does not operate on raw text diffs — it operates on **AST node deltas** with state-lock hashes attached. Every packet transmitted over the mesh encodes a node mutation, its pre/post state, and the lock hash of the node at the time of the edit. A remote peer receiving a sync packet validates the hash against its own Blackboard state before applying it. If the node is locked by a local agent, the mutation is rejected and queued for re-evaluation — never merged blindly. Raw text line numbers are never transmitted; they are stale the moment any agent touches the tree. Multiple humans and multiple agent swarms can collaborate on the same codebase simultaneously without structural collision.
* **Sovereign Identity** — BIP39 12-word identity generation, fully offline. No accounts. No registration. No external auth providers. Your identity is a wordlist you own.

---

## 🎙️ The Vocal Matrix

### 🎭 The Custodial Persona
A fully integrated voice system. Deadpan, high-intelligence. Inspired by Norman Lovett's Holly from *Red Dwarf*. Real-time barge-in interruption so you can redirect the swarm mid-execution. **Tactical Voice Steering:**

```
"Custodian, throttle the swarm."
"Custodian, open the Binary Lab."
"Custodian, show me what the Sentinel flagged."
"Custodian, switch target to ARM bare-metal."
"Custodian, open a QEMU guest for Solaris."
"Custodian, the Network Scout found something — show me."
```

**Multi-Tier Voice Stack:** Local GPU TTS (Piper/Kokoro) → Offline fallback (WinRT) → Cloud tier → RVC voice overlay.

### 🗂️ Persistent Intelligence Layer — The Memory Web
A visual Nodal Knowledge Graph (not flat tables). The `ProjectLedger` learns and retains:
* Build commands, toolchain quirks, and environment idiosyncrasies per project
* Problem → Fix → Context mappings for near-O(1) resolution of recurring failures
* Cross-project patterns — a fix that worked in your firmware project surfaces when the same class of error appears in your web backend
* Session state: active files, live errors, in-progress task graphs

The Memory Web does not reset between sessions. It compounds. The longer you use it, the faster the swarm resolves novel problems.

---

## ⚙️ Design Philosophy

| Principle | Over |
| :--- | :--- |
| Determinism | Guesswork |
| Verification | Generation |
| Parallelism | Linear chat |
| Native performance | Abstraction layers |
| Control | Convenience |
| Universal scope | Single-ecosystem lock-in |
| Independent review | Self-certifying AI |

---

## 🧨 Final Statement

There is no language Neon Sovereign cannot write.  
There is no platform it cannot target.  
There is no environment it cannot see inside.  
There is no output that ships without being independently verified.

This is not a better IDE.  
This is not a smarter copilot.

**This is a software house. On your machine. Under your control.**

> If your IDE is built on Electron, constrained by plugins, driven by chat, and locked to one ecosystem —
> it is already obsolete.
