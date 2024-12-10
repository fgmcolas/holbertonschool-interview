#!/usr/bin/node
const request = require('request');
const movieId = process.argv[2];
if (!movieId) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}
const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}/`;
request(apiUrl, (error, response, body) => {
  if (error) {
    console.error('Error fetching data:', error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Error: Received status code ${response.statusCode}`);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;
  const fetchCharacterName = (url, callback) => {
    request(url, (err, res, charBody) => {
      if (err) {
        callback(err, null);
        return;
      }
      const charData = JSON.parse(charBody);
      callback(null, charData.name);
    });
  };

  const printCharacters = (index) => {
    if (index >= characters.length) {
      return;
    }
    fetchCharacterName(characters[index], (err, name) => {
      if (err) {
        console.error('Error fetching character:', err);
      } else {
        console.log(name);
        printCharacters(index + 1);
      }
    });
  };

  printCharacters(0);
});
