#!/bin/bash

# Author: Guglielmo Palaferri

if [[ $# -ne 1 ]]; then
	echo "Usage: $0 CONFIG_NAME"
	exit 1
fi

CONFIG_NAME=$1

adb logcat -c

watch -n 66 'adb shell am force-stop gullp.androidotv; adb shell am start -n "gullp.androidotv/gullp.androidotv.MainActivity"' &>/dev/null &

adb logcat gullp.androidotv:D | egrep --line-buffered "Execution Time|Computational Frame Rate" >> results_${CONFIG_NAME}.txt

