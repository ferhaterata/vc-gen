(declare-const p Int)
(declare-const i Int)
(declare-const n Int)
(declare-const j Int)
(declare-const i!1 Int)
(declare-const i?0 Int)
(declare-const p?1 Int)
(declare-const p!1 Int)
(declare-const i?2 Int)
(declare-const p?3 Int)
(declare-const p?4 Int)
(declare-const p!0 Int)
(declare-const i?5 Int)
(declare-const i!0 Int)

(assert (not (=> (<= 2 n) (=> (= i!0 i) (=> (= i?5 3) (=> (= p!0 p) (=> (= p?4 1) (and (<= i?5 n) (and (=> (= p?4 1) (forall ((j Int)) (=> (and (<= 2 j) (< j i?5)) (not (= (mod n j) 0))))) (=> (<= i?2 n) (=> (=> (= p?3 1) (forall ((j Int)) (=> (and (<= 2 j) (< j i?2)) (not (= (mod n j) 0))))) (and (=> (< i?2 n) (and (=> (= (mod n i?2) 0) (=> (= p!1 p?3) (=> (= p?1 0) (=> (= i!1 i?2) (=> (= i?0 (+ i!1 1)) (and (<= i?0 n) (and (=> (= p?1 1) (forall ((j Int)) (=> (and (<= 2 j) (< j i?0)) (not (= (mod n j) 0))))) (=> false (and (=> (= p?1 1) (forall ((i?0 Int)) (=> (and (<= 2 i?0) (< i?0 n)) (not (= (mod n i?0) 0))))) true))))))))) (=> (not (= (mod n i?2) 0)) (=> true (=> (= i!1 i?2) (=> (= i?0 (+ i!1 1)) (and (<= i?0 n) (and (=> (= p?3 1) (forall ((j Int)) (=> (and (<= 2 j) (< j i?0)) (not (= (mod n j) 0))))) (=> false (and (=> (= p?3 1) (forall ((i?0 Int)) (=> (and (<= 2 i?0) (< i?0 n)) (not (= (mod n i?0) 0))))) true)))))))))) (=> (not (< i?2 n)) (and (=> (= p?3 1) (forall ((i?2 Int)) (=> (and (<= 2 i?2) (< i?2 n)) (not (= (mod n i?2) 0))))) true))))))))))))))
(check-sat)
(exit)
