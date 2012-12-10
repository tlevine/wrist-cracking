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
