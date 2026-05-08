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

**Orthogonal audits**: the **Logic** model (Gemma-4–class for architecture and codegen) and the **Sentinel / Speed** model used for critique and fast repairs must be **different families**—by doctrine **Qwen for Sentinel**, never a second Gemma-4 alongside the core (see provisioning above).

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
| **`AIGateway`** | Local inference: `call_local_inference` (generate-style bridge), `call_local_inference_messages` (`/api/chat`, SDK + CHAT UI), `call_winhttp` / **`call_winhttp_messages`** (tool loop for BUILD/DEBUG `ask()`). Concurrency is governed by **`m_active_inference_count`** / neural governor slots—not a global WinHTTP mutex. |
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
VRAM use is **measured and capped**, not a single fixed “18 GB inference slice.” The runtime combines **hardware detection**, **process limits**, **phase-aware loading**, and **math for context windows**.

**Who gets to use the GPU**

- **`SysProbe::get_gpus`** (`sys_probe.cpp`) keeps adapters that report **≥ 4 GB** dedicated VRAM (marketing “4 GB” chips that report slightly above 4 GB still qualify). Smaller adapters are skipped and startup falls back to **`OLLAMA_NUM_GPU=0`** / software paths (`main.cpp`).

**How much VRAM Ollama may use**

- **`OLLAMA_VRAM_LIMIT`** is set to **`max(0, total_vram − 4 GB)`** for the chosen GPU (`main.cpp`): a **4 GB OS/desktop reserve** is subtracted from reported dedicated VRAM. Example: **8 GB** total → **~4 GB** budget for weights + KV; **16 GB** → **~12 GB**. An **exactly 4 GB** card often yields **0 B** headroom after reserve—usable mostly via **CPU**, lighter pulls, or drivers that report **slightly more than 4 GB**.

**Why laptop-class GPUs are viable**

- **Automatic tiering** (`sovereign_provisioner.cpp`): VRAM bucket **≥ 20 GB** → larger Architect + Qwen 7B; **≥ 12 GB** → 9B-class Architect + Qwen 7B; **&lt; 12 GB** (includes typical **8 GB** laptops) → **Gemma-4 E4B**–class Architect + **Qwen 2.5 Coder 1.5B** Sentinel—small critic/audit models aligned with tight VRAM.

- **Audit hot-swap** (`swarm_controller.cpp`): when fabrication is finished and Sentinel work is pending, the swarm **drains inference**, **evicts** Logic-tier weights (and Gemma **`-drafter`** when applicable), then **locks** the Sentinel model. That keeps VRAM pressure closer to **one large logical stack per phase**, instead of permanently pinning two full stacks.

- **Context budget**: **`calculate_optimal_context_budget`** (`sys_probe.cpp`) derives **`num_ctx`** from pooled VRAM minus weight and reserve heuristics (floors at **2048** tokens when memory is tight).

**Parallelism vs. resident weights**

- Overlapping calls are bounded by the gateway governor (**`m_max_concurrency`**, default **2** in `gateway.hpp`). That limits simultaneous **requests**, not “two full 30B copies”—combined footprint still follows provisioner + hot-swap + **`OLLAMA_VRAM_LIMIT`**.

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
*   **GPU VRAM (what “supported” means here)**:
    *   **Comfort zone** (**24 GB+**): Large Architect tiers, Retina/VLM workflows, and headroom for long contexts—closest to the “full workstation” story.
    *   **Supported daily-driver / laptop class** (**8 GB+** discrete): Explicit **lightweight provisioner path** (E4B-scale Logic + **Qwen 1.5B** Sentinel), **`OLLAMA_VRAM_LIMIT`** derived from detected VRAM, and **audit hot-swap** so you are not paying two full stacks at peak forever.
    *   **Minimum enumeration floor** (**≥ 4 GB** reported dedicated): GPUs below **4 GB** are not selected as qualified silicon; **~4 GB** cards may show **zero** bytes left after the **4 GB** OS reserve—expect **CPU-heavy** behavior unless you stay on tiny models.
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
*   **GPU**: **Discrete ≥ 8 GB** VRAM is the practical target for native laptop use with the auto light tier; **≥ 4 GB** may be detected but often has little usable headroom after the governor reserve (details under **The Silicon Leash** earlier in this readme).

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
1.  **Architect / core logic tier**: **Gemma-4** family (e.g. 26B MoE Q4_K_M)—planning and implementation.
2.  **Sentinel / Speed tier (critic, peer-style fixes, audits)**: **Qwen** (e.g. **qwen2.5-coder** at a size your VRAM allows)—must **not** be another Gemma-4: paired Gemma models **correlate failures** and amplify hallucinations.

