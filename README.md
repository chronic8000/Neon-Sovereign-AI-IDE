# SMOKE TEST 290 ACTUALLY PRODUCED A WORKING EXE FILE!

## Available to download from this repository now - The first smoke-test to produce working code you can open in Visual Studio!

# Update #2 Smoke 293 got **SUCCESS** so I am now moving to port the smoke test in to the UI as the full pipeline.

**Here's the full, long, GitHub-ready README** for Neon Sovereign:

---

# Neon Sovereign

**The Autonomous Engineering Workstation**

> Define the outcome. Walk away. Return to working software.

**Neon Sovereign** is a high-performance, native **C++20 AI-powered IDE** engineered from first principles to function as a complete **autonomous software house**.

It is not a chat assistant.  
It is not a copilot plugin.  
It is not another Electron wrapper.

It is a **deterministic execution pipeline** that plans, coordinates, builds, verifies, repairs, and delivers real software with minimal human intervention.

---

## The Problem with Modern AI Coding Tools

Today's AI development tools suffer from deep architectural limitations:

| Issue                      | Current Tools                     | Neon Sovereign Approach |
|---------------------------|-----------------------------------|-------------------------|
| **Performance & Bloat**   | Electron / Web-based              | Native C++20 + Vulkan (120 FPS) |
| **Constant Supervision**  | Frequent user prompts & approvals | Fully autonomous DAG execution |
| **Context Amnesia**       | Short, stateless conversations    | Persistent SQLite Ledger + BM25 + Semantic Search |
| **Hallucinations**        | No grounded verification          | Compiler Shadow Buffers + Sentinel QA + Self-Repair Loops |
| **Blind Output**          | Cannot see the UI it creates      | Silicon Retina (VLM visual validation) |
| **Sequential Execution**  | One agent at a time               | Parallel Specialist Swarm |
| **Cloud Dependency**      | API quotas, privacy risks         | Fully offline / air-gapped capable |
| **Unreliable Delivery**   | Often fails to produce working code | Integration Gates + Crucible Repair System |

Neon Sovereign was built specifically to solve these systemic failures.

---

## Core Philosophy: The Software House Model

Neon Sovereign operates like a professional engineering organization:

### Execution Pipeline

1. **Demand Phase** — High-level brief from the user
2. **Executive Alignment** — CEO, CPO, and CTO agents define scope, constraints, and technical direction
3. **Architecture Phase** — Architect agent produces a formal **Task DAG** (Directed Acyclic Graph)
4. **Swarm Execution** — Parallel specialist agents (Developers, ForgeMaster, etc.) coordinate via gossip protocol
5. **Verification Gauntlet** — Multiple layers of automated checks
6. **Self-Repair Loops** — Automatic iteration on failures using compiler feedback and historical memory
7. **Delivery** — Verified artifacts, forensic logs, and visual validation

### Real Performance
**Smoke Test Example**:  
From brief to complete, compiling Win32 C++20 application → **4 minutes 43 seconds**

---

## Key Capabilities

- **Task DAG System** — Mathematically optimal dependency planning using Kahn’s Algorithm
- **Self-Repair Loops** — Persistent iteration until integration gates pass
- **Crucible System** — Multi-stage peer review, Sentinel audit, and shadow compilation
- **Silicon Retina** — Vision model validation of running application UIs
- **Persistent Memory Ledger** — SQLite with BM25 + semantic retrieval
- **Universal Target Support** — Native, Web, Mobile, Embedded, Legacy, and Virtualized systems
- **Local-First Design** — Runs entirely on your hardware with Ollama weights
- **Hyper-V + SPICE Labs** — Built-in safe testing environments

---

## Architecture Highlights

### DSCE – Deterministic Software Cognition Engine
The control plane is deliberately deterministic. LLMs are treated as powerful executors, not the source of truth.

- Sovereign Semantic Spine (Tree-sitter backed stable semantic graph)
- Contract Epochs + deterministic arbitration
- Causal Ledger for historical build incidents
- Resource Governor ("The Silicon Leash") for intelligent VRAM management

### Parallel Swarm
- Architect
- Specialist Developers
- ForgeMaster (build integration)
- Sentinel (QA & security)
- Silicon Retina (visual validation)
- Chaos Agent (fuzzing & stress testing)

### Labs
- **Hyper-V Laboratory** — Modern Windows/Linux guest testing
- **SPICE Viewport** — Retro and exotic OS targets
- **Binary Lab** — Ghidra integration for low-level analysis

---

## Current Status (Active Alpha)

**Proven Strengths**:
- Excellent native C++/Win32 delivery
- Strong autonomous execution and self-repair
- Fast smoke test cycles
- Clean, maintainable generated code

**Active Development Areas**:
- UI/UX refinement (MDI workspace)
- Expanded language and framework support
- Multi-GPU and cluster scaling
- Enterprise features (secrets management, audit trails, permissions)

---

## Quickstart

### Prerequisites
- Windows 11 (23H2 or newer)
- Visual Studio 2022 with Desktop C++ workload
- CMake 3.28+
- GPU with ≥ 8GB VRAM (strongly recommended)

### Build
```powershell
cmake -S . -B build/windows -G "Visual Studio 17 2022" -A x64
cmake --build build/windows --config Release
```

### Running a Smoke Test
```powershell
.\Neon-Sovereign.exe --headless "Create a minimal Win32 C++20 click counter app..."
```

---

## Neural Provisioning (Local Models)

Neon Sovereign is designed to run fully offline.

**Recommended Model Pairing**:
- **Logic / Architect Tier**: Gemma-4 or Qwen 3.x class (planning & code generation)
- **Speed / Sentinel Tier**: Qwen Coder family (different family from Logic tier)

Models are loaded via Ollama. VRAM tiering is handled automatically.

---

## Teaser & Vision

This is just the beginning.

Future versions will push toward:
- Multi-node GPU farm scaling
- Full software product lifecycle automation
- Advanced air-gapped enterprise deployments
- Even more sophisticated self-improvement capabilities

**Neon Sovereign** represents a new paradigm: AI that doesn't just help you code — it **builds software like a professional team**.

---

**Define the outcome.**

**Neon Sovereign handles the rest.**

---

**Business & Collaboration Inquiries**: chronic9000@gmail.com
