#!/bin/sh

if [ "$#" != '1' ]; then
  echo "USAGE: $0 [output file]"
  exit 1
fi

outfile="$1"

# http://gstreamer-devel.966125.n4.nabble.com/how-to-create-a-pipeline-to-record-video-from-camera-td3134399i20.html
gst-launch-0.10 -e v4l2src ! 'video/x-raw-yuv,width=320,height=240, framerate=30/1' ! ffmpegcolorspace ! x264enc ! mp4mux ! filesink location="$outfile"
