assert 0 <= N; 
assert i!0 = i; havoc i; assert i = 0; 
assume i <= N; assume (forall j 0 <= j and j < i implies a[j] = b[N - j]); 
havoc i; havoc a; 
assert i <= N; assert (forall j 0 <= j and j < i implies a[j] = b[N - j]); 
(assert i < N; assert a!0[i] = a; havoc a; assert a = b[N - i];  assert i!1 = i; havoc i; assert i = i!1 + 1;  assume i <= N; assume (forall j 0 <= j and j < i implies a[j] = b[N - j]); assert false; )
 []
(assert not i < N ; ) 
assume (forall i 0 <= i and i < N implies a[i] = b[N - i]); 
