CREATE TABLE annotation (
  -- The primary key comes from the experiment design.
  participant_id INTEGER NOT NULL,
  trial_id INTEGER NOT NULL,
  crack BOOLEAN NOT NULL,

  -- The annotations come from the web interface

  -- This is the time when a crack happened (crack subtrials)
  -- or when it would have happened (no-crack subtrials)
  crack_time DATETIME,

  -- This should equal [crack]; it's a check.
  crack_annotated BOOLEAN,

  UNIQUE(participant_id, trial_id, crack)
);
