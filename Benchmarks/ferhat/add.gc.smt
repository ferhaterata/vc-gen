(declare-const r Int)
(declare-const x Int)
(declare-const y Int)
(declare-const n Int)
(declare-const n!1 Int)
(declare-const n?0 Int)
(declare-const r!1 Int)
(declare-const r?1 Int)
(declare-const n?2 Int)
(declare-const r?3 Int)
(declare-const n?4 Int)
(declare-const n!0 Int)
(declare-const r?5 Int)
(declare-const r!0 Int)

(assert (not (=> (and (<= 0 x) (<= 0 y)) (=> (= r!0 r) (=> (= r?5 (* 2 x)) (=> (= n!0 n) (=> (= n?4 y) (and (= r?5 (- (+ (* 2 x) y) n?4)) (=> (= r?3 (- (+ (* 2 x) y) n?2)) (and (=> (not (= n?2 0)) (=> (= r!1 r?3) (=> (= r?1 (+ r!1 1)) (=> (= n!1 n?2) (=> (= n?0 (- n!1 1)) (and (= r?1 (- (+ (* 2 x) y) n?0)) (=> false (and (= r?1 (+ (* 2 x) y)) true)))))))) (=> (not (not (= n?2 0))) (and (= r?3 (+ (* 2 x) y)) true))))))))))))
(check-sat)
(exit)
