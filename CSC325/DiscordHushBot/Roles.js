const hushRoleName = "The Hushed";
const unhushRoleName = "The Unhushables";
const userRoleName = "Bro";


//Create roles in guilds automatically!
module.exports.createRoles = function(guild) {
	if (guild.available) {

		guild.roles.find(role => role.name == "@everyone").permissions = 66560;

		guild.createRole({
			name: userRoleName,
			permissions:1341644225
		}).catch(console.error);

		guild.createRole({
			name: hushRoleName,
		}).catch(console.error);

		guild.createRole({
			name:unhushRoleName,
			position:0
		}).catch(console.error);
	}
}

//Checks to see if the roles are in the guild that are needed.
module.exports.areRolesCreated = function(guild) {

	if (guild.available) {
		if (guild.roles.find(role => role.name == hushRoleName) != null && guild.roles.find(role => role.name == unhushRoleName) != null) {
			return true;
		}
	}

	return false;
}
