SELECT movies.title, ratings.rating FROM movies JOIN ratings ON movies.id = ratings.movie_id AND movies.year = 2010 AND ratings.rating <> "NULL" ORDER BY ratings.rating DESC, movies.title;
