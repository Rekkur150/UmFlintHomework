//Compares two string to see how similar two strings are.
module.exports.LevenshteinDistance = function(string1, string2) {

  var str1 = string1.toLowerCase();
  var str2 = string2.toLowerCase();

  var subcost;
  var value;
  var matrix = [];

  //Creates a matrix with x,y being the strings. From there they compare from previous iteration and current iteration to see how many edits have been made to the string to make them the same
  for (var i = 0; i < string1.length + 1; i++) {

    matrix.push([]);
    for (var j = 0; j < string2.length + 1; j++) {
      if (i == 0) {
        matrix[i].push(j);
      } else if (j == 0) {
        matrix[i].push(i);
      } else {

        if (str1[i-1] == str2[j-1]) { //If the characters are the same then there is no cost, if there is a cost they will be incremented by one.
          subcost = 0;
        } else {
          subcost = 1;
        }

                        //Magic, basic idea is that if either x or y direction is same then there will be increment in the difference counter, if there is a character difference then it is incremented.
        value = Math.min(matrix[i-1][j] + 1, matrix[i][j-1] + 1, matrix[i-1][j-1] + subcost)

        matrix[i].push(value);
      }
    }
  }

  return matrix[string1.length][string2.length]; //Gets the minimum amount of edits to make the strings the same. 
}

//Checks words to see how closely they match to other words.
module.exports.wordCheck = function(string) {
  var words = ["hello", "pizza", "cheese","mitch", "twitch", "cake"];
  var lowest = 9999999999999;
  var index = 0;
  for (var i = 0; i < words.length; i++) {
    var compare = this.LevenshteinDistance(words[i],string)
    if (compare < lowest) {
      lowest = compare;
      index = i;
    }
  }

  if (lowest > 2) {
    return "I don't know that word"
  } else {
    return words[index];
  }
}
