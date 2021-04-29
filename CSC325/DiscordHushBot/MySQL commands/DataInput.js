// var sql = require("./WordDatabase.js");
//
// //Used to input alot of data in to the database.
// module.exports.main = function() {
//
//   sql.getTotalWordsUsed(function(result) {
//     console.log("Returned: " + result);
//   });
//
//   var lineReader = require('line-reader');
//   lineReader.eachLine("input.txt", function(line) {
//     var lines = line.split(/[.;]/);
//
//     for (var i = 0; i < lines.length; i++) {
//       //console.log(lines[i]);
//       sql.addString(lines[i]);
//     }
//   })
//
//   sql.getTotalWordsUsed(function(result) {
//     console.log("Returned: " + result);
//   });
// }
