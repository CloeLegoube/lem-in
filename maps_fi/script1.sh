for var1 in $( cat test_cloe )
do
	var2=$(./lem < $var1) ; if [ -n "$var2" ]; then echo $var1; fi
done
