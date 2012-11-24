* Data read/write API is in Bottle.
* The rest is static pages, served by bottle so I don't have to deal with
    cross-domain requests.
* The "waveforms" are just images, and we scroll over them with CSS.

## Data read/write service
It looks like this.

### Assets
Assets are mapped exactly to the filesystem structure, and they look like this:

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
`GET /subtrials` lists all subtrials in JSON. You can pass `participant_id`,
`trial_id` and `crack_or_almost` in the querystring to limit this.

Navigation:

* `GET /`: Display the webpage; this is the only HTML. 

Annotations are at `/!/:participant_id/:trial_id/:crack_or_almost/`. `GET` and
`POST` are allowed. At first, `GET` returns something like this.

    {
      "crack_or_almost": null,
      "crack_time": null
    }

On a `POST`, the JSON body is validated and then saved to 
`/!/:participant_id/:trial_id/:crack_or_almost/index_:datetime.json`.

On subsequent a `GET`, the alphabetically highest `index_:datetime.json` is
displayed.
