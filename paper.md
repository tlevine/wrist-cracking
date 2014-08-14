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
I connected electromyograph (EMG) electrodes to a wrist flexor and a wrist extensor, varying the
combination, and measured the output every centisecond. I used
[this thing]()
attached to a [Boarduino]().
This resulted in the following sort of output.

    date,                           extensor_emg, flexor_emg, sync_button_pressed
    2012-11-21 11:20:43.007000000,           123,        123, 0
    2012-11-21 11:20:43.008000000,           123,        123, 0
    2012-11-21 11:20:43.009000000,           123,        123, 0
    2012-11-21 11:20:43.010000000,           123,        123, 0

It was not encoded in this format, however; I synchronously recorded
EMG, video, and audio all at the same time from the same computer.
The EMG, video, and audio data were all stored in a single video container file.

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
        Before motion    After motion
        ---------------  --------------- 
    id  Flexor Extensor  Flexor Extensor
    --  ------ --------  ------ --------
     1     -30      -84                      .  .  .
     2      30      100
     .       .        .
     .       .        .
     .       .        .
    -----------------------------------------------------

## EMG variables/features
The EMG processing was quite simple. As mentioned above, I used a process
that resulted in two numbers per trial, one for before the motion and one
for after the motion.

The exact process is that I calculated root mean square of the EMG signal
for before and after the wrist motion (regardless of whether the motion
involved a crack). Based on the following graphs of the EMG activity,
I'd say that this simple model is just fine.

It took me the longest time to understand what root mean
square was; in case you are like me in this way, I mention that root mean
square is the same thing as a population standard deviation. In case you
don't remember what the difference is between a population standard deviation
and a sample standard deviation, just think of it as a standard deviation.
And if you don't know what standard deviation is, think of root mean square
as the average magnitude of the electrical signal, or the average amplitude
of a wave.

## Determining the point of motion
