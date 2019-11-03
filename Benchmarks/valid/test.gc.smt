(declare-const i Int)
(declare-const a (Array Int Int))
(declare-const x Int)
(declare-const x?0 Int)
(declare-const x!0 Int)

(assert (not (=> (= x!0 x) (=> (= x?0 (+ (select a i) i)) (and (=> (and (= i 0) (= (select a i) 1)) (= x?0 1)) true)))))
(check-sat)
(exit)
