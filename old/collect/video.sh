#!/bin/sh

outfile="$1"

if [ "$#" != '1' ]; then
  echo "USAGE: $0 [output file]"
  exit 1
fi

if ! echo "$outfile" | grep '\.ogg' > /dev/null; then
  echo 'Output file should end in ".ogg".'
  exit 2
fi

# http://wiki.oz9aec.net/index.php/Gstreamer_cheat_sheet

# http://gstreamer-devel.966125.n4.nabble.com/how-to-create-a-pipeline-to-record-video-from-camera-td3134399i20.html
# gst-launch-0.10 -e v4l2src ! 'video/x-raw-yuv,width=320,height=240, framerate=30/1' ! \
#   ffmpegcolorspace ! x264enc ! mp4mux ! filesink location="$outfile"

# http://noraisin.net/diary/?p=40
gst-launch-0.10 v4l2src ! timeoverlay halign=right valign=top ! clockoverlay time-format="%Y-%m-%d %H:%M:%S" halign=left valign=top ! \
  video/x-raw-yuv,width=640,height=480 ! ffmpegcolorspace ! theoraenc ! oggmux name=mux ! filesink location="$outfile" pulsesrc ! audioconvert ! vorbisenc ! mux.

# The audio seems fine, but the video seems to lag.
# Adjusting width, height and framerate seems to help.
