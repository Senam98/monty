initializing c0 to 0's character code
>++++++++ set c1 to 8
[ while c1
	<++++++ increment c0 by 6
	>- decrement c1 by 1
]
, c1 = getchar()
>, c2 = getchar()
<< [ while c0
	>- decrement c1 by 1
	>- decrement c2 by 1
	<<- decrement c0 by 1
]
> [ while c1
	> [ while c2
		>+ increment c3 by 1
		>+ increment c4 by 1
		<<- decrement c2 by 1
	]
	>> [ while c4
		<<+ increment c2
		>>- decrement c4
	]
	<<<- decrement c1
]
c3 contains the final product
initializing c0 to 0's character code
++++++++ set c1 to 8
[ while c1
	<++++++ add 6 to c0
	>- decrement c1 by 1
]
< [ while c0
	>>>+ increment c3 by 1
	<<<- decrement c0 by 1
]
>>>. print c3
