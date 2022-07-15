>++++++++ initialize c1 to 8
[ while c1
	<++++++ increment c0 by 6
	>- decrement c1 by 1
]
, c1 = getchar()
>, c2 = getchar()
[ while c2
	<+ increment c1 by 1
	>- decrement c2 by 1
]
<< [ while c0
	>- decrement c1 by 1
	<- decrement c0 by 1
]
>. print c1
