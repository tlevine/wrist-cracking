#!/usr/bin/env python
import os
import json
from bottle import get, post, run, static_file, Bottle, request, response

@get('/!/:participant_id/:trial_id/:crack_or_almost')
def annotation(participant_id, trial_id, crack_or_almost):
    subtrial_dir = os.path.join(os.environ['WRIST_RAW'], participant_id, trial_id, crack_or_almost)
    annotation_files = list(filter(lambda f: 'index' in f, os.listdir(subtrial_dir)))
    if len(annotation_files) > 0:
        return static_file(sorted(annotation_files)[-1], subtrial_dir)
    else:
        return {
            "crack_or_almost": None,
            "crack_time": None,
        }

@get('/!/<filepath:path>')
def raw_data(filepath):
    """
    Serve the raw data.
    You'd request something like `/!/002/018/almost/video.ogg`.
    """
    return static_file(filepath, os.environ['WRIST_RAW'])

@get('/subtrials')
def navigation():
    'List subtrials in JSON. They come out as a list of dictionaries.'
    response.set_header('Content-Type', 'application/json; charset=utf-8')
    out = []
    for participant in os.listdir(os.environ['WRIST_RAW']):
        participant_path = os.path.join(os.environ['WRIST_RAW'], participant)
        for trial in os.listdir(participant_path):
            trial_path = os.path.join(participant_path, trial)
            for subtrial in os.listdir(trial_path):

                # Is it annotated?
                subtrial_path = os.path.join(trial_path, subtrial)
                for filename in os.listdir(subtrial_path):
                    if 'index' in filename:
                        annotated = True
                        break
                else:
                    annotated = False

                # The path
                web_path = '/!/' + '/'.join([participant, trial, subtrial] + '/')

                out.append({
                    "path": web_path,
                    "annotated": annotated,
                })
    return json.dumps(out)

run(host='localhost', port=8080)
