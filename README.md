# Global University Analytics & Recommendation Engine

A high-performance, multi-module data analytics engine architected in C++ designed to index, search, sort, and manage complex international institutional performance indicators. The system streams real-world datasets, processes administrative control structures, tracks persistent database tracking logs, and optimizes runtime logic via specialized data arrangement paradigms.

The platform includes embedded algorithmic evaluation loops to profile real-time execution complexities, comparing latency curves under active hardware utilization.

---

## 🚀 Architectural & System Capabilities

### 1. Robust Core Module Implementations
* **Decoupled User & Admin Pipelines:** Isolates distinct operational profiles via modular encapsulation layer targets (`Admin.h` / `User.h`), safely segregating privilege sets and system view paths.
* **Dual-Way Communication Matrix:** Processes asynchronous client notes and feedback records tracking state responses over standalone file stream boundaries (`Feedback.h`).

### 2. Multi-Tier Search & High-Efficiency Sorting
* **Multi-Variable Tokenization Filters:** Evaluates multi-dimensional strings on large datasets enabling users to isolate key criteria like Academic Status, Staff Ratios, and Location Profiles.
* **Algorithmic Profiling Environments:** Integrates standalone variants of Selection Sort and Bubble Sort alongside Binary Search targets (`O(log n)`) and Linear Arrays to directly benchmark hardware performance factors.

### 3. File Serialization & State Integrity
* **Text Ledger Infrastructure:** Serializes continuous operational mutations natively using text registry file formats (`users.txt`, `admin.txt`, `feedback.txt`), preventing memory allocation leaks without adding complex relational dependencies.
* **Punctuation & Edge-Case Sanitizers:** Employs customized character delimiters ensuring fields wrapping inner commas read cleanly without skewing matrix alignment lines.

---

## 📊 Algorithmic Efficiency Latency Benchmarks

The diagnostic layers calculate core CPU processing durations to document comparative sorting and searching capabilities over 1,400+ entries:

### In-Memory Dataset Sorting
* **Selection Sort:** `~115.90 ms` (Saves CPU clock cycles by drastically reducing deep structural reference swappings).
* **Bubble Sort:** `~1189.39 ms` (Higher time-complexity curves due to repetitive element indexing passes).

### Query Retrieval Matrix Lookups
* **Binary Search (`O(log n)`):** `~0.048 ms` (Sub-millisecond middle-partitioning index lookups).
* **Linear Search (`O(n)`):** `~2.901 ms` (Standard linear continuous array tracking iteration latency).

---

## 🛠️ Compilation & Local Deployment

### Hardware Prerequisites
* GNU Compiler Collection (`g++`) or standard Apple LLVM Clang toolchain supporting the `C++11` standard framework or higher.

### Quick Setup & Build
1. Clone this solution module to your active workspace folder:
   ```bash
   git clone [https://github.com/YOUR_USERNAME/global-university-ranking-engine.git](https://github.com/YOUR_USERNAME/global-university-ranking-engine.git)

```

2. Step inside the repository workspace root:
```bash
cd global-university-ranking-engine

```


3. Compile all implementation blocks safely through G++:
```bash
g++ -std=c++11 *.cpp -o data_engine

```


4. Execute the production console executable target:
```bash
./data_engine
