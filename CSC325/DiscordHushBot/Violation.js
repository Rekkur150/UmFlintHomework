
//Use of Class: Keep track of the violation and the time and date

module.exports = class Violation {

	constructor(violation, type) {
		this.violation = violation;
		this.type = "";
		this.date = new Date();
	}

	getViolation() {
		return this.violation;
	}

	getDate() {
		return this.date;
	}

}
