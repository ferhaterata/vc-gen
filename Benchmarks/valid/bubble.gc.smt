(declare-const i Int)
(declare-const j Int)
(declare-const n Int)
(declare-const a (Array Int Int))
(declare-const k Int)
(declare-const bound Int)
(declare-const bound!1 Int)
(declare-const bound?0 Int)
(declare-const i!1 Int)
(declare-const i?1 Int)
(declare-const a!1 (Array Int Int))
(declare-const t Int)
(declare-const a?2 (Array Int Int))
(declare-const a!0 (Array Int Int))
(declare-const a?3 (Array Int Int))
(declare-const t?4 Int)
(declare-const t!0 Int)
(declare-const i?5 Int)
(declare-const a?6 (Array Int Int))
(declare-const t?7 Int)
(declare-const i?8 Int)
(declare-const i!0 Int)
(declare-const bound?9 Int)
(declare-const bound?10 Int)
(declare-const bound!0 Int)

(assert (not (=> (> n 0) (=> (= bound!0 bound) (=> (= bound?10 n) (and (and (<= 0 bound?10) (<= bound?10 n)) (and (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (and (<= bound?10 k) (< k n)))) (<= (select a j) (select a k)))) (=> (and (<= 0 bound?9) (<= bound?9 n)) (=> (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (and (<= bound?9 k) (< k n)))) (<= (select a j) (select a k)))) (and (=> (> bound?9 0) (=> (= i!0 i) (=> (= i?8 0) (and (and (<= 0 i?8) (< i?8 bound?9)) (and (forall ((j Int)) (=> (and (<= 0 j) (< j i?8)) (<= (select a j) (select a i?8)))) (and (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (and (<= bound?9 k) (< k n)))) (<= (select a j) (select a k)))) (=> (and (<= 0 i?5) (< i?5 bound?9)) (=> (forall ((j Int)) (=> (and (<= 0 j) (< j i?5)) (<= (select a?6 j) (select a?6 i?5)))) (=> (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (and (<= bound?9 k) (< k n)))) (<= (select a?6 j) (select a?6 k)))) (and (=> (< i?5 (- bound?9 1)) (and (=> (> (select a?6 i?5) (select a?6 (+ i?5 1))) (=> (= t!0 t?7) (=> (= t?4 (select a?6 i?5)) (=> (= a!0 a?6) (=> (= a?3 (store a!0 i?5 (select a!0 (+ i?5 1)))) (=> (= a!1 a?3) (=> (= a?2 (store a!1 (+ i?5 1) t?4)) (=> (= i!1 i?5) (=> (= i?1 (+ i!1 1)) (and (and (<= 0 i?1) (< i?1 bound?9)) (and (forall ((j Int)) (=> (and (<= 0 j) (< j i?1)) (<= (select a?2 j) (select a?2 i?1)))) (and (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (and (<= bound?9 k) (< k n)))) (<= (select a?2 j) (select a?2 k)))) (=> false (=> (= bound!1 bound?9) (=> (= bound?0 (- bound!1 1)) (and (and (<= 0 bound?0) (<= bound?0 n)) (and (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (and (<= bound?0 k) (< k n)))) (<= (select a?2 j) (select a?2 k)))) (=> false (and (forall ((i?1 Int)(j Int)) (=> (and (<= 0 i?1) (and (<= i?1 j) (< j n))) (<= (select a?2 i?1) (select a?2 j)))) true))))))))))))))))))) (=> (not (> (select a?6 i?5) (select a?6 (+ i?5 1)))) (=> true (=> (= i!1 i?5) (=> (= i?1 (+ i!1 1)) (and (and (<= 0 i?1) (< i?1 bound?9)) (and (forall ((j Int)) (=> (and (<= 0 j) (< j i?1)) (<= (select a?6 j) (select a?6 i?1)))) (and (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (and (<= bound?9 k) (< k n)))) (<= (select a?6 j) (select a?6 k)))) (=> false (=> (= bound!1 bound?9) (=> (= bound?0 (- bound!1 1)) (and (and (<= 0 bound?0) (<= bound?0 n)) (and (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (and (<= bound?0 k) (< k n)))) (<= (select a?6 j) (select a?6 k)))) (=> false (and (forall ((i?1 Int)(j Int)) (=> (and (<= 0 i?1) (and (<= i?1 j) (< j n))) (<= (select a?6 i?1) (select a?6 j)))) true)))))))))))))))) (=> (not (< i?5 (- bound?9 1))) (=> (= bound!1 bound?9) (=> (= bound?0 (- bound!1 1)) (and (and (<= 0 bound?0) (<= bound?0 n)) (and (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (and (<= bound?0 k) (< k n)))) (<= (select a?6 j) (select a?6 k)))) (=> false (and (forall ((i?5 Int)(j Int)) (=> (and (<= 0 i?5) (and (<= i?5 j) (< j n))) (<= (select a?6 i?5) (select a?6 j)))) true))))))))))))))))) (=> (not (> bound?9 0)) (and (forall ((i Int)(j Int)) (=> (and (<= 0 i) (and (<= i j) (< j n))) (<= (select a i) (select a j)))) true))))))))))))
(check-sat)
(exit)