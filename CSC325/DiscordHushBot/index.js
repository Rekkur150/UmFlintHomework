var Discord = require("discord.js");
var roles = require("./Roles.js");
var sqlTest = require("./WordDatabase.js");


//DISCORD
const token = ''; //Allows us to connect to the discord bot.
var hushBot = new Discord.Client();

hushBot.on('message', msg=> {


		// console.log(compare.wordCheck(msg.content));

		// if (roles.areRolesCreated(msg.guild)) {
    //   console.log("Roles are created");
    // } else {
    //   roles.createRoles(msg.guild);
    //   console.log("Roles are not created");
    // }
})

// hushBot.login(token);
