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
│   ├── find_invalid.imp            /* Given INVALID benchmarks   */
│   ├── order_invalid.imp
│   └── prime_invalid.imp
└── valid                           /* Given VALID benchmarks     */
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
$ ./vcgen Benchmarks/ferhat/max.imp

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
   
* Run 3: 
````
$ ./vcgen Benchmarks/ferhat/binary_search.imp 

---------------------------------------------------------------
        Ferhat Erata
        CPSC 454/554
        Sun Nov  3 2019 19:57:46
---------------------------------------------------------------
program binarySearch
   pre N >= 0
   pre forall j k, (0 <= j && j < k && k < N) ==> a[j] <= a[k]
   post (0 <= index && index < N) ==> a[index] = value
   post 0 > index ==> forall k, (0 <= k && k < N) ==> a[k] != value
is
   low, high := 0, N;
   while (low < high)
      inv 0 <= low && low <= high && high <= N
      inv forall i, (0 <= i && i < N && !(low <= i && i < high)) ==> a[i] != value
   do
      mid := (low + high) / 2;
      if (a[mid] < value)
      then
         low := mid + 1;
      else
          if (value < a[mid])
          then
             high := mid;
          else
             index := mid;
          end
      end
   end
   index := -1;
end
---------------------------------------------------------------
(program binarySearch
  (precondition (N >= 0))
  (precondition (forall j k ((((0 <= j) and ((j < k) and (k < N)))) implies (a[j] <= a[k]))))
  (postcondition ((((0 <= index) and (index < N))) implies (a[index] = value)))
  (postcondition ((0 > index) implies (forall k ((((0 <= k) and (k < N))) implies (a[k] != value)))))
(low, high := 0, N)
(while ((low < high))
  (invariant ((0 <= low) and ((low <= high) and (high <= N))))
  (invariant (forall i ((((0 <= i) and ((i < N) and (not (((low <= i) and (i < high))) )))) implies (a[i] != value))))
(mid := (((low + high)) / 2))
(if ((a[mid] < value)) then (low := (mid + 1)) else (if ((value < a[mid])) then (high := mid) else (index := mid))))
(index := (-1))
---------------------------------------------------------------
assume N >= 0; assume forall j k, (0 <= j && j < k && k < N) ==> read(a, j) <= read(a, k); 
assume low!0 = low; havoc low; assume low = 0;
assume high!0 = high; havoc high; assume high = N;
assert 0 <= low && low <= high && high <= N; assert forall i, (0 <= i && i < N && ! (low <= i && i < high)) ==> read(a, i) != value; 
havoc mid; havoc low; havoc high; havoc index; 
assume 0 <= low && low <= high && high <= N; assume forall i, (0 <= i && i < N && ! (low <= i && i < high)) ==> read(a, i) != value; 
(assume (low < high);
 assume mid!0 = mid; havoc mid; assume mid = (low + high) / 2;
 (assume (read(a, mid) < value);
  assume low!1 = low; havoc low; assume low = mid + 1;
  []
  assume !((read(a, mid) < value));(assume (value < read(a, mid));
   assume high!1 = high; havoc high; assume high = mid;
   []
   assume !((value < read(a, mid)));assume index!0 = index; havoc index; assume index = mid;))
 assert 0 <= low && low <= high && high <= N; assert forall i, (0 <= i && i < N && ! (low <= i && i < high)) ==> read(a, i) != value; assume false;
 []
 assume !((low < high));)
assume index!1 = index; havoc index; assume index = -1;
assert (0 <= index && index < N) ==> read(a, index) = value; assert 0 > index ==> forall k, (0 <= k && k < N) ==> read(a, k) != value; 
---------------------------------------------------------------
(declare-const index Int)
(declare-const k Int)
(declare-const N Int)
(declare-const a (Array Int Int))
(declare-const value Int)
(declare-const index?0 Int)
(declare-const index!1 Int)
(declare-const i Int)
(declare-const low Int)
(declare-const high Int)
(declare-const mid Int)
(declare-const low?1 Int)
(declare-const low!1 Int)
(declare-const high?2 Int)
(declare-const high!1 Int)
(declare-const index?3 Int)
(declare-const index!0 Int)
(declare-const mid?4 Int)
(declare-const mid!0 Int)
(declare-const index?5 Int)
(declare-const high?6 Int)
(declare-const low?7 Int)
(declare-const mid?8 Int)
(declare-const high?9 Int)
(declare-const high!0 Int)
(declare-const low?10 Int)
(declare-const low!0 Int)
(declare-const j Int)

(assert (not (=> (>= N 0) (=> (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (< k N))) (<= (select a j) (select a k)))) (=> (= low!0 low) (=> (= low?10 0) (=> (= high!0 high) (=> (= high?9 N) (and (and (<= 0 low?10) (and (<= low?10 high?9) (<= high?9 N))) (and (forall ((i Int)) (=> (and (<= 0 i) (and (< i N) (not (and (<= low?10 i) (< i high?9))))) (not (= (select a i) value)))) (=> (and (<= 0 low?7) (and (<= low?7 high?6) (<= high?6 N))) (=> (forall ((i Int)) (=> (and (<= 0 i) (and (< i N) (not (and (<= low?7 i) (< i high?6))))) (not (= (select a i) value)))) (and (=> (< low?7 high?6) (=> (= mid!0 mid?8) (=> (= mid?4 (div (+ low?7 high?6) 2)) (and (=> (< (select a mid?4) value) (=> (= low!1 low?7) (=> (= low?1 (+ mid?4 1)) (and (and (<= 0 low?1) (and (<= low?1 high?6) (<= high?6 N))) (and (forall ((i Int)) (=> (and (<= 0 i) (and (< i N) (not (and (<= low?1 i) (< i high?6))))) (not (= (select a i) value)))) (=> false (=> (= index!1 index?5) (=> (= index?0 (- 1)) (and (=> (and (<= 0 index?0) (< index?0 N)) (= (select a index?0) value)) (and (=> (> 0 index?0) (forall ((k Int)) (=> (and (<= 0 k) (< k N)) (not (= (select a k) value))))) true)))))))))) (=> (not (< (select a mid?4) value)) (and (=> (< value (select a mid?4)) (=> (= high!1 high?6) (=> (= high?2 mid?4) (and (and (<= 0 low?7) (and (<= low?7 high?2) (<= high?2 N))) (and (forall ((i Int)) (=> (and (<= 0 i) (and (< i N) (not (and (<= low?7 i) (< i high?2))))) (not (= (select a i) value)))) (=> false (=> (= index!1 index?5) (=> (= index?0 (- 1)) (and (=> (and (<= 0 index?0) (< index?0 N)) (= (select a index?0) value)) (and (=> (> 0 index?0) (forall ((k Int)) (=> (and (<= 0 k) (< k N)) (not (= (select a k) value))))) true)))))))))) (=> (not (< value (select a mid?4))) (=> (= index!0 index?5) (=> (= index?3 mid?4) (and (and (<= 0 low?7) (and (<= low?7 high?6) (<= high?6 N))) (and (forall ((i Int)) (=> (and (<= 0 i) (and (< i N) (not (and (<= low?7 i) (< i high?6))))) (not (= (select a i) value)))) (=> false (=> (= index!1 index?3) (=> (= index?0 (- 1)) (and (=> (and (<= 0 index?0) (< index?0 N)) (= (select a index?0) value)) (and (=> (> 0 index?0) (forall ((k Int)) (=> (and (<= 0 k) (< k N)) (not (= (select a k) value))))) true)))))))))))))))) (=> (not (< low?7 high?6)) (=> (= index!1 index?5) (=> (= index?0 (- 1)) (and (=> (and (<= 0 index?0) (< index?0 N)) (= (select a index?0) value)) (and (=> (> 0 index?0) (forall ((k Int)) (=> (and (<= 0 k) (< k N)) (not (= (select a k) value))))) true))))))))))))))))))
(check-sat)
(exit)

---------------------------------------------------------------
unsat :: Valid!
---------------------------------------------------------------
Normal termination.

````