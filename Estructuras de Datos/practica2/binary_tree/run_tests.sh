#!/bin/bash
#Version: 1.0
#Version: 1.1
#- Fijado error al comprobar test que lanzan excepciones y termian
#  con EXIT_FAILURE. A partir de ahora se comprueba la salida siempre.

set -e

if [ "x$1" == "x" ] || [ ! -x "$1" ]; then
	echo "uso: $0 <program> [test dir]"
        echo "Version: 1.0"
        exit 1
fi

TEST_DIR="./tests"
if [ "x$2" != "x" ] ; then
   TEST_DIR="${2}"
fi

prog="$1" 

PASS=0
TOTAL=0

for t in ${TEST_DIR}/?? ; do
        TMPFILE=/tmp/ed_test_$$_${RANDOM}
	TOTAL=$(( $TOTAL + 1 ))
        set +e
        $prog $t >& ${TMPFILE}
	RETCODE="$?"
	set -e
	echo -n "test $t : "
	        YOUR_OUTPUT="$( cat ${TMPFILE} )"
		EXPECTED_OUTPUT="$( cat ${t}.a )"
		set +e
	        DIFF=$( diff $TMPFILE ${t}.a )        
		set -e
		if [ "${YOUR_OUTPUT}" != "${EXPECTED_OUTPUT}" ]; then
			echo " Fail!"
	                echo -e "\t Expected:\n[${EXPECTED_OUTPUT}]"
	                echo -e "\t Your output:\n[${YOUR_OUTPUT}]"
	                echo -e "\t Differences:\n[${DIFF}]"
		else
			PASS=$(( $PASS + 1 ))
			echo " Success!"
		fi	
done

echo "You pass $PASS of $TOTAL tests."
if [ "$PASS" == "$TOTAL" ]; then
	exit 0
else
	exit 1
fi

