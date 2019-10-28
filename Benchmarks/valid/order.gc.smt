(assert x > y; assert x!0 = x; havoc x; assert x = y;  assert y!0 = y; havoc y; assert y = x;  )
 []
(assert not x > y ; assert x!1 = x; havoc x; assert x = x!1;  assert y!1 = y; havoc y; assert y = y!1;  ) 
assume x <= y; 
