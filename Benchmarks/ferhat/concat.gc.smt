(declare-const c (Array Int Int))
(declare-const a (Array Int Int))
(declare-const b (Array Int Int))
(declare-const j Int)
(declare-const i Int)
(declare-const B Int)
(declare-const A Int)
(declare-const i!3 Int)
(declare-const i?0 Int)
(declare-const c!1 (Array Int Int))
(declare-const c?1 (Array Int Int))
(declare-const c?2 (Array Int Int))
(declare-const i?3 Int)
(declare-const i?4 Int)
(declare-const i!2 Int)
(declare-const N Int)
(declare-const i!1 Int)
(declare-const i?5 Int)
(declare-const c!0 (Array Int Int))
(declare-const c?6 (Array Int Int))
(declare-const c?7 (Array Int Int))
(declare-const i?8 Int)
(declare-const i?9 Int)
(declare-const i!0 Int)

(assert (not (=> (= i!0 i) (=> (= i?9 0) (and (and (<= 0 i?9) (<= i?9 N)) (and (forall ((j Int)) (=> (and (<= 0 j) (< j i?9)) (= (select c j) (select a j)))) (=> (and (<= 0 i?8) (<= i?8 N)) (=> (forall ((j Int)) (=> (and (<= 0 j) (< j i?8)) (= (select c?7 j) (select a j)))) (and (=> (< i?8 A) (=> (= c!0 c?7) (=> (= c?6 (store c!0 i?8 (select a i?8))) (=> (= i!1 i?8) (=> (= i?5 (+ i!1 1)) (and (and (<= 0 i?5) (<= i?5 N)) (and (forall ((j Int)) (=> (and (<= 0 j) (< j i?5)) (= (select c?6 j) (select a j)))) (=> false (=> (= i!2 i?5) (=> (= i?4 0) (and (and (<= 0 i?4) (<= i?4 B)) (and (forall ((j Int)) (=> (and (<= 0 j) (< j A)) (= (select c?6 j) (select a j)))) (and (forall ((j Int)) (=> (and (<= 0 j) (< j i?4)) (= (select c?6 (+ j B)) (select b j)))) (=> (and (<= 0 i?3) (<= i?3 B)) (=> (forall ((j Int)) (=> (and (<= 0 j) (< j A)) (= (select c?2 j) (select a j)))) (=> (forall ((j Int)) (=> (and (<= 0 j) (< j i?3)) (= (select c?2 (+ j B)) (select b j)))) (and (=> (< i?3 B) (=> (= c!1 c?2) (=> (= c?1 (store c!1 (+ i?3 A) (select b i?3))) (=> (= i!3 i?3) (=> (= i?0 (+ i!3 1)) (and (and (<= 0 i?0) (<= i?0 B)) (and (forall ((j Int)) (=> (and (<= 0 j) (< j A)) (= (select c?1 j) (select a j)))) (and (forall ((j Int)) (=> (and (<= 0 j) (< j i?0)) (= (select c?1 (+ j B)) (select b j)))) (=> false (and (= c?1 (+ a b)) true)))))))))) (=> (not (< i?3 B)) (and (= c?2 (+ a b)) true))))))))))))))))))) (=> (not (< i?8 A)) (=> (= i!2 i?8) (=> (= i?4 0) (and (and (<= 0 i?4) (<= i?4 B)) (and (forall ((j Int)) (=> (and (<= 0 j) (< j A)) (= (select c?7 j) (select a j)))) (and (forall ((j Int)) (=> (and (<= 0 j) (< j i?4)) (= (select c?7 (+ j B)) (select b j)))) (=> (and (<= 0 i?3) (<= i?3 B)) (=> (forall ((j Int)) (=> (and (<= 0 j) (< j A)) (= (select c?2 j) (select a j)))) (=> (forall ((j Int)) (=> (and (<= 0 j) (< j i?3)) (= (select c?2 (+ j B)) (select b j)))) (and (=> (< i?3 B) (=> (= c!1 c?2) (=> (= c?1 (store c!1 (+ i?3 A) (select b i?3))) (=> (= i!3 i?3) (=> (= i?0 (+ i!3 1)) (and (and (<= 0 i?0) (<= i?0 B)) (and (forall ((j Int)) (=> (and (<= 0 j) (< j A)) (= (select c?1 j) (select a j)))) (and (forall ((j Int)) (=> (and (<= 0 j) (< j i?0)) (= (select c?1 (+ j B)) (select b j)))) (=> false (and (= c?1 (+ a b)) true)))))))))) (=> (not (< i?3 B)) (and (= c?2 (+ a b)) true)))))))))))))))))))))
(check-sat)
(exit)
