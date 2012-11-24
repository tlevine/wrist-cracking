#!/usr/bin/env python
import os
from bottle import route, run, template

@route('/!/:file')
def index(file):
    return os.path.join(*file.split('/'))
    return os.environ['WRIST_RAW']
    return template('<b>Hello {{file}}</b>!', file = file)

run(host='localhost', port=8080)
