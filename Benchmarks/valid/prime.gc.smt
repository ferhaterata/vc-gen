(declare-const n Int)

(assert (not (=> (<= 2 n) true)))
(check-sat)
(exit)
