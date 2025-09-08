CREATE TABLE IF NOT EXISTS genre (
	id SERIAL PRIMARY KEY,
	title_genre VARCHAR(80) UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS artist (
	id SERIAL PRIMARY KEY,
	name VARCHAR(40) NOT NULL
);

CREATE TABLE IF NOT EXISTS genre_artist (
	id_genre INTEGER REFERENCES genre(id),
	id_artist INTEGER REFERENCES artist(id),
	CONSTRAINT pk PRIMARY KEY (id_genre, id_artist)
);

CREATE TABLE IF NOT EXISTS albums (
	id SERIAL PRIMARY KEY,
	album_title VARCHAR(80) NOT NULL,
	release_year INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS artist_album (
	id_artist INTEGER REFERENCES artist(id),
	id_album INTEGER REFERENCES albums(id),
	CONSTRAINT ar_al PRIMARY KEY (id_artist, id_album)
);

CREATE TABLE IF NOT EXISTS track (
	id SERIAL PRIMARY KEY,
	track_name VARCHAR(80) NOT NULL,
	id_albums INTEGER NOT NULL REFERENCES albums(id),
	track_duration TIME NOT NULL
);

CREATE TABLE IF NOT EXISTS collection (
	id SERIAL PRIMARY KEY,
	collection_name VARCHAR(80) NOT NULL,
	release_year INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS track_collection (
	id_track INTEGER REFERENCES track(id),
	id_collection INTEGER REFERENCES collection(id),
	CONSTRAINT tr_co PRIMARY KEY (id_track, id_collection)
);