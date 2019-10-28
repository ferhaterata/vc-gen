assert n >= 0; 
assert p!0 = p; havoc p; assert p = 0; 
assert x!0 = x; havoc x; assert x = 0; 
assume p = x * m and x <= n; 
havoc p; havoc x; 
assert p = x * m and x <= n; 
(assert n < N; assert x!1 = x; havoc x; assert x = x!1 + 1;  assert p!1 = p; havoc p; assert p = p!1 + m;  assume p = x * m and x <= n; assert false; )
 []
(assert not n < N ; ) 
assume p = p * m; 
