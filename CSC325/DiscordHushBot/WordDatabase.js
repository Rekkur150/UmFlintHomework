var mysql = require("mysql");
var charRemoveFromStrings = ["'",'"','!',',','.','!','~',]

//Connects to mysql server
var con = mysql.createConnection({
  host:"127.0.0.1",
  user:"zachary",
  password:"Zh@1004948"
});
//
//Makes sure that I know if there is an error connecting to the basebase.
con.connect(function(err) {
  if (err) throw err;
  console.log("Connected!");
});

//Returns a words used to flagged ratio, using a call back. So we need to pass a function
//Example use getWordFlaggedRatio("the", function(ratio) { console.log(ratio)});
module.exports.getWordFlaggedRatio = function(string,callback) {
  var str = this.cleanWord(string);
  con.query("SELECT * FROM words.common_words WHERE word = ?;", [str], function(err,result) {
    if (err) throw err;

    if (result.length != 0) {
      return callback(result[0].flagged/(result[0].used+1));
    } else {
      return 0;
    }
  });
}

//Add a string to the database
module.exports.addString = function(string, callback = ()=>{}) {
  var str = this.cleanWord(string);   //Clean the string of puntuation, and numbers
  var words = str.match(/\S+/g) || [];         //Split string into an array of words;

  for (var i = 0; i < words.length; i++) {
    con.query("call words.addWord(?);", [words[i]], function(err,result) { //Call a custom made mysql procedure that adds both the word and the connections of that word
      // if (err) throw err;
    });
    if (i != 0) {
      con.query(" call words.addWords(?,?);", [words[i-1],words[i]], function(err,result) { //Call a custom made mysql procedure that adds the word to the database.
        // if (err) throw err;
      });
    }
  }
  return "Operation Completed";
}

//Get the ratio between a set of words flagged and used, similar to how getWordFlaggedRatio, just an extra string
module.exports.getWordsFlaggedRatio = function(string1,string2, callback) {
  var str1 = this.cleanWord(string1);
  var str2 = this.cleanWord(string2);
  con.query("SELECT * FROM words.word_order WHERE preword = ? AND postword = ?;", [str1,str2], function(err,result) {
    console.log(err);
    if (err) throw err;
    if (result.length != 0) {
      console.log(result);
      return callback(result[0].flagged/(result[0].used+1));
    } else {
      return 0;
    }
  });
}

//Get the total amount of words used in the database.
module.exports.getTotalWordsUsed = function(callback) {
  con.query("SELECT sum(USED) AS sum FROM words.common_words", function(err,result) {
    if (err) throw err;
    if (result.length != 0) {
        return callback(result[0].sum);
    } else {
      return 0;
    }
  })
}

//Gets the total amount of combined words that are stored in the database.
module.exports.getTotalOrderWordsUsed = function(callback) {
  con.query("SELECT sum(USED) AS sum FROM words.word_order", function(err,result) {
    if (err) throw err;
    if (result.length != 0) {
      return callback(result[0].sum);
    } else {
      return 0;
    }
  })
}

//Gets the total flagged of every words.
module.exports.getTotalWordsFlagged = function(callback) {
  con.query("SELECT sum(FLAGGED) AS sum FROM words.common_words", function(err,result) {
    if (err) throw err;
    if (result.length != 0) {
      return callback(result[0].sum);
    } else {
      return 0;
    }
  })
}

//Gets the total flagged of order words.
module.exports.getTotalOrderWordsFlagged = function(callback) {
  con.query("SELECT sum(FLAGGED) AS sum FROM words.word_order", function(err,result) {
    if (err) throw err;
    if (result.length != 0) {
      return callback(result[0].sum);
    } else {
      return 0;
    }
  })
}

//Cleans the words so they are ready for the database.
module.exports.cleanWord = function(string) {
  var str = string.toLowerCase();
  str = str.replace(/[^a-zA-Z ]/g,"");

  return str;
}
