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
* A **universal execution window** (SpiceViewport) with eyes inside every environment

---

## 📑 Table of Contents
- [Why Neon Sovereign Exists](#why-neon-sovereign-exists)
- [Universal Scope](#universal-scope--every-platform-every-language-every-target)
- [The Software House Model (The Hive-Mind)](#the-software-house-model-the-hive-mind)
- [The Infinite Swarm in Action](#the-infinite-swarm-in-action)
- [Hardware Requirements & VLM Economics](#hardware-requirements--vlm-economics)
- [Ignition Sequence (Quickstart)](#ignition-sequence-quickstart)
- [Core Architecture](#core-architecture)
- [The Silicon Retina](#️-the-silicon-retina--absolute-visual--spatial-verification)
- [The Verification Gauntlet](#-the-verification-gauntlet-hostile-engineering--omniscience)
- [The SpiceViewport](#️-the-spiceviewport--active-execution-window)
- [Defensive Engineering & Safety](#️-defensive-engineering--safety)
- [Decentralised Collaboration — C-Lab Zero](#decentralised-collaboration--c-lab-zero)
- [The Vocal Matrix](#️-the-vocal-matrix-tactical-steering)
- [Design Philosophy](#️-design-philosophy)

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
| UI/UX hallucinations and broken layouts | AI cannot actually *see* the UI it builds |

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
| **Mobile** | Swift/Obj-C (iOS), Kotlin/Java (Android), Flutter |
| **Embedded & Firmware** | C/C++/Rust on ARM Cortex-M, RISC-V, AVR, ESP32, bare-metal |
| **Games & Graphics** | C++ (Unreal), C# (Unity), GLSL/HLSL shaders, Vulkan/DirectX |
| **Data & ML** | Python, CUDA, ROCm, Triton, ONNX pipelines |
| **Legacy & Exotic** | COBOL, Fortran, Ada, PL/I, assembly (x86, ARM, MIPS) |
| **Scripting & DevOps** | Bash, PowerShell, Lua, Ruby, Go, Dockerfile, Terraform |
| **Mainframe & Enterprise** | z/OS, JCL, CICS, AS/400 RPG |
| **Virtualised Targets** | SGI IRIX, Solaris, VAX/VMS, any QEMU-bootable OS |

The Architect doesn't know "C++ only." The Developers don't care which compiler is in the `ToolRegistry`. The Sentinel audits logic, not language. **The system scales to the target, not the other way around.**

---

## 🏢 The Software House Model (The Hive-Mind)

This is the fundamental shift. Neon Sovereign doesn't give you smarter autocomplete. It gives you a **team** operating through a high-speed **Ephemeral Gossip Protocol** (in-memory SQLite), allowing agents to dynamically negotiate interface contracts before generating muscle code.

In a professional software house, work flows through a defined structure:
1. A **Technical Architect** designs the system and breaks it into parallel workstreams via AST-Pointer UUIDs, drastically shrinking context windows.
2. **UX Specialists** define a Spatial Constraint Graph (the mathematical blueprint for UI layout).
3. **Specialist Developers** execute workstreams in parallel.
4. **The Classroom (Peer Review):** Developers swap AST deltas and cross-check interfaces *before* compilation.
5. A **QA team** independently reviews the output for correctness, safety, and edge cases.
6. A **Tech Lead** (Sentinel) grades the final output, embedding a formal audit trail directly into the source.

Neon Sovereign runs this entire structure autonomously, in real-time, on your machine:

```
You give a task
       ↓
Architect designs the system → produces a JSON Task DAG with AST UUID pointers
       ↓
UX Specialist generates the Spatial Constraint Graph (if UI is involved)
       ↓
Kahn's Algorithm calculates optimal parallel execution order
       ↓
Specialist Developers execute workstreams in parallel (negotiating via Ephemeral DB)
       ↓
Peer-Review Phase: Agents cross-check interfaces and resolve clashes
       ↓
Forge Master compiles in the Shadow Buffer (injecting DPAPI credentials safely)
       ↓
The Verification Gauntlet (Silicon, Protocol, Stability, and Multimodal UI Audits)
       ↓
Sovereignty Gate renders changes as Inline Ghost Text inside the Rope Editor
       ↓
You press `Tab` to accept. Nothing ships without your sign-off.
```

---

## 🐝 The Infinite Swarm in Action

Three tasks across three entirely different domains. Same system. Same control loop. Same guarantees.

**🎯 Task 1:** *Cross-platform C++ TCP client with reconnect logic and exponential backoff.*
1. **Architect** builds the DAG with AST UUID pointers.
2. **Kahn's Algorithm** calculates the optimal parallel execution order.
3. **Developers** execute workstreams in parallel, negotiating socket abstractions via the Ephemeral DB.
4. **Forge Master** cross-compiles in the Shadow Buffer.
5. **Chaos Agent** fuzzes the compiled socket layer, triggering a buffer overflow edge case.
6. **Autopsy Agent** extracts the exact nanosecond of the memory fault via `rr` and mandates a Developer refactor.
7. **Forge Master** recompiles the refactored code, and the **Chaos Agent** re-fuzzes the target to definitively prove the memory boundary is sealed.
8. **Sentinel** approves the hardened code.
9. **Sovereignty Gate** presents the final structure as Inline Ghost Text for your `Tab` approval.

**🎯 Task 2:** *RISC-V bare-metal firmware — interrupt-driven ADC sampling with DMA transfer.*
1. **Architect** decomposes the task into linker script, startup assembly, ISR, and DMA config.
2. **Forge Master** provisions the RISC-V GCC cross-compile chain automatically.
3. **Developers** write the ISR and DMA routines in parallel.
4. **Binary Analyst** runs Ghidra Headless against the ELF, verifying interrupt vector alignment at the silicon level.
5. **SpiceViewport** boots a QEMU RISC-V guest to execute and observe the firmware.
6. **Sentinel** audits `volatile`-correctness on all memory-mapped registers.
7. **Sovereignty Gate** presents the changeset for your `Tab` approval.

**🎯 Task 3:** *Full-stack web app — TypeScript React frontend, Go REST API, PostgreSQL.*
1. **Architect** defines the service boundary DAG.
2. **UX Specialist** generates the Spatial Constraint Graph for the React UI layout.
3. **Developers** execute frontend components and API handlers.
4. **Geometry Auditor** extracts the OS accessibility tree and proves the UI layout mathematically matches the constraints.
5. **Silicon Retina (VLM)** captures a raw frame, flags a low-contrast button overlap, and routes a red-boxed screenshot back to the Developers.
6. **Network Scout** verifies CORS headers via TShark packet inspection on the Shadow Buffer's loopback interface.
7. **Sovereignty Gate** overlays the validated frontend and backend code as Inline Ghost Text.

---

## 🧠 Hardware Requirements & VLM Economics

This system is **not lightweight by design**. Running the Gemma 4 26B Architect, the Gemma 4 E2B Sentinel, and a local Vision-Language Model simultaneously requires serious hardware.

| Component | Minimum (Degraded / Sentinel-Only) | Recommended (Full Swarm) | Notes |
| :--- | :--- | :--- | :--- |
| **CPU** | 8-core (Ryzen 3700X / i7-9700K) | 16-core+ (Ryzen 7950X / i9-13900K) | Agent parallelism & shadow compiles |
| **RAM** | 32GB | 64GB+ | Prevents context thrashing |
| **GPU** | 12GB VRAM | 24GB VRAM (RTX 3090/4090+) | Local LLM execution |
| **Storage** | SSD | NVMe Gen4 | Indexing + builds |
| **OS** | Windows 11 + WSL2 | Same | Native host |

> ⚠️ **VRAM Reality Check & Model Guidelines:** > 
> * **12GB Tier (Degraded Mode):** You cannot run the full swarm locally. The system automatically degrades to running the E2B Sentinel only, heavily offloads the Architect to the CPU (incurring massive latency penalties), or routes to a hybrid API. 
>   * *VLM Recommendation:* Use **LLaVA 1.5 (7B, Q4_K_M)** for the Silicon Retina. It requires ~5GB VRAM. The system will run it serially, pausing the Architect and swapping the VLM into VRAM only when the Geometry Auditor triggers the visual gate.
> * **24GB Tier (Full Swarm Mode):** The recommended tier. Runs the Gemma-4-26B Architect, Gemma-4-E2B Sentinel, Vulkan UI, and SpiceViewport concurrently with zero compromises.
>   * *VLM Recommendation:* Use **Pixtral 12B** or **LLaVA v1.6 34B (Quantized)**. These provide superior aesthetic reasoning and spatial awareness, co-residing seamlessly with the rest of the neural stack.

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

### ⚙️ Step 3 — Provision Neural Weights

Neon Sovereign is **air-gapped by default**. No API keys. No cloud fallback. No hidden telemetry. You own the weights.

```bash
mkdir -p models/

# Download the specific Gemma 4 GGUF models utilized by the Neon Sovereign stack
wget -O models/gemma-4-26B-A4B-it-UD-Q4_K_M.gguf https://huggingface.co/<YOUR_REGISTRY>/resolve/main/gemma-4-26B-A4B-it-UD-Q4_K_M.gguf
wget -O models/gemma-4-E2B-it-Q4_K_M.gguf        https://huggingface.co/<YOUR_REGISTRY>/resolve/main/gemma-4-E2B-it-Q4_K_M.gguf

# Note: Update config/neural.toml to point `architect` and `sentinel` to these exact binaries.
```

---

## ⚡ Core Architecture

### 🧩 The Non-LLM Brain — Deterministic CPU Offloading

The system's intelligence does not begin with the LLM. Fast, deterministic algorithms handle reasoning *before* any model is invoked:

* **Kahn's Algorithm (`BlackboardManager`)** — Topological sorting of the Task DAG. The swarm never guesses execution order; it calculates the mathematically optimal parallel path.
* **Ephemeral Gossip Protocol (`m_ephemeral_db`)** — Agents do not pass massive code blocks to each other. They negotiate interface contracts dynamically via an in-memory SQLite database before writing muscle code, drastically shrinking context windows and preventing hallucinations.
* **Force-Directed MCTS Visualization** — The swarm doesn't just prompt-chain; the `Analyst` agent executes genuine Monte Carlo Tree Search (MCTS)—running simulated rollouts, UCB1 node selection, and backpropagation to evaluate architectural branches. The reward signal evaluating these branches is a composite of historical BM25 similarity (from past successful fixes), projected token-context footprint, and statically analyzed compiler pass probability *(derived dynamically from Tree-sitter cyclomatic complexity and historical linker-fault heuristics)*. This reasoning tree is dynamically mapped in the UI using a real-time Spring-Embedding algorithm.
* **BM25/TF-IDF Memory (`ProjectLedger`)** — Historical fixes stored in SQLite, retrieved via a native C++ BM25 ranker. O(1) lookup.

### 🐝 The Infinite Swarm — Role-Locked Specialisation

Every agent in the swarm operates under hard, non-negotiable boundaries enforced by the C++ core:

| Agent | Role | Hard Constraint |
| :--- | :--- | :--- |
| **The Architect** | Designs the system via AST UUID pointers | Barred from writing implementation code |
| **The Developers** | Execute parallel implementation workstreams | Cannot modify the overall DAG or task structure |
| **The Forge Master** | DevOps scope (Builds, NDK, ADB pipelines) | Barred from mutating application logic; strictly manages build scripts, linkers, Dockerfiles, and deployment |
| **The Binary Analyst** | Ghidra Headless + EGL/VirtIO Audits | Strictly read-only analysis; cannot alter source code |
| **The UX Specialist** | Defines spatial constraint blueprints | Generates mathematical bounds only; barred from writing UI framework code |
| **The Autopsy Agent** | Rewinds execution state via `rr` / eBPF | Forensic extraction only; read-only access to crash dumps and registers |
| **The Chaos Agent** | Agentic fuzzing of SPICE queues & UI | Destructive testing only; routes crashes to the Autopsy Agent to mandate Developer fixes |
| **The Sentinel** | Adversarial code review & Multimodal QA | Auditing and grading only; never generates or patches code |

---

## 👁️ The Silicon Retina — Absolute Visual & Spatial Verification

Current AI IDEs are blind text-calculators. Neon Sovereign **looks at what it builds.**

1. **Synthetic ID Injection:** Developer agents automatically stamp AST UUIDs into the compiled UI framework's accessibility tags.
2. **Geometry Auditor:** Using native Windows `UIAutomation` and Linux `AT-SPI`, the system extracts absolute `[X, Y, W, H]` coordinates from the rendered application (waiting for UI idle-state to prevent desync).
3. **The Math Gate:** The Sentinel verifies the parsed coordinates against the UX Specialist's initial Spatial Constraint Graph.
4. **The VLM Retina:** If the math passes, a raw framebuffer screenshot is captured via GDI/WIC. A local Multimodal Vision-Language Model audits the app for contrast, overlap, and aesthetic issues.
5. **Red-Box Feedback:** Any spatial or visual failure results in a red-boxed screenshot routed immediately back to the Developers for an autonomous refactor loop.

---

## 🗡️ The Verification Gauntlet: Hostile Engineering & Omniscience

Neon Sovereign doesn't just write polite code; it attacks it to guarantee stability before it reaches the Sovereignty Gate.

* **Agentic Fuzzing (The Chaos Protocol):** After a successful build, the Chaos Agent takes over the QEMU/ADB bridge, rapidly resizing framebuffers, thrashing VirtIO queues, and spamming malformed HID packets to ensure the hypervisor doesn't break.
* **Time-Travel Autopsy:** If a kernel panic or JNI crash occurs across an exotic OS boundary, the Autopsy Agent uses `rr` (Record and Replay) and eBPF probes to rewind the execution trace. It injects the exact nanosecond of memory corruption back into the Swarm's context, routing the failure directly to the Developers for a fix.
* **Micro-Architecture Optimizer:** High-complexity loops trigger the Swarm to write standard C++, ARM NEON, and aggressive `#pragma` variants in parallel. The Forge Master compiles them, benchmarks CPU cycles and cache misses via PDH telemetry, and silently commits the mathematically fastest variant.

---

## 🖥️ The SpiceViewport — Active Execution Window

The `SpiceViewport` is Neon Sovereign's native window into any execution context. It isn't passive.
* **Active VirtIO HID Injection:** Agents autonomously test UI code by sending synthetic mouse clicks and keystrokes directly into virtualized targets (Solaris, SPARC, Android emulators) and tracking the VirtIO input-to-frame latency.
* **Edge Forge (ADB Pipeline):** Autonomously compiles C++/Rust NDK backends, packages APKs, deploys via the Android Debug Bridge, and intercepts Logcat telemetry natively to trap JNI panics in real-time.

---

## 🛡️ Defensive Engineering & Safety

### 🔒 The Sovereignty Gate (Inline Ghost Diffs & The Rejection Path)
When the Sentinel grades and approves code, it is rendered via the 120FPS Slint UI directly in your editor as **Inline Ghost Text**. Green for additions, red for removals. You press `Tab` to accept the diff, instantly locking the AST state-hashes.

**The Rejection Path:** Operator intent overrides all. If you reject the diff (e.g., via `Esc`), the UI opens a frictionless critique prompt. You type a prose note explaining *why* it's wrong ("Memory bounds are safe, but I want to use standard library arrays instead of raw pointers"). This operator mandate is injected directly into the Ephemeral DB as a High-Priority Correction, and the Swarm dynamically routes back to the Architect to re-plan the branch.

### 🔐 Windows DPAPI Secret Store
Agents request API keys and passwords via abstract tags (`DB_PASSWORD`). The Forge Master retrieves the real credentials from the OS encrypted DPAPI vault and injects them as environment variables during QEMU boot or Shadow Compilation, entirely shielding plaintext from the LLM.

---

## 🌐 Decentralised Collaboration — C-Lab Zero

Neon Sovereign isn't just an isolated engine; it is a node in a completely decentralized engineering network.

* **Post-Quantum Security** — Genuine Rust-backed X-WING handshakes (X25519 + ML-KEM-768 Kyber) over raw TCP/UDP.
* **True Loro CRDT Synchronisation** — Conflict-free editing via native Rust `Loro` bindings. Sync operates on **AST node deltas** locked by cryptographic hashes, not raw strings.

### 🧠 Memory Web Synthesis (`.sovereign` Export)
The Swarm's intelligence (cross-platform fixes, NDK quirks, interface contracts) can be synthesized into a highly compressed `.sovereign` SQLite export. This serves as the core distribution mechanism, allowing you to port Swarm intelligence across air-gapped workstations or seamlessly share learned context over the C-Lab Zero Mesh.

### 🔑 Sovereign Identity (BIP39)
**True offline, decentralised identity.**
Neon Sovereign completely rejects cloud accounts, email registrations, and external auth providers. 
Your identity on the C-Lab Zero mesh is a cryptographic **BIP39 12-word mnemonic phrase**, generated fully offline. You own the keys. When collaborating with other developers or swarms over the mesh, your state-lock hashes and CRDT operations are cryptographically signed using this offline identity. 

---

## 🎙️ The Vocal Matrix (Tactical Steering)

A fully integrated voice system powered by local **Piper TTS**. Real-time barge-in interruption allows you to redirect the swarm mid-execution without touching the keyboard. 

The IDE is a living command center. **Tactical Voice Steering examples:**
* *"Custodian, the Chaos Agent triggered a panic — rewind the eBPF trace and show me the exact JNI boundary failure."*
* *"Custodian, halt the frontend developers. I'm updating the Spatial Constraint Graph."*
* *"Custodian, approve the Sentinel's diff and commit the state-lock."*

**Multi-Tier Voice Stack:** Local GPU TTS (Piper/Kokoro) → Offline fallback (SAPI) → RVC voice overlay.

---

## ⚙️ Design Philosophy

| Principle | Over |
| :--- | :--- |
| Determinism | Guesswork |
| Spatial/Visual Verification | Generative Hallucination |
| Parallelism & Peer Review | Linear chat |
| Native performance | Abstraction layers |
| Replayed Omniscience (rr) | Static Crash Logs |
| Universal scope | Single-ecosystem lock-in |

---

## 🧨 Final Statement

There is no language Neon Sovereign cannot write.  
There is no platform it cannot target.  
There is no environment it cannot see inside, measure, and actively test.  
There is no output that ships without being independently verified by math, vision, and compiler loops.

This is not a better IDE.  
This is not a smarter copilot.

**This is a software house. On your machine. Under your control.**

> If your IDE is built on Electron, constrained by plugins, driven by chat, blind to its own UI, and locked to one ecosystem — it is already obsolete.
