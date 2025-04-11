# Cf Compiler
**Cf** (*C Functional*) is a purely functional, strictly typed, C-esque compiled programming language. This repository contains the source code and tooling for the Cf compiler.

Cf is designed to blend the familiarity of C-style syntax with the rigor of purely functional programming. It enforces immutability, pure functions, and composibility--without sacrificing performance, readability, or control over low-level execution.

---

## Language Goals

- **Strict Static Typing** - All types are resolved at compile-time with no implicit conversions.
- **Purely Functional** - Functions are first-class citizens, and mutation is opt-in and explicit.
- **C-Inspired Syntax** - Familiar control structures and syntax for ease of adoption by C-family developers.
- **Compiled & Fast** - Ahead-of-time compilation with performance close to C/C++.
- **Readable & Expressive** - Syntax that prioritizes clarity and intention.
- **Functional + OOP Support** - Strong functional foundation with optional object-oriented constructs.

---

## Compiler Architecture

The Cf compiler is structured in modular stages:

```
cfc/ <- Main compiler source
├── lexer/    <- Tokenizes Cf source code
├── parser/   <- Converts tokens into AST
├── ast/      <- Abstract syntax tree definitions and traversal tools
├── semantic/ <- Type checking and function resolution
├── codegen/  <- Generates LLVM IR or other intermediate formats
└── runtime/  <- Optional runtime support for functional features
```

---

## Language Features (WIP)

- Immutable variables by default (`let`, `const`)
- Pure functions with guaranteed no side effects
- Algebraic data types and pattern matching
- Custom control structures
- Higher-order functions and closures
- Tail call optimization
- Module system with explicit imports
- Optional lightweight classes/objects for modular design

---

## Building the Compiler

> **Note:** Cf is in early development and not ready for general use.

### Prerequisites

- C++17 or newer compiler (e.g., `g++`, `clang++`)
- CMake (>=3.15)
- LLVM (optional, for backend codegen)

```bash
git clone https://github.com/rjmee3/cf-compiler.git
cd cf-compiler
make
```

This will generate the `cfc` binary in the `build/` directory.

---

## Hello World (Planned Syntax)

```
// main.cf
fn main() -> Int {
   print("Hello, world!");
   return 0;
}
```

---

## Design Philosophy

Cf aims to strip away incidental complexity. By enforcing function purity, strong typing, and clear syntax, it seeks to be:

- **Minimal** in concept
- **Powerful** in abstraction
- **Explicit** in behavior

It is not designed to replace C, but explore what a functional-first systems language might look like if it were shaped by C's principles.

---

## Roadmap

### Phase 1: Seed Compiler - Arithmetic Core (Functional, Typed)
**Goal:** Build the smallest viable compiler for purely functional expression evaluation with strict typing.

- [ ] **Minimal Grammar**
  - Support literals and arithmetic ops: `+`, `-`, `*`, `/`
  - Syntax example: `1 + (2 * 3)`

- [ ] **Basic Type System**
  - Primitive types: `Int`, `Float`, `Bool`
  - Type checking and error reporting

- [ ] **Compiler Pipeline**
  - Lexer → Parser → Typed AST → IR → C++ → Binary

### Phase 2: Functions + Let Bindings
**Goal:** Introduce functional programming structures and lexical scope.

- [ ] **Let Bindings**
  - Immutable bindings  
    ```Cf
    let x: Int = 5
    ```

- [ ] **First-Class Functions**
  - Named and anonymous functions  
    ```Cf
    fn add(x: Int, y: Int) -> Int { x + y; }
    ```

- [ ] **Recursion Support**
  - Allow recursive functions  
    ```Cf
    fn factorial(n: Int) -> Int {
      if n <= 1 then 1 else n * factorial(n - 1);
    }
    ```

- [ ] **Closures (Optional)**
  - Functions capturing outer-scope variables

### Phase 3: Advanced Type System
**Goal:** Make the type system expressive and safe.

- [ ] **Type Inference (Optional)**
  - Infer types where annotations are omitted

- [ ] **Custom Types & ADTs**
  - Support algebraic data types and variants  
    ```Cf
    type Option<T> = Some(T) | None
    ```

- [ ] **Type Checking**
  - Pattern matching exhaustiveness
  - Purity enforcement (no side effects unless tagged)

### Phase 4: Control Structures & Composition
**Goal:** Add expressive control flow with a functional twist.

- [ ] **Custom Control Structures**
  - Define new keywords like `unless`, `repeat`, etc.
  - Desugar internally to core expressions

- [ ] **Pattern Matching**
  - Functional `match` expression  
    ```Cf
    match maybeVal with
      Some(x) => x
      None    => 0
    ```

- [ ] **Higher-Order Functions**
  - `map`, `fold`, `filter`, etc.

### Phase 5: Intermediate Representation & Optimization
**Goal:** Add an IR layer and optimize programs.

- [ ] **Custom IR or LLVM IR**
  - Translate AST to IR for easier transformation

- [ ] **Optimizations**
  - Tail call optimization
  - Constant folding
  - Dead code elimination
  - Function inlining

### Phase 6: Compilation to Executable
**Goal:** Produce native executables.

- [ ] **C++ Backend**
  - Translate IR to C++ code
  - Compile using system compiler (`g++`, `clang++`)

- [ ] **Optional: LLVM Backend**
  - Generate LLVM IR directly for performance

### Phase 7: Modules & Interoperability
**Goal:** Add modularity and C-level interop.

- [ ] **Module System**
  - Namespaces, `import`, `export`

- [ ] **C Interop**
  - `extern fn` support
  - Link with external libraries

- [ ] **REPL (Optional)**
  - Interactive evaluation of expressions

### Phase 8: Functional OOP (Optional)
**Goal:** Enable encapsulation using functional principles.

- [ ] **Records with Methods**
  - Struct-like types with associated functions

- [ ] **Traits / Typeclasses / Interfaces**
  - Ad-hoc polymorphism  
    ```yourlang
    trait Eq {
      fn eq(self, other): Bool
    }
    ```

- [ ] **Pure Object Patterns**
  - Use closures + records to emulate objects

## Contributing
Cf is a solo passion project right now, but PRs and ideas are welcome! Open an issue or start a discussion to get involved.

## License
MIT License--see LICENSE for details.
