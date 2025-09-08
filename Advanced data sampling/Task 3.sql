
-- Количество исполнителей в каждом жанре.
SELECT title_genre, count(*)
FROM genre g
LEFT JOIN genre_artist ga ON g.id = ga.id_genre 
LEFT JOIN artist a ON a.id = g.id 
GROUP BY title_genre
ORDER BY count(*) DESC;


--Количество треков, вошедших в альбомы 2019–2020 годов.
SELECT release_year, count(*) 
FROM albums a
LEFT JOIN track t  ON a.id = t.id_albums  
WHERE release_year  BETWEEN '2019' AND '2020'
GROUP BY release_year
ORDER BY count(*) DESC;


--Средняя продолжительность треков по каждому альбому.
SELECT album_title , avg(track_duration)
FROM albums a 
LEFT JOIN track t  ON A.id = t.id_albums 
GROUP BY album_title 
ORDER BY avg(track_duration)  DESC;


--Все исполнители, которые не выпустили альбомы в 2020 году.
SELECT name 
FROM artist a 
LEFT JOIN artist_album aa ON a.id = aa.id_artist 
LEFT JOIN albums a2 ON aa.id_album  = a2.id
WHERE release_year != '2020'
GROUP BY name;


--Названия сборников, в которых присутствует конкретный исполнитель
SELECT collection_name 
FROM collection c 
LEFT JOIN track_collection tc ON c.id = tc.id_collection 
LEFT JOIN track t ON tc.id_track = t.id 
LEFT JOIN albums a ON t.id_albums = a.id 
LEFT JOIN artist_album aa ON aa.id_album = a.id 
LEFT JOIN artist a2 ON aa.id_artist = a2.id 
WHERE name = 'Helavisa'
GROUP BY collection_name;
