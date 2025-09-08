INSERT INTO artist (name)
VALUES('Helavisa'), ('Yuri Melisov'), ('Nikolai Rastorguev'), ('Yuko Suzuhana');

INSERT INTO genre (title_genre)
VALUES ('rock'), ('metal'), ('j-pop'), ('folk music');

INSERT INTO albums (album_title, release_year)
VALUES ('Ребята нашего полка', 2004), ('Князь Владимир', 2004), ('Алхимия', 2015), ('Всадник из льда', 2011), ('Сокровище Энии', 2014), ('Tokyo Singing', 2020);

INSERT INTO track (track_name, id_albums, track_duration)
VALUES ('Солдат', 1, '00:05:08'), ('Ты неси меня река', 1, '00:03:37'), ('Может знает лес', 2, '00:03:20'), 
	('Об устройстве небесного свода', 3, '00:03:48'),('Радость моя', 3, '00:03:34'),('Смерти нет', 5, '00:05:05'),
	('Прощай, Мой Дом', 4, '00:04:20'),('Calling', 6, '00:04:30'),('Sun Wheel', 6, '00:04:26');

INSERT INTO collection (collection_name, release_year)
VALUES ('Защитникам Отечества', 2010), ('Любэ И Мельница', 2004), ('Эпидемия и Мельница', 2014), ('Trajectory',2020);

INSERT INTO artist_album (id_artist, id_album)
VALUES (1,2), (1,3), (1,5), (2,4), (2,5), (3,1), (3,2), (4,6);

INSERT INTO genre_artist (id_genre, id_artist)
VALUES (1,1), (1,4), (2,2), (3,4), (4,1), (4,3);

INSERT INTO track_collection (id_collection, id_track)
VALUES (1,1), (1,2), (2,3), (3,6), (4,8), (4,9);