<!--
// -----------------------------------------------------------------------------
// File: readme.md -------------------------------------------------------------
// Created by Ferhat Erata <ferhat.erata@yale.edu> on Sun November 03, 2019 
// -----------------------------------------------------------------------------
-->

Prerequisites: 
--------------
* Prepared and tested on linux environments (including _zoo_ machines).
* -std=c++17 g++ compiler or above

Quick Overview:
--------------
* There are two front-ends: **imp** and **gc** languages. 
* Tooling workflow:  

**.imp** =compile=> **.gc** =compile=> **.gc.smt** =z3=> **.gc.smt.out**

Building and Running:
---------------------
1. To build release version: `make`

2. To build debug version: `make debug`

3. To clean: `make clean`

4. To run: `./vcgen <filename>`  
   
   This command generates:  
   * <filename>.gc          : Guarded Command Language input
   * <filename>.gc.smt      : SMT-LIB language input
   * <filename>.gc.smt.out  : SMT solver output

5. To trace parsing (`-p`) and/or scanning (`-s`):  

    `./vcgen -p -s <filename>` 
   
Code Structure:
---------------
````
.
├── gc                              /* GC Language Namespace    */  
│   ├── ast                         
│   │   ├── gc.cpp
│   │   ├── gc.hpp                  /* Abstract Syntax Tree     */
│   │   ├── printer-visitor.hpp     /* Pretty Printer Visitor   */
│   │   └── visitor.hpp             /* Pure Abstract Visitor    */
│   ├── recognizer                  /* Flex/Bison Recognizer    */
│   │   ├── gc-parser.cpp
│   │   ├── gc-parser.gv
│   │   ├── gc-parser.hpp
│   │   ├── gc-parser.output
│   │   ├── gc-scanner.cpp
│   │   └── location.hh
│   ├── compiler
│   │   └── smt-compiler.hpp        /* SMT-LIB Compiler Visitor */
│   ├── gc-driver.cpp
│   ├── gc-driver.hpp               /* Driver for GC Language   */
│   ├── gc-parser.yy                /* Bison Parser Definition  */
│   ├── gc-scanner.ll               /* Flex Lexer Definition    */
│   └── test.cpp
├── imp                             /* IMP Language Namespace   */
│   ├── ast
│   │   ├── imp.cpp
│   │   ├── imp.hpp                 /* Abstract Syntax Tree     */
│   │   ├── printer-visitor.hpp     /* Pretty Printer Visitor   */
│   │   └── visitor.hpp             /* Pure Abstract Visitor    */
│   ├── recognizer                  /* Flex/Bison Recognizer    */
│   │   ├── imp-parser.cpp
│   │   ├── imp-parser.gv
│   │   ├── imp-parser.hpp
│   │   ├── imp-parser.output
│   │   ├── imp-scanner.cpp
│   │   ├── location.hh
│   │   └── location.hpp
│   ├── compiler                    /* GC Compiler Visitor      */
│   │   └── gc-compiler.hpp
│   ├── imp-driver.cpp
│   ├── imp-driver.hpp              /* Driver for IMP Language  */
│   ├── imp-parser.yy               /* Bison Parser Definition  */
│   └── imp-scanner.ll              /* Flex Lexer Definition    */
├── solver                          /* SMT Solver Namespace     */
│   ├── z3-solver.cpp
│   └── z3-solver.hpp               /* Z3 Solver Wrapper        */
├── Makefile                        /* Make (Build/Debug/Clean) */
├── readme.md                       /* This File                */
├── CMakeLists.txt                  /* CMake Configuration      */
├── .clang-format                   /* C++ Formatting Definition*/
├── tools.cpp                     
├── tools.hpp                       /* Macro definitions        */
└── vcgen.cpp                       /* Main Conductor           */
````   
Benchmarks:
---------------
````
Benchmarks
├── ferhat                          /* My own VALID benchmarks   */
│   ├── abs.imp                     
│   ├── add.imp                     
│   ├── binary_search.imp
│   ├── concat.imp
│   ├── copy.imp
│   ├── count.imp
│   ├── cube.imp
│   ├── less_more.imp
│   ├── max.imp
│   ├── test1.imp
│   └── test2.imp
├── invalid
│   ├── find_invalid.imp
│   ├── order_invalid.imp
│   └── prime_invalid.imp
└── valid
    ├── bubble.imp
    ├── example.imp
    ├── find.imp
    ├── gcd.imp
    ├── lcm.imp
    ├── mod.imp
    ├── mult.imp
    ├── order.imp
    ├── prime.imp
    ├── rev.imp
    └── test.imp
