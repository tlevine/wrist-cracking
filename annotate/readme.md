* Data read/write API is in Bottle.
* The rest is static pages, served by bottle so I don't have to deal with
    cross-domain requests.
* The "waveforms" are just images, and we scroll over them with CSS.

## Data read/write service
It looks like this

* `GET /!/`: List all participants
* `GET /!/:participant_id/`: List all trials for one participant.
* `GET /!/:participant_id/:trial_id`: List the flex and extend subtrials for
    the participant.
* `GET /random`: 
* `GET /`: Display the webpage; this is the only HTML.
