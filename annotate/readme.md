Wrist cracking annotation website
====

I start with a CSV of EMG readings and an ogg video/audio file.

First, I synchronize the EMG with the video/audio. I know when the sync
button was pressed from the raw csv output, so the website marks that line
in the EMG graphs. I expect the button to be pressed exactly twice, so the
website only displays the first and last times. In the website, I play the
video and press a button to mark the points where the button was pressed
(and the light lights and speaker sounds). This updates the JSON file in the
backend (via the JSON API) with the locations.

Second, the website changes slightly. All streams now start when the sync
button was first pressed and end when the sync button was last pressed.
Now that they are synchronized, I watch the video and mark the point where
either the wrist cracked or almost-cracked (depending on the experiment
condition). This is also saved in the JSON backend.

After this, I get the data somewhere else and do something with them.

## Data read/write API
The data read/write service only has one HTML page. It is at `GET /`, and it is
static. This page calls the API. Ooohh "API" I'm so hip!!!

### Raw data
Raw data are mapped exactly to the filesystem structure, like this:

* `GET /!/:participant_id/:trial_id/:crack_or_almost/video.ogg`
* Data files if I render line plots on the browser
  * `GET /!/:participant_id/:trial_id/:crack_or_almost/audio.json`
  * `GET /!/:participant_id/:trial_id/:crack_or_almost/emg1.json`
  * `GET /!/:participant_id/:trial_id/:crack_or_almost/emg2.json`
* Images if I don't render line plots on the browser
  * `GET /!/:participant_id/:trial_id/:crack_or_almost/audio.png`
  * `GET /!/:participant_id/:trial_id/:crack_or_almost/emg1.png`
  * `GET /!/:participant_id/:trial_id/:crack_or_almost/emg2.png`

### Navigation
`GET /subtrials` lists all subtrials in JSON. They come out as a list of
dictionaries, where the dictionaries look like this:

    {
      "path": "/!/:participant_id/:trial_id/:crack_or_almost",
      "annotated": false
    }

`annotated` gets switched to `true` when the annotation below is done.

### Annotations
Annotations are at `/!/:participant_id/:trial_id/:crack_or_almost/`. `GET` and
`POST` are allowed. At first, `GET` returns something like this.

    {
      "crack_or_almost": null,
      "crack_time": null,
      "sync0": 0.00232,
      "sync1": 0.92749
    }

On a `POST`, the query string is expected to contain `crack_or_almost`,
`crack_time`, `sync0` and `sync1`. It validated and then saved to 
`/!/:participant_id/:trial_id/:crack_or_almost/index_:datetime.json`.

On subsequent a `GET`, the alphabetically highest `index_:datetime.json` is
displayed.

## Frontend
Anything that does not match the rules above is loaded as a static file from
the `frontend` directory.

The "waveforms" are just images, and we scroll over them with CSS. Or maybe
they're generated in Javascript. This would be nice because remove layers from
this program.


