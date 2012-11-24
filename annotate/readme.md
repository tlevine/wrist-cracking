* Data read/write API is in Bottle.
* The rest is static pages, served by bottle so I don't have to deal with
    cross-domain requests.
* The "waveforms" are just images, and we scroll over them with CSS.

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
      "crack_time": null
    }

On a `POST`, the query string is expected to contain `crack_or_almost` and
`crack_time`. It validated and then saved to 
`/!/:participant_id/:trial_id/:crack_or_almost/index_:datetime.json`.

On subsequent a `GET`, the alphabetically highest `index_:datetime.json` is
displayed.
