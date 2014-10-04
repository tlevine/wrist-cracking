#!/bin/sh

# Read the arduino serial output.
# https://wiki.archlinux.org/index.php/Arduino#Accessing_serial

# Arduino serial port
SERIAL_PORT=/dev/ttyACM0

# Preparing
stty -F $SERIAL_PORT cs8 9600 ignbrk -brkint -imaxbel -opost -onlcr -isig -icanon -iexten -echo -echoe -echok -echoctl -echoke noflsh -ixon -crtscts

# Sending commands through Terminal without new line after command
# echo -n > /dev/ttyACM0

# Reading what your Arduino has to tell you 
cat /dev/ttyACM0
