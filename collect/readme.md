Run `collect [dir]` to collect everything into one directory. A good place to
put this is `raw/[participant_id]/[trial_id]`. The following files will be
created in the directory

* `video.ogg`: Video and audio
* `emg1.csv`: Readings from the first electrode
* `emg2.csv`: Readings from the second electrode

You need `gstreamer0.10-base-plugins` for the `timeoverlay` element.

## How to synchronize
Is this good enough? Run some manual tests to find out.

    date --rfc-3339 ns && ./video.sh /tmp/foo.ogg

Pick out the first frame

    ffmpeg -i foo.ogg -s 320?240 -vframes 1 swing.jpg 

Hmm actually I think this is how I do it.

1. The arduino records milliseconds since it turned on (`millis`).
2. I push the synchronization button on the arduino. It triggers a bright
    light and a loud noise. This is recorded in the Arduino serial CSV as
    the `sync_button_pressed` column. Then you run the trial, and then you
    press this sync button again.
3. In a web interface, EMG is displayed starting and ending at the sync
    points, but the full audio and video recordings are shown. A person
    manually marks these start and end points in the video/audio.
4. Now that these are marked, the web interface truncates the video/audio
    appropriately, and you can mark the wrist (almost) crack point.
