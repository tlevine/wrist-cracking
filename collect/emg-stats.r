#!/usr/bin/Rscript --vanilla

filename <- commandArgs()[1]
emg <- read.csv(filename)
emg$sync_button_previous_state <- emg$sync_button_pressed[c(0, 1:(nrow(emg) - 1))]

emg.switch <- subset(emg, sync_button_pressed != sync_button_previous_state)

# Proportional sync points (0 to 1)
sync.points <- emg.switch[c(1, nrow(emg.switch)), 'millis()'] / max(emg$millis)

cat(sync.points[1])
cat(sync.points[2])