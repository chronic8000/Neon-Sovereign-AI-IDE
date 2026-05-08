# Neon Sovereign: The Universal Engineering Workstation

**Neon Sovereign** is a high-performance, fully native **C++20 AI-powered IDE** built from first principles. It is not a chat assistant, a copilot, or a plugin. It is a **Fully Autonomous Execution Pipeline** designed to operate as a deterministic software house.

Developed as a sovereign alternative to bloated, Electron-based tools, it utilizes a parallelized, role-locked swarm of AI agents to plan, write, review, verify, and ship code across every platform, language, or target.

---

## 🚫 The Failure of Modern AI IDEs
Modern tools are architecturally limited by their foundations. Neon Sovereign was built to solve these specific systemic issues:

| Problem | Root Cause | Sovereign Solution |
| :--- | :--- | :--- |
| **Latency & Bloat** | Built on Electron / Web Tech | **Native C++20 + Vulkan (120FPS)** |
| **"Babysitting"** | AI stops for permission at every file | **Autonomous Execution Pipeline (Task DAG)** |
| **Amnesia** | Context windows lost after few messages | **Persistent SQLite Memory Ledger (BM25)** |
| **Hallucination** | No real-time verification | **Compiler-Driven Shadow Buffer & Sentinel QA** |
| **Blind Execution** | AI cannot see the UI it builds | **Silicon Retina (VLM-Driven Visual Audit)** |
| **Single-Threaded** | One AI doing everything sequentially | **Parallel Swarm (Architect + Developers + QA)** |
| **Vendor Lock-in** | Built around specific toolchains | **Universal Target Scope (Firmware to Web)** |
| **Inference hosting** | Often cloud APIs & quotas | **Local weights (Ollama / on-box), air-gap friendly** |

---

## 🏢 The Software House Model (Fully Autonomous Execution Pipeline)
Neon Sovereign operates as an execution engine, coordinating a parallelized swarm through a defined, autonomous pipeline:

### 📦 Example Output (Real Run)
**Brief**: "Build a cross-platform file sync tool with a GUI"
**Result**:
- ✅ 14 C++ source files generated & cross-linked.
- ✅ Qt-based GUI compiled (Windows + Linux).
- ✅ Background sync engine (threaded, verified via ForgeMaster).
- ✅ 37 unit tests (all passing).
- ✅ UI validated via Silicon Retina (no layout collisions).
**Artifacts**: `/build/windows/sync.exe`, `/docs/forensic_audit.sqlite`.

### 🤖 What "Autonomous" Actually Means
Neon Sovereign does **NOT**:
- Ask for confirmation between individual file edits.
- Require manual copy/pasting of code snippets.
- Lose architectural context between development steps.

Neon Sovereign **DOES**:
- Generate and execute a comprehensive **Task DAG**.
- Retry failed builds autonomously by analyzing compiler feedback.
- Use the **ForgeMaster** to verify code in shadow buffers before disk commits.
- Escalate to the user only on unrecoverable architectural ambiguity.

1.  **The Brief**: You provide a high-level goal.
2.  **Architecture**: The **Architect** designs the system and produces a **JSON Task DAG** (Directed Acyclic Graph) using AST-Pointer UUIDs to minimize context bloat.
3.  **Parallel Execution**: **Specialist Developers** execute workstreams in parallel. They coordinate via an **Ephemeral Gossip Protocol** (in-memory SQLite) to negotiate interface contracts before writing code.
4.  **The Verification Gauntlet**:
    *   **Forge Master**: Handles cross-compilation in a **Shadow Buffer** to verify builds before touching disk.
    *   **Sentinel Auditor**: An independent agent that reviews code cold, looking for edge cases and security vulnerabilities.
    *   **Silicon Retina**: Captures framebuffers from running targets (QEMU/ADB) and uses a Vision-Language Model (VLM) to audit for layout overlaps, contrast violations, and missing UI elements. (Note: Validates visual integrity; does not replace human UX intent).
    *   **Chaos Agent**: Performs agentic fuzzing and stress testing against virtualized targets.
5.  **Handoff**: You return to a running application, proof-of-work screenshots, and a complete forensic audit log.

---

## 🌍 Universal Target Scope
The system scales to the target, not the other way around. The Swarm adapts its toolchain and verification strategy automatically.

