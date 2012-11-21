#!/bin/sh

if [ "$#" != '1' ]; then
  echo "USAGE: $0 [output file]"
  exit 1
fi

outfile="$1"

gst-launch-0.10 -e v4l2src ! 'video/x-raw-yuv,width=320,height=240, framerate=30/1' ! ffmpegcolorspace ! x264enc ! mp4mux ! filesink location="$outfile"
