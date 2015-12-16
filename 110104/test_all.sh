for i in 4 5
do
	./a.out < in$i >tmp$i
	diff -c out$i tmp$i
	if [ $? -eq 0 ]
	then
		echo "$i is ok"
	else
		echo "$i is wrong"
	fi
done