Configure tags in **`config/neural.toml`** (and persisted UI JSON). For **Ollama tag** mode, **`enforce_model_pairing`** in **`config_manager.cpp`** refuses **Gemma-4 + Gemma-4** Logic/Sentinel pairs and rewrites Sentinel to **`qwen2.5-coder:7b-q5_k_m`**. Local **`.gguf` paths** are never rewritten automatically (mixed layouts stay operator-controlled).

**Gateway concurrency** (**`max_concurrent_agents`**, default **2**) is a separate knob from VRAM sizing—it limits overlapping inference workers but does not replace tier selection; tune it in settings when your GPU keeps up or struggles.

---

## 🧪 Headless smoke tests & verification pipeline

Smoke tests exercise the full **Software House** path (Architect DAG → parallel Developers → **Crucible** transactional commits) without the GUI. Archives land under **`<repo-root>/smoke-test/<id>/`** (override parent with `SOVEREIGN_REPO_ROOT`). Each run writes **`smoke_test_swarm.log`**, **`smoke_trace.txt`**, and generated sources.

### Invocation

```powershell
.\Neon-Sovereign.exe smoke-test "Your engineering brief here"
.\Neon-Sovereign.exe smoke-test brief "Your engineering brief here"
.\Neon-Sovereign.exe smoke-test full "Your engineering brief here"
```

The `brief` / `full` tokens only select the argv shape; they share the same pipeline and validation.

The brief must be **substantive**: rejected if fewer than **3 words** or fewer than **12** non-whitespace characters (prevents meaningless “success” on noise).

**Headless defaults**: smoke-test sets **`SOVEREIGN_LOGIC_MODEL`**, **`SOVEREIGN_SPEED_MODEL`**, and **`SOVEREIGN_SDK_SINGLE_SHOT=1`** for CI stability and throughput (see trace header for resolved values).

**Exit codes**:

| Code | Meaning |
| :--- | :--- |
| **`0`** | Final verdict **SUCCESS** (see below). |
| **`1`** | Smoke finished but verdict **FAILURE** (timeout, stalled/incomplete tasks, missing or **empty** output files). |
| **`2`** | CLI usage error or brief rejected (too short). |

**SUCCESS** (recomputed at shutdown from the blackboard): seed task **Completed** or **Stalled**, **no** active swarm work, **no** non-seed task stuck outside **Completed**, every **Completed** non-seed task has an **existing, non-empty** file under the smoke workspace (`target_file`), and **at least one** non-seed task completed.

If the DAG is still active when the smoke timeout fires, the archive logs **`Reason: TIMEOUT`** and **`FAILURE`**.

### Crucible: peer review, auto-repair, then Sentinel

Each **`submit_patch`** (Developer → Crucible) runs **inner repair rounds** before the blackboard consumes a **swarm retry**. Order per attempt:

1. **Bracket preflight** (fast SIMD balance). On failure → **Speed-tier** LLM structural fix.
2. **Peer gate** (optional): another model pass asks for **`PEER_APPROVED`** vs **`PEER_ISSUES`** + bullets; issues feed a **Logic-tier** rewrite *before* Sentinel.
3. **Sentinel** (`AdversarialEngine::run_critic`): Red Team hypothesis + Speed audit. **Only the `[AUDIT]:` section** is interpreted for approve/reject (the hypothesis line alone cannot false-trigger rejection).
4. **Shadow verification** (includes the same bracket gate + OMNI-BYPASS promotion path). On failure → Logic-tier fix from the error text.

Only after **all inner rounds** fail does Crucible call **`commit_task(false)`** with **`crucible_auto_repair_exhausted`**. That burns **one** swarm-level retry, not one per gate.

### Full environment list (`smoke_trace.txt` parity)

The first lines of **`smoke_trace.txt`** are stable forensic fields and commentary; **`readme.md`** lists the same items so operators do not have to diff binaries against logs.

**Fixed keys (not environment variables)**

