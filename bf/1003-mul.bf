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
performing the multiplication
> [ while c1
	> [ while c2
		>+ increment c3 by 1
		>>+ increment c5 by 1
		# for if and else chains cells c9 = left c10 = right c11 = data holder
		copy c5 to c11 and initialize the conditional section
		[ while c5
			>>>>+ jump to c9 and increment it by 1
			>>+ jump to c11 and increment it by 1
			<<<<<<- jump to c5 and decrement it by 1
		]
		>>>>>[-]++++++++++ set c10 to 10
		> [ while c11
			<<<<<<+ jump to c5 and increment it by 1
			>>>>>>- jump to c11 and decrement it by 1
		]
		< jump to c10
		[ while c10
			<- jump to c9 and decrement c9 by 1
			>- jump to c10 and decrement c10 by 1
		]
		+ increment c10 by 1
		< jump to c9 (c9 is going to be 0 if it is equal to c10)
		[ while c9 is not equal to c10 (the if condition failed)
			# begin else condition's body
			# end else condition's body
			>- jump to c10 and decrement it to 0 (prevents the if section from executing)
			< jump to c9
			[-] decrement c9 till it is 0 (breaks this loop)
		]
		> jump to c10
		[ while c10 is equal to c9 (the if condition passed)
			# begin if condition's body
			<<<<+ jump to c6 and increment it by 1
			<[-] set c5 to 0 (units should start from 0 if we've reached a ten)
			# end if condition's body
			>>>>> jump to c10
			[-] decrement c10 till it is 0 (breaks this loop)
		]
		<<<<<<+ increment c4 by 1
		<<- decrement c2 by 1
	]
	>> [ while c4
		<<+ increment c2 by 1
		>>- decrement c4 by 1
	]
	<<<- decrement c1
]
c3 contains the final product
c5 contains the number of units
c6 contains the number of tens
converting the tens and units to character codes
>>>>> jump to c6
copy c6 to c11 and initialize the conditional section
[ while c6
	>>>+ jump to c9 and increment it by 1
	>>+ jump to c11 and increment it by 1
	<<<<<- jump to c6 and decrement it by 1
]
>>>>[-] set c10 to 0
> [ while c11
	<<<<<+ jump to c6 and increment it by 1
	>>>>>- jump to c11 and decrement it by 1
]
< jump to c10
[ while c10
	<- jump to c9 and decrement c9 by 1
	>- jump to c10 and decrement c10 by 1
]
+ increment c10 by 1
< jump to c9 (c9 is going to be 0 if it is equal to c10)
[ while c9 is not equal to c10 (the if condition failed)
	# begin else condition's body
	<<<<<<<< jump to c1
	++++++++ set c1 to 8
	[ while c1
		>>>>>++++++ jump to c6 and increment it by 6
		<<<<<- jump to c1 and decrement it by 1
	]
	# end else condition's body
	>>>>>>>>>- jump to c10 and decrement it to 0 (prevents the if section from executing)
	< jump to c9
	[-] decrement c9 till it is 0 (breaks this loop)
]
> jump to c10
[ while c10 is equal to c9 (the if condition passed)
	# begin if condition's body
	# end if condition's body
	[-] decrement c10 till it is 0 (breaks this loop)
]
<<<<<<<<< jump to c1
++++++++ set c1 to 8
[ while c1
	>>>>++++++ jump to c5 and increment it by 6
	<<<<- jump to c1 and decrement it by 1
]
printing the character codes
>>>>>. jump to c6 (tens) and print c6
<. jump to c5 (units) and print c5
<<<<
++++++++++. set c1 to 10 (newline character code) and print c1
