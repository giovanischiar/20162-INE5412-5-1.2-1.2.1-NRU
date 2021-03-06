#!/bin/bash

#load common script and check programs
. common_script.sh
check_program g++
get_source_files cpp C
#compile
g++ -o vpl_program -g -O0 $SOURCE_FILES -lm -lutil -lgtest -std=c++11 -Wall
if [ -f vpl_program ] ; then
	cat common_script.sh > vpl_execution
	chmod +x vpl_execution
	if [ "$(command -v ddd)" == "" ] ; then
		check_program gdb
		echo "gdb vpl_program" >> vpl_execution
	else
		echo "ddd --quiet --gdb -geometry 800x600 vpl_program &>/dev/null" >> vpl_execution
		mkdir .ddd
		mkdir .ddd/sessions
		mkdir .ddd/themes
		cat >.ddd/init <<END_OF_FILE
Ddd*splashScreen: off
Ddd*startupTips: off
Ddd*suppressWarnings: on
Ddd*displayLineNumbers: on
Ddd*saveHistoryOnExit: off

! DO NOT ADD ANYTHING BELOW THIS LINE -- DDD WILL OVERWRITE IT
END_OF_FILE
		mv vpl_execution vpl_wexecution
	fi
fi