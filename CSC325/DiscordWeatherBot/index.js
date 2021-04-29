const Discord = require("discord.js"); 	//Requires discord API bot code
const Request = require("request");		//Requires request, which is used for API calls.
const Fs = require("fs");

//Discord Variables
const token = ''; //Allows us to connect to the discord bot.
const bot = new Discord.Client(); //Creates a new bot object

//Openweathermap Variables
const openWeatherAPIKey = ""; //API key for openweather
const openWeatherURL = "http://api.openweathermap.org/data/2.5/weather?q="; //Begginning URL for API

//Functions
//--------------------------------------------------

//Description: Gets the weather for a particular location;
//Input: Arguments of the command, along with the msg object
//Arguments [0] = "!weather", [1] = "cityname"
var weather = function(arguments, msg) {
	var city = "";

	//Deals with cities that have names that contain spaces. It combines the arguments and puts spaces between them. Example ["Hello","World"] would become "Hello world"
	for (var i = 1; i < arguments.length; i++) {
		city += arguments[i];
		city += " ";
	}

	//Calls of API of openweather, with the correct API key along with the name of the city.
	Request(openWeatherURL + city + "&units=imperial&APPID=" + openWeatherAPIKey, function(error, response, body) {
		if (!error && response.statusCode == 200) {
			var weatherData = JSON.parse(body); //Data to JSON object.
			//For more information on what is returned from openWeather (https://openweathermap.org/current#one)
			msg.reply("\n" + weatherData.name + " is currently experiencing **" + weatherData.weather[0].description + "**\n" +
				"The Current Tempature is **" + weatherData.main.temp + "°F** with a high of **" +
				weatherData.main.temp_max + "°F** and a low of **" + weatherData.main.temp_min + "°F**\n" +
				"The humidity is **" + weatherData.main.humidity + "%**");
				//Takes the information from the JSON object and sends a reply of weather information to the calling user.

			//Sends a link to the user where it thinks the location of the city, embed is a discord object reference discord documentation for more information
			msg.reply({embed:{
				title:"City Coordinates [" + weatherData.coord.lat + "," + weatherData.coord.lon + "]",
				url:"https://www.google.com/maps/@" + weatherData.coord.lat + "," + weatherData.coord.lon + ",12z"}});

		} else {

			//Checks to see error that has occured, if it is one specified then reply with specified error Message
			//If its an unepected error, reply with error message

			var errorMessage = JSON.parse(body); //Turns error body into a JSON file.
			switch (errorMessage.cod) {
				case "404": //City is not avaible
					msg.reply("I am sorry that is not a valid location");
					break;
				case "429": //Exceeded max API calls to openWeather (MAX with a free openWeather account is 60 per hour)
					msg.reply("There has been too many attempts, please try again later");
					break;
				default:	//Generic Error Message
					msg.reply("An error:" + errorMessage.message);
			}
		}
	});
}


//Description: Helps the user get information about commands
//Input: Arguments of the commands, and the msg object
var man = function(arguments, msg) {
	switch (arguments[1]) {
		case "weather":
			msg.reply("Usage: '!weather [name_of_city]' or '!weather [name_of_city],[country_code]'\nExamples: '!weather New York,US', '!weather London,UK'");
			break;
		default:
			msg.reply("No available manual");
	}
}

//DISCORD BOT CODE
//-------------------------------------------------------

//When there has been a message, it reads it and proceeds to parse it and check to see if any commands had been typed.
bot.on('message', msg=> {
	var arguments = msg.content.split(" "); //Splits the message into parts

	switch (arguments[0]) {
		case "!weather"://Checks to see if the first word in the message is the !weather command
			weather(arguments,msg);
			break;
		case "!man": //Man for manual, for information about commands.
			man(arguments,msg);
			break;
	}
})

bot.login(token); //Logins into the discord bot, using the unique token for it.
