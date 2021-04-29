const Discord = require('discord.js');
const bot = new Discord.Client();

//Allow to connect to discord bot
const token = '';

//Checks to see when the bot is online, prints comment
bot.on('ready', () => {
	console.log('This bot is online');
})

bot.on('message', msg=> {
	if (msg.content === "HELLO!") {
		msg.reply("HELLO FRIEND");
	}
})

// bot.login(token);
