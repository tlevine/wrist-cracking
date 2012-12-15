#!/usr/bin/env python
import os
import json
import datetime
from bottle import get, post, run, static_file, Bottle, request, response

@get('/!/:participant_id/:trial_id/:crack_or_almost')
def get_annotation(participant_id, trial_id, crack_or_almost):
    subtrial_dir = os.path.join(os.environ['WRIST_RAW'], participant_id, trial_id, crack_or_almost)
    annotation_files = list(filter(lambda f: 'index' in f, os.listdir(subtrial_dir)))
    if len(annotation_files) > 0:
        return static_file(sorted(annotation_files)[-1], subtrial_dir)
    else:
        return {
            "crack_or_almost": None,
            "crack_time": None,
        }

@post('/!/:participant_id/:trial_id/:crack_or_almost')
def post_annotation(participant_id, trial_id, crack_or_almost):

    if not {'crack_or_almost', 'crack_time'}.issubset(request.params):
        response.status = 400
        return {'error': 'You must specify both "crack_or_almost" and "crack_time"'}

    annotation_data = {
        "crack_or_almost": bool(request.params.crack_or_almost),
        "crack_time": float(request.params.crack_time),
    }

    subtrial_dir = os.path.join(os.environ['WRIST_RAW'], participant_id, trial_id, crack_or_almost)
    annotation_filename = 'index-' + datetime.datetime.now().isoformat() + '.json'
    annotation_file = open(os.path.join(subtrial_dir, annotation_filename), 'w')
    json.dump(annotation_data, annotation_file)
    annotation_file.close()

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
        if not os.path.isdir(participant_path):
            continue
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
                web_path = '/!/' + '/'.join([participant, trial, subtrial]) + '/'

                out.append({
                    "path": web_path,
                    "annotated": annotated,
                })
    return json.dumps(out)

@get('/')
@get('/<filepath:path>')
def frontend(filepath = 'index.html'):
    """
    Serve the raw data.
    You'd request something like `/!/002/018/almost/video.ogg`.
    """
    frontend_dir = os.path.join(os.environ['WRIST_ROOT'], 'annotate', 'frontend')
    return static_file(filepath, frontend_dir)

run(host='localhost', port=8080)
