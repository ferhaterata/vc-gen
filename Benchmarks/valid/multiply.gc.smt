(declare-const p Int)
(declare-const n Int)
(declare-const m Int)
(declare-const x Int)
(declare-const p!1 Int)
(declare-const p?0 Int)
(declare-const x!1 Int)
(declare-const x?1 Int)
(declare-const x?2 Int)
(declare-const p?3 Int)
(declare-const x?4 Int)
(declare-const x!0 Int)
(declare-const p?5 Int)
(declare-const p!0 Int)

(assert (not (=> (>= n 0) (=> (= p!0 p) (=> (= p?5 0) (=> (= x!0 x) (=> (= x?4 0) (and (= p?5 (* x?4 m)) (and (<= x?4 n) (=> (= p?3 (* x?2 m)) (=> (<= x?2 n) (and (=> (< x?2 n) (=> (= x!1 x?2) (=> (= x?1 (+ x!1 1)) (=> (= p!1 p?3) (=> (= p?0 (+ p!1 m)) (and (= p?0 (* x?1 m)) (and (<= x?1 n) (=> false (and (= p?0 (* n m)) true))))))))) (=> (not (< x?2 n)) (and (= p?3 (* n m)) true))))))))))))))
(check-sat)
(exit)
