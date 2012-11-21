Why do wrists crack?
===
**Note well**: I am using documentation-driven development; I am writing in the
past tense, but not all of these things have happened yet.

## Wrist cracking
The wrist-cracking motion involves a range of wrist movements that culminate
with wrist extension.

### Hypothesis
I think that wrist cracking involves the simultaneous contraction of opposing
wrist muscle groups and that when the audible crack occurs, they are
temporarily relaxed to some degree.

## Physical measurement
I connected EMG to a wrist flexor and a wrist extensor, varying the
combination, and measured the output every centisecond. I used
[this thing]()
attached to a [Boarduino]().
This resulted in the following output, which was streamed to a file.

    date,                           extensor_emg, flexor_emg, sync_button_pressed
    2012-11-21 11:20:43.007000000,           123,        123, 0
    2012-11-21 11:20:43.008000000,           123,        123, 0
    2012-11-21 11:20:43.009000000,           123,        123, 0
    2012-11-21 11:20:43.010000000,           123,        123, 0

Simultaneously, video and audio of the hand were recorded.

### Synchronization procedure
At the beginning and end of the session, a button on the Arduino was pressed
for the synchronization procedure. The state of this button is recorded in
the output (`sync_button_pressed`). When the button is pressed, a light and
speaker are activated, so the signal also shows up in the video and audio.
Later, the video-audio and arduino output are manually synchronized based on
these signals.

## Experiment design
Each trial involved performing the wrist-cracking motion twice, once with the
goal of iliciting a crack and once with the goal of performing the same motion
except just barely avoiding making the crack. The order of these two subtrials
(crack and no crack) was randomized.

This experiment was run on one person (me) and one arm and only with one set
of muscles, so the design is quite simple. Differences in the processed EMG
variables (discussed later) between the crack and no-crack subtrials were
treated as one variable and were compared between the different muscles.
We thus have something like this.

    -----------------------------------------------------
        Var1 Difference  Var2 Difference        
        ---------------  --------------- 
    id  Flexor Extensor  Flexor Extensor
    --  ------ --------  ------ --------
     1     -30      -84                      .  .  .
     2      30      100
             .
             .
             .
    -----------------------------------------------------

## EMG variables/features
Before deciding which variables to extract, I made a web interface for marking
when the crack occurred. 
