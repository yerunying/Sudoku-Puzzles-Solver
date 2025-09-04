# SAT-Based Diagonal Sudoku Solver

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)](https://github.com/your-username/your-repo-name)
[![Course](https://img.shields.io/badge/Course-课程设计-orange.svg)]()

一个基于 **DPLL 算法** 的高效 **SAT 求解器**，并将其应用于求解复杂的 **对角线数独** 谜题。本项目是华中科技大学《程序设计综合课程设计》的课程设计成果。

## ✨ 功能特性

-   **🧠 完备的 SAT 求解器**: 基于 DPLL 算法框架，能够解析并求解 CNF 格式的 SAT 算例文件。
-     **⚡ 性能优化**: 实现了基于变元出现频次的分支策略 (`strategy2`)，显著提升求解性能，并提供明确的优化率数据。
-     **🎯 对角线数独求解**: 将数独规则（包括两条对角线）完美转化为 SAT 问题，并利用内置求解器进行求解。
-     **🎮 数独生成**: 采用“挖洞法”从 20 个预置的完整合法格局中随机生成可玩的数独谜题。
-     **💻 简单的交互界面**: 提供控制台菜单，方便用户选择 SAT 求解或数独游戏模式。

## 📁 项目结构

SAT-Sudoku-Solver/
│
├── src/ # 源代码目录
│ ├── main.c # 主程序入口，用户交互菜单
│ ├── Global.h # 全局头文件（结构体、常量、函数声明）
│ ├── DPLLSolver.c # DPLL 算法核心实现与优化
│ ├── FileReader.c # CNF 文件解析与数据结构构建
│ └── Sudoku.c # 数独生成、CNF 转换与输出功能
│
├── docs/ # 文档目录
│ └── CS2305-U202315573叶润莹.pdf # 完整的课程设计报告
│
├── test/ # 测试用例目录（可存放 .cnf 文件）
│
├── README.md # 项目说明文档


## 🚀 快速开始

### 环境要求

-   **操作系统**: 任何支持 C 语言编译的环境（Windows / Linux / macOS）
-   **编译器**: 支持 C99 标准的编译器（如 `gcc`, `clang`）
-   **开发环境**: 本项目使用 `Dev-C++ 5.11` 开发测试

### 编译与运行

1.  **克隆仓库并进入目录**
    ```bash
    git clone https://github.com/your-username/your-repo-name.git
    cd your-repo-name
    ```

2.  **编译项目**
    ```bash
    gcc -o solver src/main.c src/DPLLSolver.c src/FileReader.c src/Sudoku.c -I src/
    ```

3.  **运行程序**
    ```bash
    # On Windows
    solver.exe
    # On Linux/Mac
    ./solver
    ```

## 🎮 使用方法

运行程序后，您将看到主菜单：
Welcome to My System!
1. Sat    2. Sudoku
0. Exit
请输入你的选择[0-2]:


### 1. SAT 求解模式
-   选择选项 `1`。
-   根据提示输入 CNF 文件名（如 `example.cnf`）。
-   程序将进行求解，并在同目录下生成对应的 `.res` 结果文件，包含求解结果和耗时。

### 2. 数独游戏模式
-   选择选项 `2`。
-   根据提示输入要挖的洞数（即难度，例如 `40`）。
-   系统会显示生成的数独棋盘。
-   选择 `1. Answer`，程序将利用 SAT 求解器解出答案，并保存在结果文件中。

## ⚙️ 核心实现

### 数据结构
-   **`CNode`**: 表示一个文字（Literal）。
-   **`CHead`**: 表示一个子句（Clause），是由 `CNode` 组成的链表。
-   **`times`**: 用于记录变元出现频次，以优化分支策略。

### 关键算法
1.  **DPLL 算法**: 在 `DPLLSolver.c` 中实现，包含单子句传播、纯文字消除、分裂策略等步骤。
2.  **分支策略优化**:
    -   `strategy1`: 朴素策略，选择第一个出现的文字。
    -   `strategy2`: **优化策略**，选择整个公式中出现频次最高的文字。
3.  **数独问题转换**: 在 `TranToCNF` 函数中，将数独的规则（单元格、行、列、宫、对角线）全部转换为 CNF 子句，共约 6642 + (81 - 挖洞数) 条子句。

## 📊 性能优化

项目对 DPLL 求解器进行了性能优化，通过比较两种策略的运行时间来计算优化率：
`优化率 = [(t - t₀) / t] * 100%`
其中 `t` 为优化前时间，`t₀` 为优化后时间。测试表明优化策略能有效提升求解速度。

## 👥 开发者

-   **叶润莹** - *计算机科学与技术 2305 班* - `U202315573`
-   **指导教师**：李丹 老师

**华中科技大学计算机科学与技术学院 - 2024.10**

---

<div align="center">
    <sub><sup>⚡ 由 DPLL 算法驱动</sup></sub>
</div>
