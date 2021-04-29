var database = require("./WordDatabase.js");

module.exports.checkStringForNaughty = function(string) {

  database.addString(string, (result) => {

    console.log(result);

    var words = string.match(/\S+/g) || [];         //Split string into an array of words;
    var ratios = [];

    for (var i = 1; i < words.length; i++) {
      database.getWordsFlaggedRatio(words[i-1], words[i], (result)=> {
        ratios.push(result);
        console.log(result);
      })
    }
  });
}


// this.CheckStringForNaughty("Hello World!");

this.checkStringForNaughty('the', 'table', (result)=> {
  console.log(result);
})

this.checkStringForNaughty('i', 'table', (result)=> {
  console.log(result);
})
