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

### Project playbook (`ledger.db` / `ProjectMetadata`)

Neon persists operator-facing “vital facts” in SQLite (`ProjectLedger` → table **`ProjectMetadata`**, key/value, scoped by `project_uuid`; the default workspace often uses an empty UUID). **`AIGateway`** injects non-empty keys into **BUILD / DEBUG** prompts and **`prompt_with_system`** so local models see the same facts as your team.

**Recommended keys** (convention; extend as needed):

| Key | Purpose |
| :--- | :--- |
| **`build_folder`** | Output directory for binaries (existing). |
| **`script_mappings`** | JSON or prose mapping script names to paths (existing). |
| **`windows_build_command`** | Canonical Windows build (e.g. `.\build.bat` from repo root). |
| **`smoke_command`** | Headless smoke entrypoint (e.g. `.\scripts\run-smoke-ci.ps1`). |
| **`storage_root_hint`** | Where `ledger.db` lives relative to Neon (`storage_root` in settings). |
| **`ollama_managed_port`** | Optional note or port string for local Ollama routing. |
| **`project_playbook_json`** | Optional structured blob for extra rules (keep small). |

**Cursor / external agents:** use the **`tools/ledger-mcp`** stdio MCP server (see [`tools/ledger-mcp/README.md`](tools/ledger-mcp/README.md)). Set one of:

- **`NEON_LEDGER_DB`** — absolute path to `ledger.db` (same file Neon uses when running).
- **`NEON_REPO_ROOT`** — repository root; MCP defaults to `<NEON_REPO_ROOT>/.neon/ledger.db` if that file exists.

Optional writes from MCP: set **`NEON_LEDGER_MCP_ALLOW_WRITE=1`** before starting the server to enable `ledger_set_metadata` (otherwise read-only).

### 🔌 Local Neural Operator (Offline LLM, Cursor-Class Loop)
has been 
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
| **`HyperVManager`** | Hyper-V lifecycle via PowerShell (`src/core/hyperv_manager.cpp`); **`ToolRegistry`** exposes **`hyperv_*`** tools used by the MDI Hyper‑V Lab and by agents. |
| **Pipeline telemetry** | **`neon::pipeline_telemetry_snapshot()`** / **`pipeline_telemetry_reset()`** (`include/ai/swarm_pipeline_telemetry.hpp`): cumulative counters for Crucible inner loops, peer gate, Sentinel, shadow verify, disk commits, and swarm classroom PeerReview. |

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

**Cluster fabric and remote inference**

- Multi-GPU and multi-host **Ollama fabric**, Linux rack sidecars, and optional **vLLM / OpenAI-compatible** backends are documented in [docs/NEURAL_CLUSTER_FABRIC.md](docs/NEURAL_CLUSTER_FABRIC.md) (`SOVEREIGN_OLLAMA_CLUSTER_HOSTS`, `SOVEREIGN_INFERENCE_ENDPOINTS`, rack SSH, fleet routing).

**Parallelism vs. resident weights**

- Overlapping calls are bounded by the gateway governor (**`m_max_concurrency`**, default **2** in `gateway.hpp`). That limits simultaneous **requests**, not “two full 30B copies”—combined footprint still follows provisioner + hot-swap + **`OLLAMA_VRAM_LIMIT`**.

---

## 🧪 Systems Laboratory & SpiceViewport
Neon Sovereign has two virtualization lanes:

### 🕹️ SPICE (Retro / exotic virtual targets)
The **SpiceViewport** is a live window into **SPICE-backed guests** (typically QEMU). This lane is aimed at **retro systems and exotic OS targets** where Hyper-V is not applicable (or not desired).

- **Active HID testing**: agents send synthetic clicks/keystrokes into the guest to validate UI flows.
- **Legacy / exotic OS validation**: QEMU-bootable operating systems (Solaris/IRIX/…).

### 🧫 Hyper‑V Lab (Modern Windows/Linux host debugging & testing)
For modern workstation-grade isolation on **Windows hosts**, Neon includes a **Hyper‑V Systems Laboratory** (MDI window **ID 12: “HYPER‑V LAB”**).

