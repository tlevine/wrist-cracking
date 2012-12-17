#!/bin/sh

tmp=$(mktemp)
cat /dev/stdin | sed '/^$/d' > $tmp
Rscript --vanilla emg-stats.r $tmp