*   **Systems & Native**: C, C++, Rust, Zig (Linux, Windows, macOS).
*   **Web & Frontend**: TypeScript, React, Vue, WASM.
*   **Mobile**: Swift (iOS), Kotlin (Android) via NDK/ADB integration.
*   **Embedded & Firmware**: Bare-metal ARM Cortex-M, RISC-V, AVR, ESP32.
*   **Games & Graphics**: Unreal (C++), Unity (C#), GLSL/HLSL shaders.
*   **Legacy & Exotic**: COBOL, Fortran, Ada, assembly (x86, ARM, MIPS).
*   **Virtualised Targets**: QEMU-bootable OSs (Solaris, IRIX, VAX/VMS).

---

## ⚡ Core Architecture: Built for Silicon Performance

### 🧩 Deterministic "Non-LLM" Brain
Intelligence begins with C++ algorithms before any LLM is invoked:
*   **Kahn’s Algorithm**: Mathematically optimal parallel task execution.
*   **Tree-sitter Complexity Router**: Routes complex logic to 26B models while keeping trivial tasks on 2B models to save VRAM.
*   **Context Vault**: Persistent grounding. Drag-and-drop documentation and diagrams directly into the IDE to persistently ground the swarm's reasoning.
*   **BM25 SQLite Memory**: Near-O(1) retrieval of historical project fixes and toolchain quirks.

### 🔌 Local Neural Operator (Offline LLM, Cursor-Class Loop)

Neon Sovereign is built to be a **sovereign workstation**: weights run **on your machine** (see [Provision Neural Weights](#provision-neural-weights)), not rented from a vendor API. That is not a compromise—it is the architectural point: **your context never leaves the box**, and the swarm still behaves like a serious agent product, not a sidebar chat.

**Chat panel vs. gateway paths**

| Mode (`AgentialIntent`) | Neural transport | Notes |
| :--- | :--- | :--- |
| **CHAT** | Native **Ollama `/api/chat`** via `AIGateway::call_local_inference_messages` | **Multi-turn session**: system mandate + rolling user/assistant pairs (bounded window). History clears when you leave CHAT or call `clear_ui_chat_session()`. |
| **BUILD / DEBUG** (when the panel runs `ask()`, not steering-only) | **`call_winhttp_messages`**: seeded **system + user**, then the existing **tool loop** (`/api/chat` + `ToolRegistry` + Sentinel approval) | Previously unused `call_winhttp` is now the real agentic path for these intents; CHAT mode never attaches gateway tools to the panel (doctrine: consultation only). |

**Retry / steering chips (UI)**

- **Regenerate**: last Sovereign prose row in CHAT mode gets a **↻ Regenerate reply** chip. It pops the last completed turn from the gateway transcript and re-runs inference without duplicating your user bubble.
- **Failed tool row**: structured **tool_result** lines (`kind` 21) with `tool_ok == false` expose **↻ Retry / steer swarm**, which enqueues **operator steering** on the blackboard (same pipeline as mid-flight chat corrections during active DAG work).

**SDK / swarm (autonomous agent)**

| Idea in cloud IDEs | What Sovereign does |
| :--- | :--- |
| Agent mode: plan → tool → observe → repeat | **Developer agents** run a **Reason+Act loop** over real tools: `read_file`, `write_file`, `execute_command` (bridged into the same `ToolRegistry` / shadow buffers as the rest of the IDE). **ReAct** uses **`LLMInterface::chat(messages)`** → **`call_local_inference_messages`** with thread built from JSON `history`. |
| Terminal + workspace awareness | Tool results (build output, file reads) are fed back into the next inference turn—**ground truth over hallucination**. |
| Low-noise “thought” lines | `SwarmChat::post_agent_thought` emits short lines (e.g. parsed tool count, finish). |
| Persistent transcript | **`SwarmChat`** can mirror into **`ProjectLedger::insert_reasoning`** (`set_project_ledger`); operator steering **enqueue** is also logged for replay. |

**Throughput vs. depth (both first-class)**

- **Default / production posture**: full multi-step loop with **executed** tools—the offline analogue of an agent that actually edits and runs commands.
- **`SOVEREIGN_SDK_SINGLE_SHOT=1`**: optional **single-inference** path for tight iteration windows (e.g. CI smoke velocity). It does not redefine the product; it schedules faster completion when the DAG allows one-shot delivery.

This is the same doctrine as the rest of the README: **AI is not an assistant answering prompts—it is an autonomous engineer inside a deterministic execution pipeline**, with local inference as the substrate.

### 📋 Engineering reference (major subsystems)

Useful when navigating `src/`:

| Area | Role |
| :--- | :--- |
| **`AIGateway`** | Local inference: `call_local_inference` (generate-style bridge), `call_local_inference_messages` (`/api/chat`, SDK + CHAT UI), `call_winhttp` / **`call_winhttp_messages`** (tool loop for BUILD/DEBUG `ask()`). Neural lane mutex shared across generate/chat paths. |
| **`SwarmChat` bridge** | `post`, structured segments (`tool_call` / `tool_result` / `agent_thought`), optional **ledger** mirror, **operator steering** ledger hook. |
| **`BlackboardManager`** | Task DAG, **`enqueue_operator_steering`** / drain into prompts, gossip hooks. |
| **`HiveViewModel` / Slint `ChatMessage`** | Composer-style rows (`kind` 20–22), fold toggles on tool cards, **retry_slug** for chips → **`AppActions.retry_chat_action`**. |
| **`ProjectLedger`** | SQLite: reasoning logs, knowledge, contracts/gossip, AST vault, terminal flight recorder. |

### 🎮 Sovereign MDI (Command Center)
A hybrid of the classic Program Manager and modern IDEs. Built on a **120FPS Slint engine**, everything is a child window (Editor, Hive, Terminal, Lab).
*   **Resolution Independence**: MDI child windows use dynamic layout clamping to adapt to any display.
*   **Contextual Elevation**: Windows are promoted to the front based on the active **Agential Intent Mode** (CHAT, BUILD, or DEBUG).

### 🕵️ Forensic Historian
Captures and cleans all PTY output (ANSI noise removed) into a searchable SQLite ledger. Agents use this to "look back" at previous build failures and environment changes, eliminating the "context reset" issue of standard terminals.

### 🐝 The Silicon Leash (Resource Governor)
To prevent GPU saturation, Neon Sovereign implements static VRAM partitioning:
*   **Inference**: 18GB (Architect + Sentinel).
*   **Renderer**: 2GB (Vulkan/DirectX).
*   **SpiceViewport**: 2GB (QEMU/VNC observability).
*   **System Reserve**: 2GB.
The governor enforces these budgets before inference begins, preventing OOM crashes.

---

## 🧪 Systems Laboratory & SpiceViewport
The **SpiceViewport** is a live window into any execution context. 
*   **Active HID Testing**: Agents send synthetic clicks and keystrokes to test UI responsiveness.
*   **ADB Forge**: Autonomously compiles, deploys, and debugs Android applications via NDK.
*   **Binary Lab**: Bridges Ghidra Headless into the swarm for silicon-level verification of instruction scheduling and memory layout.

---

## 🎙️ Tactical Steering (The Vocal Matrix)
Redirect the swarm mid-execution using local **Piper/Kokoro TTS**.
*   *"Custodian, halt the developers. I'm updating the architecture."*
*   *"Custodian, open the Binary Lab and show me the disassembly for the ISR."*
Any tactical override is injected as a High-Priority Correction into the Ephemeral DB, forcing a dynamic re-plan.

---

## ⚠️ Current Limitations (Active Alpha)
Neon Sovereign is an active engineering frontier. While the architecture is designed for full autonomy, users should note the following constraints:
*   **VRAM Intensity**: 24GB+ VRAM is recommended for the full Architect/Sentinel/Retina swarm.
*   **Target Stability**: C/C++ and Rust are Tier-1 targets. Web and Mobile support are currently in active stabilization.
*   **Active Iteration**: Complex UI frameworks may require multiple iteration cycles. Some manual intervention may be required for exotic build environments.
*   **Untested Status**: The GUI is currently in a "Beta-Test" state. Expect rapid updates and breaking structural changes.

---

## 🔥 Ignition Sequence (Quickstart)

### Prerequisites
*   **Windows 11** (23H2+)
*   **Visual Studio 2022** (Desktop C++ workload)
*   **CMake ≥ 3.28**, **Git**, **Rust**
*   **WSL2** with Ubuntu 22.04+ (Vulkan 1.3 support)

### Build (Windows Native)
```powershell
cmake -S . -B build/windows -G "Visual Studio 17 2022" -A x64
cmake --build build/windows --config Release
```

### Build (WSL Linux Layer)
```bash
wsl
sudo apt update && sudo apt install build-essential clang lld ninja-build pkg-config libvulkan-dev libxkbcommon-dev
cmake -S . -B build/linux -G Ninja
cmake --build build/linux
```

### Provision Neural Weights
Neon Sovereign is **air-gapped by default**. You own the weights.
1.  **Architect**: Gemma-4 26B MoE (Q4_K_M).
2.  **Sentinel**: Gemma-4 E2B (Q4_K_M).
Configure these in `config/neural.toml`. The system will automatically recalibrate `max_concurrent_agents` based on detected VRAM.

---

## 🛡️ Security & Zero-Leak Mandate
*   **Encrypted Secrets**: API keys and credentials are encrypted via **Windows DPAPI** (NCrypt) and never exposed to the LLM context.
*   **Offline Identity**: Collaboration uses **BIP39 12-word mnemonics**. No accounts. No cloud.
*   **Transactional AST Locks**: Agents cannot mutate overlapping code nodes simultaneously, preventing race conditions.

---

## 🏆 Comparison
| Feature | Cursor / VSCode | **Neon Sovereign** |
| :--- | :--- | :--- |
| **Base** | Electron (TS/JS) | **Native C++20 (Vulkan)** |
| **Autonomy** | Prompt & Wait | **Set Brief & Walk Away** |
| **Verification** | User Reviews Diffs | **Shadow Buffer & Silicon Retina** |
| **Memory** | Transient / Amnesiac | **Persistent SQLite (BM25)** |
| **Hardware** | Low utilization | **NUMA-Aware Affinity / VRAM Partitioning** |
| **Visibility** | Blind to App UI | **SpiceViewport (QEMU/ADB)** |

---

Neon Sovereign is not just an IDE. It is the first system designed to actually finish what other AI tools start.

**Define the outcome. Neon Sovereign handles the execution.**
What used to take hours of manual prompting now completes in the background.

> If your IDE is built on Electron, constrained by plugins, driven by chat, and blind to its own UI — it is already obsolete.