````
Examples:   
---------
* Run 1: 
````
$ ./vcgen Benchmarks/ferhat/cube.imp

---------------------------------------------------------------
        Ferhat Erata
        CPSC 454/554
        Sun Nov  3 2019 15:38:58
---------------------------------------------------------------
program cube
  pre 0 <= N
  post c = N*N*N
is
  c := 0;
  n, k := 0, 1;
  m := 6;
  while n < N
    inv n <= N
    inv c = n*n*n
    inv k = 3*n*n + 3*n + 1
    inv m = 6*n + 6
  do
    c := c + k;
    k := k + m;
    m := m + 6;
    n := n + 1;
  end
end
---------------------------------------------------------------
(program cube
  (precondition (0 <= N))
  (postcondition (c = ((N * N) * N)))
(c := 0)
(n, k := 0, 1)
(m := 6)
(while (n < N)
  (invariant (n <= N))
  (invariant (c = ((n * n) * n)))
  (invariant (k = ((((3 * n) * n) + (3 * n)) + 1)))
  (invariant (m = ((6 * n) + 6)))
(c := (c + k))
(k := (k + m))
(m := (m + 6))
(n := (n + 1)))
---------------------------------------------------------------
assume 0 <= N; 
assume c!0 = c; havoc c; assume c = 0;
assume n!0 = n; havoc n; assume n = 0;
assume k!0 = k; havoc k; assume k = 1;
assume m!0 = m; havoc m; assume m = 6;
assert n <= N; assert c = n * n * n; assert k = 3 * n * n + 3 * n + 1; assert m = 6 * n + 6; 
havoc c; havoc m; havoc k; havoc n; 
assume n <= N; assume c = n * n * n; assume k = 3 * n * n + 3 * n + 1; assume m = 6 * n + 6; 
(assume n < N;
 assume c!1 = c; havoc c; assume c = c!1 + k;
 assume k!1 = k; havoc k; assume k = k!1 + m;
 assume m!1 = m; havoc m; assume m = m!1 + 6;
 assume n!1 = n; havoc n; assume n = n!1 + 1;
 assert n <= N; assert c = n * n * n; assert k = 3 * n * n + 3 * n + 1; assert m = 6 * n + 6; assume false;
 []
 assume !(n < N);)
assert c = N * N * N; 
---------------------------------------------------------------
(declare-const c Int)
(declare-const N Int)
(declare-const m Int)
(declare-const n Int)
(declare-const k Int)
(declare-const n!1 Int)
(declare-const n?0 Int)
(declare-const m!1 Int)
(declare-const m?1 Int)
(declare-const k!1 Int)
(declare-const k?2 Int)
(declare-const c!1 Int)
(declare-const c?3 Int)
(declare-const n?4 Int)
(declare-const k?5 Int)
(declare-const m?6 Int)
(declare-const c?7 Int)
(declare-const m?8 Int)
(declare-const m!0 Int)
(declare-const k?9 Int)
(declare-const k!0 Int)
(declare-const n?10 Int)
(declare-const n!0 Int)
(declare-const c?11 Int)
(declare-const c!0 Int)

(assert (not (=> (<= 0 N) (=> (= c!0 c) (=> (= c?11 0) (=> (= n!0 n) (=> (= n?10 0) (=> (= k!0 k) (=> (= k?9 1) (=> (= m!0 m) (=> (= m?8 6) (and (<= n?10 N) (and (= c?11 (* (* n?10 n?10) n?10)) (and (= k?9 (+ (+ (* (* 3 n?10) n?10) (* 3 n?10)) 1)) (and (= m?8 (+ (* 6 n?10) 6)) (=> (<= n?4 N) (=> (= c?7 (* (* n?4 n?4) n?4)) (=> (= k?5 (+ (+ (* (* 3 n?4) n?4) (* 3 n?4)) 1)) (=> (= m?6 (+ (* 6 n?4) 6)) (and (=> (< n?4 N) (=> (= c!1 c?7) (=> (= c?3 (+ c!1 k?5)) (=> (= k!1 k?5) (=> (= k?2 (+ k!1 m?6)) (=> (= m!1 m?6) (=> (= m?1 (+ m!1 6)) (=> (= n!1 n?4) (=> (= n?0 (+ n!1 1)) (and (<= n?0 N) (and (= c?3 (* (* n?0 n?0) n?0)) (and (= k?2 (+ (+ (* (* 3 n?0) n?0) (* 3 n?0)) 1)) (and (= m?1 (+ (* 6 n?0) 6)) (=> false (and (= c?3 (* (* N N) N)) true))))))))))))))) (=> (not (< n?4 N)) (and (= c?7 (* (* N N) N)) true))))))))))))))))))))))
(check-sat)
(exit)

---------------------------------------------------------------
unsat :: Valid!
---------------------------------------------------------------
Normal termination.

````
   
* Run 2: 
````
$ ./vcgen Benchmarks/ferhat/cube.imp

---------------------------------------------------------------
        Ferhat Erata
        CPSC 454/554
        Sun Nov  3 2019 15:47:33
---------------------------------------------------------------
program max
    post forall j, (l <= j && j <= u) ==> a[j] <= max
is
    max := a[l];
    i := l + 1;
    while i <= u
        inv forall j, (l <= j && j < i) ==> a[j] <= max
    do
        if a[i] > max
        then
            max := a[i];
        end
        i := i + 1;
    end
end
---------------------------------------------------------------
(program max
  (postcondition (forall j ((((l <= j) and (j <= u))) implies (a[j] <= max))))
(max := a[l])
(i := (l + 1))
(while (i <= u)
  (invariant (forall j ((((l <= j) and (j < i))) implies (a[j] <= max))))
(if (a[i] > max) then (max := a[i]))
(i := (i + 1)))
---------------------------------------------------------------
assume max!0 = max; havoc max; assume max = read(a, l);
assume i!0 = i; havoc i; assume i = l + 1;
assert forall j, (l <= j && j < i) ==> read(a, j) <= max; 
havoc max; havoc i; 
assume forall j, (l <= j && j < i) ==> read(a, j) <= max; 
(assume i <= u;
 (assume read(a, i) > max;
  assume max!1 = max; havoc max; assume max = read(a, i);
  []
  assume !(read(a, i) > max); assume true;)
 assume i!1 = i; havoc i; assume i = i!1 + 1;
 assert forall j, (l <= j && j < i) ==> read(a, j) <= max; assume false;
 []
 assume !(i <= u);)
assert forall j, (l <= j && j <= u) ==> read(a, j) <= max; 
---------------------------------------------------------------
(declare-const l Int)
(declare-const j Int)
(declare-const u Int)
(declare-const a (Array Int Int))
(declare-const max Int)
(declare-const i Int)
(declare-const i!1 Int)
(declare-const i?0 Int)
(declare-const max?1 Int)
(declare-const max!1 Int)
(declare-const i?2 Int)
(declare-const max?3 Int)
(declare-const i?4 Int)
(declare-const i!0 Int)
(declare-const max?5 Int)
(declare-const max!0 Int)

(assert (not (=> (= max!0 max) (=> (= max?5 (select a l)) (=> (= i!0 i) (=> (= i?4 (+ l 1)) (and (forall ((j Int)) (=> (and (<= l j) (< j i?4)) (<= (select a j) max?5))) (=> (forall ((j Int)) (=> (and (<= l j) (< j i?2)) (<= (select a j) max?3))) (and (=> (<= i?2 u) (and (=> (> (select a i?2) max?3) (=> (= max!1 max?3) (=> (= max?1 (select a i?2)) (=> (= i!1 i?2) (=> (= i?0 (+ i!1 1)) (and (forall ((j Int)) (=> (and (<= l j) (< j i?0)) (<= (select a j) max?1))) (=> false (and (forall ((j Int)) (=> (and (<= l j) (<= j u)) (<= (select a j) max?1))) true)))))))) (=> (not (> (select a i?2) max?3)) (=> true (=> (= i!1 i?2) (=> (= i?0 (+ i!1 1)) (and (forall ((j Int)) (=> (and (<= l j) (< j i?0)) (<= (select a j) max?3))) (=> false (and (forall ((j Int)) (=> (and (<= l j) (<= j u)) (<= (select a j) max?3))) true))))))))) (=> (not (<= i?2 u)) (and (forall ((j Int)) (=> (and (<= l j) (<= j u)) (<= (select a j) max?3))) true)))))))))))
(check-sat)
(exit)

---------------------------------------------------------------
unsat :: Valid!
---------------------------------------------------------------
Normal termination.

````
