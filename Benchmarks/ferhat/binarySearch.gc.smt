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
(declare-const high?1 Int)
(declare-const high!1 Int)
(declare-const index?2 Int)
(declare-const index!0 Int)
(declare-const low?3 Int)
(declare-const low!1 Int)
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

(assert (not (=> (forall ((j Int)(k Int)) (=> (and (<= 0 j) (and (< j k) (< k N))) (<= (select a j) (select a k)))) (=> (= low!0 low) (=> (= low?10 0) (=> (= high!0 high) (=> (= high?9 N) (and (and (<= 0 low?10) (and (<= low?10 high?9) (<= high?9 N))) (and (forall ((i Int)) (=> (and (<= 0 i) (and (< i N) (and (not (<= low?10 i)) (< i high?9)))) (not (= (select a i) value)))) (=> (and (<= 0 low?7) (and (<= low?7 high?6) (<= high?6 N))) (=> (forall ((i Int)) (=> (and (<= 0 i) (and (< i N) (and (not (<= low?7 i)) (< i high?6)))) (not (= (select a i) value)))) (and (=> (< low?7 high?6) (=> (= mid!0 mid?8) (=> (= mid?4 (+ low?7 (div high?6 2))) (=> (< (select a mid?4) value) (=> (= low!1 low?7) (=> (= low?3 (+ mid?4 1)) (and (=> (< value (select a mid?4)) (=> (= high!1 high?6) (=> (= high?1 mid?4) (and (and (<= 0 low?3) (and (<= low?3 high?1) (<= high?1 N))) (and (forall ((i Int)) (=> (and (<= 0 i) (and (< i N) (and (not (<= low?3 i)) (< i high?1)))) (not (= (select a i) value)))) (=> false (=> (= index!1 index?5) (=> (= index?0 (- 1)) (and (=> (and (<= 0 index?0) (< index?0 N)) (= (select a index?0) value)) (and (=> (> 0 index?0) (forall ((k Int)) (=> (and (<= 0 k) (< k N)) (not (= (select a k) value))))) true)))))))))) (=> (not (< value (select a mid?4))) (=> (= index!0 index?5) (=> (= index?2 mid?4) (and (and (<= 0 low?3) (and (<= low?3 high?6) (<= high?6 N))) (and (forall ((i Int)) (=> (and (<= 0 i) (and (< i N) (and (not (<= low?3 i)) (< i high?6)))) (not (= (select a i) value)))) (=> false (=> (= index!1 index?2) (=> (= index?0 (- 1)) (and (=> (and (<= 0 index?0) (< index?0 N)) (= (select a index?0) value)) (and (=> (> 0 index?0) (forall ((k Int)) (=> (and (<= 0 k) (< k N)) (not (= (select a k) value))))) true))))))))))))))))) (=> (not (< low?7 high?6)) (=> (= index!1 index?5) (=> (= index?0 (- 1)) (and (=> (and (<= 0 index?0) (< index?0 N)) (= (select a index?0) value)) (and (=> (> 0 index?0) (forall ((k Int)) (=> (and (<= 0 k) (< k N)) (not (= (select a k) value))))) true)))))))))))))))))
(check-sat)
(exit)