| Trace field | Meaning |
| :--- | :--- |
| **`simulation_id`** | Monotonic run folder under `<parent>/smoke-test/<id>/`. |
| **`cwd`** | Process working directory when the smoke swarm starts. |
| **`smoke_path`** | Absolute path to this archive (artifacts + logs). |
| **`SOVEREIGN_LOGIC_MODEL=`** | Raw env value if set; empty string in the trace when unset (GUI sessions typically rely on **`config/neural.toml`** instead). |
| **`SOVEREIGN_SPEED_MODEL=`** | Same pattern for Speed-tier / Sentinel critic routing. |
| **`resolved_logic_model`** | Logic-tier tag passed to **`set_model`**: **`getenv("SOVEREIGN_LOGIC_MODEL")`** or fallback **`gemma-4-e2b-it-q4_k_m`**. Standard **`smoke-test`** forces Gemma E2B via **`_putenv`** before load—see **Headless defaults**. |
| **`resolved_speed_model`** | Speed / Sentinel tag: **`getenv("SOVEREIGN_SPEED_MODEL")`** or fallback **`qwen2.5-coder:1.5b`** in the smoke initializer when unset. **`smoke-test`** normally forces Qwen via **`_putenv`**. If both tiers would resolve to **Gemma-4** Ollama tags, **`enforce_model_pairing`** rewrites Sentinel to **`qwen2.5-coder:7b-q5_k_m`** before **`set_sentinel_model`**. |
| **`ollama_managed_port`** | From **`ConfigManager`** / settings JSON (default **11435** when managed Ollama is used—not an env var in the trace). |

**Embedded commentary** (copied into the trace for reproducibility)

- **Neon hot-swap**: model evict/lock behavior is governor-gated; see **`startup.log`** for **`[GOVERNOR]`** / **`[SWARM]`** lines.
- **Developer path**: default SDK posture is **Reason+Act with real tool execution** (`read` / `write` / `execute`); not chat-only.
- **Throughput mode**: explains **`SOVEREIGN_SDK_SINGLE_SHOT=1`** → `planSingleShotCodegen` (CI/smoke velocity; not the architectural ceiling for interactive work).

**`SOVEREIGN_*` variables** (every name that appears in the trace narrative)

| Variable | Default when unset | Allowed range | Purpose |
| :--- | :--- | :--- | :--- |
| **`SOVEREIGN_LOGIC_MODEL`** | From **`config/neural.toml`** via **`ConfigManager`** (smoke overwrites to Gemma E2B before load) | Ollama tag string | Overrides persisted Logic-tier model on startup (`config_manager.cpp`). |
| **`SOVEREIGN_SPEED_MODEL`** | From **`config/neural.toml`** (smoke overwrites to Qwen 1.5B before load) | Ollama tag string | Overrides Speed-tier / Sentinel routing model on startup. |
| **`SOVEREIGN_SDK_SINGLE_SHOT`** | off (`0` / unset) | `0` / `1` (any non-empty, non-`0` enables) | **`autonomous_agent_impl`**: one-shot codegen vs full **`planReact`**. Smoke-test **forces `1`** after setting models. |
| **`SOVEREIGN_REACT_MAX_STEPS`** | `24` | `4`–`128` | Max Reason+Act iterations when single-shot is off. |
| **`SOVEREIGN_REPO_ROOT`** | (derive from repo detection beside `startup.log`) | filesystem path | Parent directory for **`smoke-test/<id>/`** (`main.cpp`). |
| **`SOVEREIGN_SMOKE_TIMEOUT_SEC`** | `3600` | `300`–`14400` | Outer poll/wait budget for the smoke harness. |
| **`SOVEREIGN_ARCHITECT_ASK_TIMEOUT_SEC`** | `1800` | `120`–`7200` | Per-call timeout for Architect **`gateway->ask()`** while producing the JSON DAG (`swarm_controller.cpp`). |
| **`SOVEREIGN_CRUCIBLE_AUTO_REPAIR_ROUNDS`** | `8` | `1`–`32` | Inner **`submit_patch`** repair rounds before a swarm retry (`crucible.cpp`). |
| **`SOVEREIGN_PEER_GATE`** | on | set exactly **`0`** to disable | Skip Speed-tier peer review before Sentinel (`crucible.cpp`). |

For normal **GUI** runs, **`SOVEREIGN_LOGIC_MODEL`** and **`SOVEREIGN_SPEED_MODEL`** override the values from **`config/neural.toml`** when those variables are set in the environment at **`ConfigManager::load()`** time (`config_manager.cpp`).

**Pairing guard**: **`AIGateway::set_model`** / **`set_sentinel_model`** apply the same Gemma-4 / Gemma-4 refusal so the live gateway cannot drift into twin-Gemma configuration from the UI alone.

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
| **Hardware** | Low utilization | **NUMA-Aware Affinity / VRAM-aware governor & audit hot-swap** |
| **Visibility** | Blind to App UI | **SpiceViewport (QEMU/ADB)** |

---

Neon Sovereign is not just an IDE. It is the first system designed to actually finish what other AI tools start.

**Define the outcome. Neon Sovereign handles the execution.**
What used to take hours of manual prompting now completes in the background.

> If your IDE is built on Electron, constrained by plugins, driven by chat, and blind to its own UI — it is already obsolete.
