	#!/bin/bash
	rm -rf error.txt
	rm -rf leaks
	list_file=`find . -type f -name "map*"`
	echo "\033[0;35mBegin of unvalid map\033[0m\n\n" >> leaks
	for file in $list_file
	do
		RETVAL=`valgrind --log-fd=1 ../lem-in < valid_map/valid_map01 | grep "definitely lost"`
		LEAK=`echo $RETVAL | cut -d : -f 2 | awk '{print $1}'`
		../lem-in < $file | ./error $file
		if [ "$LEAK" != "0" ]
		then
			echo "Leaks in $file\n$RETVAL\n" >> leaks
		fi
	done