- **Implementation**: **`HyperVManager`** wraps Hyper‑V via **PowerShell** (encode/exec path in `hyperv_manager.cpp`) with a configurable storage root for VHDX placement guidance.
- **Primary intent**: fast, local, deterministic VM lifecycle for debugging/testing on **Windows and Linux hosts** (future: deeper capture; current: external viewer).
- **MVP display**: launches **`vmconnect.exe`** / **Virtual Machine Connection** for the selected VM — the same “connect to the VM” story Microsoft documents for Hyper‑V Manager (**Connect** opens an external console window; there is no supported way here to paint the guest framebuffer inside Neon’s MDI).
- **Checkpoint gauntlet**: create/restore **Standard** checkpoints for destructive agent testing.
- **VM selection**: pick a VM from the **status bar “VM” selector** or from the Hyper‑V pane’s **List VMs** view; the choice is persisted in settings (**`hyperv_vm_name`**).
- **Persisted settings** (UI JSON via **`ConfigManager`**): **`hyperv_enabled`**, **`hyperv_vm_name`**, **`hyperv_switch_name`**, **`hyperv_dev_vhdx_url`**, **`hyperv_dev_vhdx_path`**, **`hyperv_startup_ram_mb`**, **`hyperv_cpu_count`**, **`hyperv_checkpoint_name`**.
- **Agent / UI tools** (same **`ToolRegistry`** surface): **`hyperv_probe`**, **`hyperv_list_vms`**, **`hyperv_status`**, **`hyperv_provision`**, **`hyperv_start`**, **`hyperv_stop`**, **`hyperv_checkpoint`**, **`hyperv_restore_checkpoint`**, **`hyperv_open_viewer`**, **`hyperv_create_vm`** (new Gen2 VM from an **existing** `.vhdx` on disk), **`hyperv_delete_vm`** (remove a VM by name). Slint callbacks mirror the lab actions for the pane and status line feedback.
- **Windows guest media**: Obtain official **evaluation/dev VHDX or ISO** through Microsoft’s channels (browser acceptance), place or download into storage, then point **`hyperv_dev_vhdx_path`** / **`hyperv_dev_vhdx_url`** or pass **`vhdx_path`** into **`hyperv_create_vm`**. Neon automates Hyper‑V; **you** comply with Microsoft licensing for the SKU you install.
- **Official download pages (same destinations as the Hyper‑V Lab buttons):**
  - [Windows 11 Enterprise Evaluation (Microsoft Eval Center)](https://www.microsoft.com/en-us/evalcenter/evaluate-windows-11-enterprise)
  - [Windows development environments / VM downloads](https://developer.microsoft.com/en-us/windows/downloads/virtual-machines/)
  - [Create a virtual machine in Hyper‑V (Learn quickstart)](https://learn.microsoft.com/en-us/virtualization/hyper-v-on-windows/quick-start/quick-create-virtual-machine)

**SPICE vs Hyper‑V (which tool?):** **`inject_spice_input`** drives **QEMU/SPICE** guests (retro/exotic lane). **`hyperv_*`** tools drive **Hyper‑V** on the Windows host (`vmconnect` for display). Do not mix—pick the backend that matches your VM.

**Permissions note**: Hyper‑V cmdlets require membership in **Hyper‑V Administrators** or **Administrators**. On Windows, the first time you use a Hyper‑V Lab button without either, Neon offers to **restart elevated** (same command line). You can also add your account to Hyper‑V Administrators and sign out/in instead of running the whole IDE as Administrator.

#### Hyper‑V sandbox guest execution (agents / swarm)

VMConnect is **visual**. To run builds, tests, and installers **inside** the same Windows 11 VM the operator uses, Neon adds a **guest execution plane** over the network (OpenSSH and optional WinRM)—aligned with how enterprises automate Hyper‑V guests (there is no SPICE-style framebuffer automation API from the host).

- **Concept**: Keep **`hyperv_vm_name`** as the logical VM the UI and **`hyperv_*`** tools refer to; set **`sandbox_host`** to that guest’s **hostname or IP** (DHCP reservation or static IP on **Default Switch** / your vSwitch). Agents then use **`sandbox_ssh_exec`**, **`sandbox_scp_push`**, **`sandbox_probe`**, and optionally **`sandbox_winrm_exec`** (Windows host only). **`run_terminal_command`** stays on the **Neon host**—do not confuse host vs guest.
- **Settings** (`settings.json` via **`ConfigManager`**): **`sandbox_enabled`**, **`sandbox_host`**, **`sandbox_ssh_port`** (default 22), **`sandbox_ssh_user`**, **`sandbox_ssh_identity_file`** (OpenSSH private key path; empty uses default agent behavior), **`sandbox_ssh_timeout_sec`**, **`sandbox_ssh_strict_host_key`** (e.g. `accept-new`). Optional WinRM: **`sandbox_winrm_enabled`**, **`sandbox_winrm_user`**, **`sandbox_winrm_password_file`** (UTF‑8 one-line password file—prefer SSH keys), **`sandbox_winrm_use_ssl`**, **`sandbox_winrm_port`** (5985 HTTP / 5986 HTTPS typically).
- **Bootstrap (golden path)**: In the guest, install **OpenSSH Server** (Windows Optional Feature), start **`sshd`**, allow **`sandbox_ssh_user`** key-based auth; optionally enable **WinRM** for PowerShell-heavy automation. Use **`sandbox_probe`** (`try_ssh`) to verify TCP + SSH before long jobs. Wrap destructive suites with **`hyperv_checkpoint`** / **`hyperv_restore_checkpoint`**.
- **WSL inside the guest**: From agents, run `wsl.exe -e bash -lc "..."` via **`sandbox_ssh_exec`** on the guest—no separate Hyper‑V API.

##### Windows Sandbox (built‑in ephemeral desktop)

**Windows Sandbox** (Windows Pro/Enterprise; optional Windows feature) is a **throwaway** desktop: closing the Sandbox window **discards all guest disk changes**. It is hypervisor‑isolated but **not** managed by Neon’s **`hyperv_*`** PowerShell path—think “quick sterile Windows,” not the same as your persistent **`hyperv_vm_name`** VM.

- **When to use it**: Short, repeatable automation runs where losing installed SDKs after close is OK, or where you reinstall/script tooling each session. For multi‑day builds with heavy toolchains, prefer a **persistent Hyper‑V VM** + **`hyperv_checkpoint`**.
- **Same agent tools**: Neon does not need a separate API—once the Sandbox has **networking** and **OpenSSH Server** (or WinRM), point **`sandbox_host`** at the Sandbox guest IP and use **`sandbox_ssh_exec`** / **`sandbox_probe`** like any other guest. **`run_terminal_command`** remains **host‑side**.
- **`.wsb` config**: Enable **`<Networking>Enable</Networking>`**, use **`<MappedFolders>`** so artifacts survive on the **host** path (guest VM disk still resets). The repo sample **[examples/neon-sandbox.wsb.sample](examples/neon-sandbox.wsb.sample)** turns on **memory**, **clipboard**, a **read/write workspace**, **read-only `C:\tools`**, **read/write `C:\artifacts`**, and a default **`<LogonCommand>`** that installs OpenSSH Server, starts **`sshd`**, and opens **TCP/22** (first launch can be slow). Copy it to a `.wsb` file, replace the **`REPLACE_WITH_*`** host paths, remove optional **`<MappedFolder>`** blocks you do not need, then launch with **`WindowsSandbox.exe`** or double‑click the `.wsb`.
- **`sandbox_host`**: Sandbox DHCP/internal addressing can change between sessions. Typical workflow: open Sandbox, run **`ipconfig`** inside it, set **`sandbox_host`** in **`settings.json`** for that session, or automate discovery out of band.
- **Checkpoints**: **`hyperv_checkpoint`** applies to **Hyper‑V VMs** you manage with **`hyperv_*`**—it does **not** preserve Windows Sandbox guest state after you close the Sandbox window.

### 🔧 Other lab hooks (non-virtualization)
- **ADB Forge**: autonomously compiles, deploys, and debugs Android applications via NDK/ADB.
- **Binary Lab**: bridges Ghidra Headless into the swarm for silicon-level verification of instruction scheduling and memory layout.

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

**VRAM tier hints (mid-2026 open weights, operator overrides via env):**

| VRAM (dedicated) | Logic / Architect (`SOVEREIGN_LOGIC_MODEL`) | Speed / micro-edits (`SOVEREIGN_SPEED_MODEL`) |
| :--- | :--- | :--- |
| **&lt; 12 GB** | `gemma4:e4b-it-q4_K_M` or `qwen3:8b` (provisioner default) | `qwen2.5-coder:1.5b` or `qwen3:8b` |
| **12–20 GB** | `qwen3.6:27b-q4_K_M` or `gemma4:26b-a4b` MoE | `qwen2.5-coder:7b-q5_k_m` |
| **≥ 20 GB** | `qwen3.6:27b-q4_K_M` (Architect DAG, deep planning) | `qwen2.5-coder:7b-q5_k_m` or `gemma4:e4b-it-q4_K_M` for bracket/LSP repairs |

Use **`SovereignProvisioner`** + **`SOVEREIGN_LOGIC_MODEL` / `SOVEREIGN_SPEED_MODEL`**—do not hardcode tags in prompts. Reasoning-heavy Architect work benefits from larger Qwen 3.x / DeepSeek-R1–class tags when VRAM allows; Speed tier should stay a **different family** (Qwen coder) for peer/Sentinel and inner ReAct repairs.

**Gateway concurrency** (**`max_concurrent_agents`**, default **2**) is a separate knob from VRAM sizing—it limits overlapping inference workers but does not replace tier selection; tune it in settings when your GPU keeps up or struggles.

---

## 🧪 Headless smoke tests & verification pipeline

Smoke tests exercise the full **Software House** path (Architect DAG → parallel Developers → **Crucible** transactional commits) without the GUI. Archives land under **`<repo-root>/smoke-test/<id>/`** (override parent with `SOVEREIGN_REPO_ROOT`). Each run writes **`smoke_test_swarm.log`**, **`smoke_trace.txt`**, **`smoke_debug.ndjson`** (structured NDJSON: Architect LLM output + DAG node registration + blackboard + Crucible rounds), **`pipeline_telemetry.json`** (final composed-cycle counters), **`smoke_manifest.json`**, and generated sources.

**Staff Mail in smoke:** Headless smoke exits before the Slint loop runs, so in-app Staff Mail toasts are not shown during CI—but every **`staff_mail_post`** call (and CEO/CPO and CEO/CTO executive briefing emails from **`mandate_meetings`**) is appended synchronously to **`staff_mail.jsonl`** in the same archive folder (NDJSON, `"format":"neon_staff_mail_mirror_v1"`). Review that file to see design questions and build-status mail the swarm would have sent the operator. The swarm mandate also instructs agents to use **`staff_mail_post`** for design checkpoints when they need you in the loop. Agents do **not** block waiting for mail: they proceed with stated assumptions when there is no reply (e.g. CI).

**Staff Mail vs operator steering (interactive):** Replying in **Staff Mail** enqueues structured JSON on the blackboard ( **`kind`: `staff_mail_reply`** ) consumed by **`drain_operator_steering_block`** on the next swarm task—**forward-only** guidance for work still running. Pending steering is saved under app storage as **`operator_steering_pending.jsonl`** on exit and reloaded on startup so late replies are not lost if you restart the IDE.

**Vision:** Tool **`vision_audit`** captures the **primary monitor** to a temporary **BMP** when the vision callback is wired (interactive desktop sessions). Use it for UI regressions together with **`staff_mail_post`**.

### Polyglot / non-C++ workflows
Tier‑1 remains native **C/C++** / **Rust** in-repo; for **Python**, **Node**, **Go**, etc., agents typically use **`execute_wsl_command`** (Linux toolchain in WSL) or run interpreters inside a **Hyper‑V** or **SPICE** guest when you need OS isolation. Expand per-project scripts and tool prompts rather than expecting one universal runner.

### Invocation

```powershell
.\Neon-Sovereign.exe smoke-test "Your engineering brief here"
.\Neon-Sovereign.exe smoke-test brief "Your engineering brief here"
.\Neon-Sovereign.exe smoke-test full "Your engineering brief here"
.\Neon-Sovereign.exe smoke-test --brief-file .\path\to\brief.txt
```

The `brief` / `full` tokens only select the argv shape; they share the same pipeline and validation.

Use **`--brief-file`** when the brief contains characters that are awkward in PowerShell (for example `>` in thresholds) or when a script generates the text. Prefer saving the file as **UTF-8** (with or without BOM). The harness also normalizes **UTF-16 LE/BE** (with BOM) and **UTF-16 LE without BOM** for typical ASCII-heavy briefs so `user_brief` in **`smoke_manifest.json`** stays valid UTF-8.

The brief must be **substantive**: rejected if fewer than **3 words** or fewer than **12** non-whitespace characters (prevents meaningless “success” on noise).

**Headless defaults (integrity profile):** smoke-test sets **`SOVEREIGN_LOGIC_MODEL`** / **`SOVEREIGN_SPEED_MODEL`** from **`SovereignProvisioner`** when unset, leaves **`SOVEREIGN_SDK_SINGLE_SHOT` unset** so Developers use the full **`planReact`** tool loop (multi-pass line edits), and leaves the Crucible **peer gate on** (same default as the GUI). After the DAG completes, the harness runs a **project integration gate** (static preflight, **`cmake` configure/link**, optional **`scripts/verify_*.sh`**) before **SUCCESS**. Set **`SOVEREIGN_SMOKE_FAST=1`** for the velocity profile (peer gate off, no integration link, lighter shadow checks, and **`SOVEREIGN_SDK_SINGLE_SHOT=1`** when not already set). Set **`SOVEREIGN_SDK_SINGLE_SHOT=1`** explicitly if you want single-shot throughput without fast mode. **`smoke-test full`** sets **`SOVEREIGN_SMOKE_FULL_PIPELINE=1`** (alias for the integrity peer preflight). See **`smoke_trace.txt`**: **`smoke_integrity_profile`**, **`integration_gate_enabled`**, **`SOVEREIGN_PEER_GATE=`**, and **`resolved_crucible_peer_gate`**.

**CI smoke profile:** Example env and a wrapper script live in **[`scripts/smoke-ci.env.example`](scripts/smoke-ci.env.example)** and **[`scripts/run-smoke-ci.ps1`](scripts/run-smoke-ci.ps1)**. Use **`-Fast`** for **`SOVEREIGN_SMOKE_FAST=1`** when you need the legacy fast path on tight VRAM tiers.

**Exit codes**:

| Code | Meaning |
| :--- | :--- |
| **`0`** | Final verdict **SUCCESS** (see below). |
| **`1`** | Smoke finished but verdict **FAILURE** (timeout, stalled/incomplete tasks, missing or **empty** output files). |
| **`2`** | CLI usage error or brief rejected (too short). |

**SUCCESS** (recomputed at shutdown from the blackboard): seed task **Completed** or **Stalled**, **no** active swarm work, **no** non-seed task stuck outside **Completed**, every **Completed** non-seed task has an **existing, non-empty** file under the smoke workspace (`target_file`), **at least one** non-seed task completed, **integration gate pass** when enabled (see **`integration_result.json`** / **`integration_build.log`**), and **at least one peer-gate run** when the peer gate is enabled.

If the DAG is still active when the smoke timeout fires, the archive logs **`Reason: TIMEOUT`** and **`FAILURE`**.

### Crucible: peer review, auto-repair, then Sentinel

Each **`submit_patch`** (Developer → Crucible) runs **inner repair rounds** before the blackboard consumes a **swarm retry**. Order per attempt:

1. **Bracket preflight** (fast SIMD balance). On failure → **Speed-tier** LLM structural fix.
2. **Peer gate** (optional): another model pass asks for **`PEER_APPROVED`** vs **`PEER_ISSUES`** + bullets; issues feed a **Logic-tier** rewrite *before* Sentinel.
3. **Sentinel** (`AdversarialEngine::run_critic`): Red Team hypothesis + Speed audit. **Only the `[AUDIT]:` section** is interpreted for approve/reject (the hypothesis line alone cannot false-trigger rejection).
4. **Shadow verification** (bracket gate; in the integrity profile, LSP diagnostics and optional single-TU compile before disk commit). On failure → Logic-tier fix from the error text.

Only after **all inner rounds** fail does Crucible call **`commit_task(false)`** with **`crucible_auto_repair_exhausted`**. That burns **one** swarm-level retry, not one per gate.

### Pipeline telemetry (composed-cycle metrics)

Runtime counters aggregate **Crucible** inner-loop activity (peer gate, Sentinel audits, shadow verification outcomes, successful disk commits) and **swarm classroom** PeerReview approve/reject totals. They are thread-safe globals exposed as **`neon::PipelineTelemetrySnapshot`** via **`neon::pipeline_telemetry_snapshot()`**. Field names match the struct in **`include/ai/swarm_pipeline_telemetry.hpp`** (inner repair rounds, peer gate runs/passes/revision cycles, Sentinel audits/acceptances, shadow verify failures/successes, successful commits, swarm PeerReview invocations/approvals/rejections).

**Smoke-test harness behavior**

- **`pipeline_telemetry_reset()`** runs at the start of each headless smoke run so archives are comparable run-to-run.
- **`smoke_test_swarm.log`** receives periodic **`[PIPELINE_METRICS]`** lines: JSON objects with **`"format": "neon_pipeline_metrics_v1"`** (same payload mirrored at **`LOG_INFO`**).
- **`smoke_trace.txt`** appends a compact **`metrics={...}`** subset on the rolling audit lines for quick diffing.
- **`smoke_debug.ndjson`** receives high-signal events when **`SOVEREIGN_SMOKE_ARCHIVE`** is set (always during **`smoke-test`**): raw Architect response (truncation-capped blob), parsed DAG shape, per-node **`submit_task`** outcomes, duplicate-file rejections, Crucible inner rounds / peer / Sentinel / shadow / disk persist / commit. **`dag_malform.ndjson`** records Architect DAG parse/shape failures only (grep-friendly). Optional **`SOVEREIGN_SMOKE_TICK_LOG=1`** adds **`smoke_poll_tick`** once per simulated second (verbose).
- **`[SMOKE_VERDICT_PREVIEW]`** in **`smoke_test_swarm.log`** (every **`SOVEREIGN_SMOKE_AUDIT_INTERVAL_SEC`**, default **5**) shows **`non_seed_completed`** before shutdown so an empty Architect DAG is obvious without reading NDJSON.
- If **`smoke_test_swarm.log`** is **0 bytes** but **`smoke_trace.txt`** exists, the run was **interrupted** (reboot, kill, crash) during **`run_executive_meetings()`** *before* the first swarm poll — the log is now **opened with an immediate header + flush**; set **`SOVEREIGN_SKIP_EXEC_MEETINGS=1`** to skip that LLM phase in CI and avoid long pre-swarm windows.
- **VRAM / Ollama wedging:** the Sentinel **barrier** closes neural accept and waits for idle before **`evict_from_vram` / `lock_in_vram`**. Headless smoke defaults **`SOVEREIGN_VRAM_SWAP_NEURAL_IDLE_SEC=600`** so a hung **`/api/chat`** worker cannot block the swap forever; **`SOVEREIGN_SMOKE_SKIP_VRAM_BARRIER=1`** skips the evict+lock entirely (faster, less VRAM discipline). Hot-swap **`/api/generate`** calls now use **WinHTTP receive timeouts** so unload/lock cannot hang indefinitely on TCP.
- **Single-model smoke residency (24 GB class):** integrity CI via **`scripts/run-smoke-ci.ps1`** sets **`SOVEREIGN_DUAL_RESIDENCY=0`** so only **Logic** stays in VRAM at startup; **Speed** loads on demand via **`prepare_vram_for_model`** + swarm barrier. Opt in to dual pins with **`SOVEREIGN_DUAL_RESIDENCY=1`** (live probe must succeed before **`SOVEREIGN_SMOKE_SKIP_VRAM_BARRIER=1`**). **`SOVEREIGN_VRAM_PIN_LOGIC=1`** (default on in smoke) swaps back to Logic after Speed-tier calls. **`SOVEREIGN_DUAL_RESIDENCY_HEADROOM_GIB`** (default **4** on ≤28 GB cards) tightens dual-feasibility math in **`neural_vram_budget.cpp`**.
- **`pipeline_telemetry.json`** is overwritten on each **`SOVEREIGN_SMOKE_AUDIT_INTERVAL_SEC`** audit with **`"format": "neon_pipeline_telemetry_partial_v1"`** (and on swarm-loop exception before exit) so killed or partial runs keep counters. At **`=== SIMULATION TERMINAL ===`**, the harness overwrites it again with **`"format": "neon_pipeline_telemetry_final_v1"`** and logs the path.
- **Cross-run memory:** high-signal smoke failures and selected **`smoke_debug`** events are appended to **`ledger.db`** **`KnowledgeBase`** (problem prefix **`[smoke]`**). Isolated runs under **`smoke-test/<id>/`** (**`SOVEREIGN_SMOKE_ARCHIVE`**) **do not** inject broad prior-run BM25 gossip into the swarm mandate unless you opt in with **`SOVEREIGN_SMOKE_CROSS_RUN_MEMORY=1`**. When enabled, **`main.cpp`** prepends a capped **`CROSS_RUN_SMOKE_MEMORY`** block from **`search_historical_fixes("smoke")`** (2048 chars in smoke archive mode).

### Vault memory tiers (ledger.db playbook)

Neon stores durable operator memory in **`ledger.db`**: **`ProjectMetadata`** (short keys) and **`KnowledgeBase`** (longer lessons). Swarm/SDK recall uses tiered injection — not a separate MCP product.

| Tier | Where | What |
| :--- | :--- | :--- |
| **L0** | **`AIGateway`** (`append_vault_memory_stack`) | Compact playbook keys: **`windows_build_command`**, **`smoke_command`**, **`build_folder`**, **`storage_root_hint`**, **`script_mappings`**. |
| **L1** | Gateway + capped preamble | Essential story: top **`KnowledgeBase`** rows via FTS + semantic **RRF** (`knowledge_search_rrf` in **`vault_memory.cpp`**). |
| **L2** | **`SwarmController`** Developer/Forge prompts | Room-scoped episodic drawers: tags **`room:<repo-relative-path>`**, facets **`facet:read_only_loop`**, **`facet:edit_lines_eof`**, **`vault_run:<smoke-id>`**. Block header **`=== VAULT L2 RECALL ===`**. |
| **L3** | ReAct tool **`ledger_recall`** | Deep query: optional **`room`** path merges **`search_vault_room_recall`** + RRF over **`KnowledgeBase`**. |

**Agent layout & observe–act tools**

- Checked-in role/layout spec: **`docs/sovereign/agent-layout.md`** (injected into Architect/Developer prompts; override with **`SOVEREIGN_AGENT_LAYOUT_PATH`**).
- **`dag_peek`**: JSON dependency view for a task (`blocked_by` status, ages, satisfied flags).
- **`pull_skill`**: load **`skills/<name>/SKILL.md`** (post-smoke synthesis writes under the smoke archive).
- **`correction_memory.md`**: human export at simulation terminal from **`KnowledgeBase`** + **`CrucibleGateIncidents`**.
- Env (smoke defaults via **`sovereign_apply_smoke_run_defaults`**): **`SOVEREIGN_HERESY_PROMOTE_AFTER`**, **`SOVEREIGN_REPAIR_REQUIRE_RECALL`**, **`SOVEREIGN_WITNESS_HEADER_STALL_SEC`**, **`SOVEREIGN_SMOKE_SOP_SYNTHESIS`**, **`SOVEREIGN_SDK_OTA_LABELS`**.

**Vault tag conventions** (semicolon-separated in **`KnowledgeBase.tags`**):

- **`smoke`** — episodic smoke incident (BM25 prefix **`[smoke]`** in problem text).
- **`room:src/Foo.cpp`** — file-scoped recall room (normalized forward slashes).
- **`facet:<name>`** — failure class for grep/filter (e.g. **`read_only_loop`**, **`thread_safety`**, **`chrono_modern`**, **`resource_leak`**).
- **`vault_run:190`** — smoke run id when **`SOVEREIGN_SMOKE_ARCHIVE`** is set.

**Environment knobs**

| Variable | Default | Effect |
| :--- | :--- | :--- |
| **`SOVEREIGN_SMOKE_CROSS_RUN_MEMORY`** | off when archive set | Inject **`CROSS_RUN_SMOKE_MEMORY`** into swarm mandate from prior smoke rows. |
| **`SOVEREIGN_SEMANTIC_MEMORY`** | on | Ollama/hash embeddings in **`KnowledgeEmbeddings`**; **`SOVEREIGN_SEMANTIC_MEMORY=0`** disables semantic leg of RRF. |
| **`SOVEREIGN_VAULT_RRF`** | follows semantic | **`SOVEREIGN_VAULT_RRF=0`** uses first BM25 list only (no reciprocal-rank fusion). |
| **`SOVEREIGN_VAULT_RRF_K`** | **60** | RRF constant **k** (clamped 1–200). |
| **`SOVEREIGN_VAULT_RRF_W_FTS`** | **1.0** | FTS leg weight in weighted RRF (paper Stage 8). |
| **`SOVEREIGN_VAULT_RRF_W_VEC`** | **1.0** | Vector leg weight in weighted RRF. |
| **`SOVEREIGN_VAULT_NOVELTY_GATE`** | on | Gzip novelty gate for **`smoke`/`gossip`/`crucible`** tags (paper Stage 1). |
| **`SOVEREIGN_VAULT_NOVELTY_MIN`** | **0.12** | Minimum **n_t** to insert episodic rows. |
| **`SOVEREIGN_VAULT_TEMPORAL_BOOST`** | **1.3** | RRF multiplier for **`vault_run:<current>`** or previous run (paper Stage 9). |
| **`SOVEREIGN_SQLITE_VEC_PATH`** | unset | Path to **sqlite-vec** extension DLL/SO; enables **`KnowledgeVec`** KNN SQL. |
| **`SOVEREIGN_SQLITE_VEC`** | follows path | Set **0** to force C++ cosine fallback. |

**Retrieval pipeline (True Memory / arXiv:2605.04897):** ingest novelty gate → FTS5 BM25 + dense vectors → **weighted RRF** `w/(k+rank)` → temporal **`vault_run`** boost → L0–L3 injection. No Python cross-encoders.

**sqlite-vec:** optional. When **`SOVEREIGN_SQLITE_VEC_PATH`** loads **vec0**, dense search uses SQL `MATCH … AND k = ?` on **`KnowledgeVec`**; otherwise full-table cosine on **`KnowledgeEmbeddings`** remains the fallback.

**MCP ledger tools** (optional): **`tools/ledger-mcp/README.md`** — same **`ledger.db`**; agents can **`ledger_get_metadata`** / **`ledger_search_knowledge`** when the MCP server is configured.

Interactive GUI sessions do not reset counters automatically; call **`pipeline_telemetry_reset()`** when you need a clean baseline (or rely on smoke for isolated measurement).

### Swarm throughput tuning (cheat sheet)

These knobs affect how aggressively the swarm **polls for work**, how many **heavy** Architect/Developer tasks can be **checked out** at once, and how many **concurrent neural sessions** the gateway allows. Defaults favor stability on a single GPU; raise them when you have headroom.

| Goal | Knob | Notes |
| :--- | :--- | :--- |
| Faster dequeue when the blackboard still has open tasks | **`SOVEREIGN_SWARM_IDLE_POLL_CAP_MS`** | Clamped **2–80** ms cap on idle backoff while **`has_active_work()`** is true (`sovereign_env.cpp`). Defaults **12** (integrity) / **6** (fast smoke). Lower = hungrier polling, slightly more CPU wakeups. |
| More Architect/Developer tasks **Claimed** concurrently | **`SOVEREIGN_HEAVY_NEURAL_LANE_CAP`** | Default **2** (`blackboard.cpp` / `checkout_task`). Increase only if VRAM and Ollama can sustain more parallel codegen. |
| More concurrent **Ollama / SDK inference slots** | Startup + cluster | After **`configure_ollama_fabric`**, **`main.cpp`** sets **`AIGateway::set_max_concurrency`** to at least **`max(2, fabric replicas, cluster.swarm.ollama_num_parallel)`** (capped at 32). **`apply_neural_cluster_ollama_env`** also sets **`OLLAMA_NUM_PARALLEL`** from the cluster plan (`neural_cluster_topology.cpp`). |
| Windows C++ shadow compile without a Developer shell | **`SOVEREIGN_VCVARS_BAT`**, **`SOVEREIGN_SHADOW_CPP_TOOLCHAIN`** | Point **`SOVEREIGN_VCVARS_BAT`** at **`vcvars64.bat`**, or set **`wsl`** / **`msvc`** / **`auto`** for toolchain selection (`tool_registry.cpp`). |
| Velocity over single-TU compile | **`SOVEREIGN_SHADOW_COMPILE=0`** | Disables Crucible compile shadow; LSP may still run in integrity profile. |
| Disable Crucible **batch** peer/Sentinel staging | **`SOVEREIGN_CRUCIBLE_BATCH_AUDIT=0`** | When unset, batch audit is **on** in integrity mode (`sovereign_env.cpp`). |

### Stopping Neon Sovereign and rebuilding (Windows)

Canonical build from repo root: **`.\build.bat`** (loads MSVC via **`vcvars64.bat`**, fixed CMake tree, Rust/Corrosion; see repository **`build.bat`**). If link fails with **`LNK1104: cannot open … Neon-Sovereign.exe`**, the binary is almost always still **running or locked**.

1. Exit the IDE normally, or from **PowerShell**:

```powershell
Get-Process -Name "Neon-Sovereign" -ErrorAction SilentlyContinue | Stop-Process -Force
```

2. If you run a **managed** Ollama for Neon and it holds model locks, you can stop it the same way (adjust if you rely on system Ollama on port **11434**):

```powershell
Get-Process -Name "ollama" -ErrorAction SilentlyContinue | Stop-Process -Force
```

3. Rebuild from **`neon-vs-src`**:

```powershell
Set-Location "C:\path\to\neon-vs-src"
.\build.bat
```

Then launch the next **`smoke-test`** or GUI session. Closing stragglers before **`build.bat`** avoids wedged links and stale in-memory state when iterating toward reliable app-generation runs.

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
| **`SOVEREIGN_PEER_GATE=`** | Raw env; empty when unset. Integrity headless smoke leaves peer gate **on** (same as GUI). **`SOVEREIGN_SMOKE_FAST=1`** forces **`0`**. |
| **`SOVEREIGN_SMOKE_FULL_PIPELINE=`** | Raw env; empty when unset. **`smoke-test full`** sets **`1`** at CLI parse (integrity peer preflight alias). |
| **`smoke_integrity_profile`** | **`integrity`** or **`fast`**: resolved smoke profile (`sovereign_env.cpp`). |
| **`integration_gate_enabled`** | **`1`** or **`0`**: whether DAG-complete configure/link runs before terminal **SUCCESS**. |
| **`resolved_crucible_peer_gate`** | **`on`** or **`off`**: whether Crucible runs the Speed-tier peer preflight (same rules as runtime parsing of **`SOVEREIGN_PEER_GATE`**). |
| **`resolved_logic_model`** | Logic-tier tag passed to **`set_model`**: **`getenv("SOVEREIGN_LOGIC_MODEL")`** if set; otherwise **`smoke-test`** sets it from **`SovereignProvisioner::acquire_neural_assets(vram)`** (VRAM-tiered Gemma Architect tags). |
| **`resolved_speed_model`** | Speed / Sentinel tag: **`getenv("SOVEREIGN_SPEED_MODEL")`** if set; otherwise smoke sets it from the same provisioner selection (VRAM-tiered Qwen tags). If both tiers would resolve to **Gemma-4** Ollama tags, **`enforce_model_pairing`** rewrites Sentinel to **`qwen2.5-coder:7b-q5_k_m`** before **`set_sentinel_model`**. |
| **`ollama_managed_port`** | From **`ConfigManager`** / settings JSON (default **11435** when managed Ollama is used—not an env var in the trace). |

**Embedded commentary** (copied into the trace for reproducibility)

- **Neon hot-swap**: model evict/lock behavior is governor-gated; see **`startup.log`** for **`[GOVERNOR]`** / **`[SWARM]`** lines.
- **Developer path**: default SDK posture is **Reason+Act with real tool execution** (`read` / `write` / `execute`); not chat-only.
- **Throughput mode**: explains **`SOVEREIGN_SDK_SINGLE_SHOT=1`** → `planSingleShotCodegen` → **`AIGateway::prompt()`** / **`SOVEREIGN_PROMPT_TIMEOUT_SEC`** (CI/smoke velocity; not the architectural ceiling for interactive work).
- **Pipeline telemetry**: points operators at **`[PIPELINE_METRICS]`** polling lines and **`pipeline_telemetry.json`** for Crucible / PeerReview cycle counters.

**`SOVEREIGN_*` variables** (every name that appears in the trace narrative)

| Variable | Default when unset | Allowed range | Purpose |
| :--- | :--- | :--- | :--- |
| **`SOVEREIGN_LOGIC_MODEL`** | From **`config/neural.toml`** via **`ConfigManager`**; headless smoke sets from **`SovereignProvisioner`** when unset | Ollama tag string | Overrides persisted Logic-tier model on startup (`config_manager.cpp`). |
| **`SOVEREIGN_SPEED_MODEL`** | From **`config/neural.toml`**; headless smoke sets from provisioner when unset | Ollama tag string | Overrides Speed-tier / Sentinel routing model on startup. |
| **`SOVEREIGN_SDK_SINGLE_SHOT`** | off (`0` / unset) | `0` / `1` (any non-empty, non-`0` enables) | **`autonomous_agent_impl`**: one-shot codegen vs full **`planReact`**. Headless **`smoke-test`** leaves it unset (ReAct); **`SOVEREIGN_SMOKE_FAST=1`** (or **`scripts/run-smoke-ci.ps1 -Fast`**) sets **`1`** when unset. |
| **`SOVEREIGN_SDK_AUTO_VERIFY_AFTER_EDIT`** | **on** (unset) | `0` / `false` / `off` disables | After successful **`edit_lines`** / **`fuzzy_patch`** / **`replace_ast_node`** on implementation TUs, SDK auto-runs **`verify_translation_unit`** and blocks **FINISH** until compile checks pass (`autonomous_agent_impl.cpp`). |
| **`SOVEREIGN_REACT_MAX_STEPS`** | `24` | `4`–`128` | Max Reason+Act iterations when single-shot is off. |
| **`SOVEREIGN_REPO_ROOT`** | (derive from repo detection beside `startup.log`) | filesystem path | Parent directory for **`smoke-test/<id>/`** (`main.cpp`). |
| **`SOVEREIGN_SMOKE_TIMEOUT_SEC`** | `3600` | `300`–`14400` | Outer poll/wait budget for the smoke harness. |
| **`SOVEREIGN_ARCHITECT_ASK_TIMEOUT_SEC`** | `1800` | `120`–`7200` | Per-call timeout for Architect **`gateway->ask()`** while producing the JSON DAG (`swarm_controller.cpp`). |
| **`SOVEREIGN_PROMPT_TIMEOUT_SEC`** | `1800` | `30`–`7200` | Wall-clock cap for **`AIGateway::prompt()`** (SDK string **`chat`** → WinHTTP **`call_winhttp_messages`**). Prevents infinite **`cv.wait`** when Ollama streams slowly or stalls; single-shot smoke (**`SOVEREIGN_SDK_SINGLE_SHOT=1`**) uses this path (`gateway.cpp`). |
| **`SOVEREIGN_DEVELOPER_SDK_TIMEOUT_SEC`** | prompt **`+ 180`** | `60`–`7300` (clamped to **≥ prompt + 30**) | Outer bound for Developer **`blockingWait(sdk_worker->run(...))`**. Should exceed **`SOVEREIGN_PROMPT_TIMEOUT_SEC`** so the inner prompt timeout fires first; on outer timeout the task fails and the async SDK join is **detached** so the swarm thread does not block forever (`swarm_controller.cpp`). |
| **`SOVEREIGN_CRUCIBLE_AUTO_REPAIR_ROUNDS`** | `8` | `1`–`32` | Inner **`submit_patch`** repair rounds before a swarm retry (`crucible.cpp`). |
| **`SOVEREIGN_CRUCIBLE_BATCH_AUDIT`** | **on** in integrity (unset) | `0` / `false` / `off` / `no` disables | Batch peer/Sentinel path for staged patches (`sovereign_env.cpp`, `crucible.cpp`). Off in **`SOVEREIGN_SMOKE_FAST=1`**. |
| **`SOVEREIGN_SWARM_IDLE_POLL_CAP_MS`** | **12** (integrity) / **6** (fast smoke) | `2`–`80` | Max milliseconds between swarm idle polls while the blackboard still has open work (`sovereign_env.cpp`, `swarm_controller.cpp`). |
| **`SOVEREIGN_HEAVY_NEURAL_LANE_CAP`** | `2` | `1`–`8` | Max Architect/Developer tasks in **Claimed** / **InProgress** / **PeerReview** / **ShadowCompile** counted toward checkout (`blackboard.cpp`). |
| **`SOVEREIGN_PEER_GATE`** | **on** (unset) | `0` / `false` / `off` / `no` / numeric **0** disables; **`1` / `true` / `on` / `yes`** enables | Speed-tier peer review before Sentinel (`sovereign_env.cpp`, `crucible.cpp`). **`SOVEREIGN_SMOKE_FAST=1`** forces **`0`** in headless smoke. |
| **`SOVEREIGN_SMOKE_FAST`** | off (`0` / unset) | `1` / `true` / `on` / `yes` | Velocity smoke profile: disables peer gate, integration link, and heavy shadow compile (`sovereign_env.cpp`, `main.cpp`). |
| **`SOVEREIGN_INTEGRATION_GATE`** | **on** in integrity profile | `0` / `false` / `off` / `no` disables | DAG-complete **`cmake` configure/link** + optional verify scripts before smoke **SUCCESS** (`integration_gate.cpp`). Off when **`SOVEREIGN_SMOKE_FAST=1`**. |
| **`SOVEREIGN_SHADOW_LSP`** | **on** in integrity profile | `0` disables | Crucible LSP shadow diagnostics (`crucible.cpp`). |
| **`SOVEREIGN_SHADOW_COMPILE`** | **on** in integrity profile | `0` disables | Crucible single-TU compile check for `.cpp` files (`crucible.cpp`). |
| **`SOVEREIGN_SMOKE_FULL_PIPELINE`** | off (`0` / unset) | `1` / `true` / `on` / `yes` | Sets **`SOVEREIGN_SMOKE_FULL_PIPELINE=1`** at CLI parse; alias for integrity peer preflight. **`smoke-test full`** enables it. |
| **`SOVEREIGN_SMOKE_MEMORY_DB`** | (not implemented) | filesystem path | **Reserved:** future optional SQLite separate from global **`ledger.db`**. Today cross-run smoke memory uses **`ledger.db`** **`KnowledgeBase`** rows tagged **`[smoke]`** via **`ProjectLedger::record_smoke_incident`** / **`search_historical_fixes("smoke")`**. |

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
