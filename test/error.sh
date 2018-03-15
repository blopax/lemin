	#!/bin/bash
	rm -rf error.txt
	list_file=`find . -name "map*"`
	for file in $list_file
	do
		./lem-in < $file | ./error $file
	done
