SELECT title FROM movies, stars, ratings, people WHERE movies.id = stars.movie_id AND stars.person_id = people.id AND ratings.movie_id = movies.id AND name = "Chadwick Boseman" ORDER BY rating DESC LIMIT 5;