-- Название и продолжительность самого длительного трека.
SELECT track_name, track_duration 
FROM track 
WHERE  track_duration = (SELECT max (track_duration) FROM track);


-- Название треков, продолжительность которых не менее 3,5 минут.
SELECT track_name, track_duration 
FROM track 
WHERE  track_duration > '00:03:30';


-- Названия сборников, вышедших в период с 2018 по 2020 годы включительно.
SELECT collection_name 
FROM collection  
WHERE  release_year BETWEEN  '2018' AND '2020';


-- Исполнители, чьё имя состоит из одного слова.
SELECT name 
FROM artist 
WHERE name NOT LIKE '% %';

-- Название треков, которые содержат слова «мой» или «my».
SELECT track_name  
FROM track  
WHERE track_name LIKE '%мой%' OR track_name LIKE '%Мой%' OR track_name LIKE '%my%' OR track_name LIKE '%MY%';