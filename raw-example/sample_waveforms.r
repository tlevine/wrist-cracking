#!/usr/bin/env Rscript

# Generate a waveform image
library(ggplot2)
emg <- read.table('http://www.physionet.org/physiobank/database/emgdb/emg_healthy.txt', col.names = c('time', 'reading'), stringsAsFactors = F)
emg$reading <- as.numeric(emg$reading)

p <- ggplot(emg) + aes(x = time, y = reading) + geom_line()   

png('waveform.png', width = 2000, height = 200)
p + ylim(-1, 1)  
dev.off()
