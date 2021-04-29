#include <iostream>
using namespace std;


class Examination {

	private:

	string type = "";
	float maxScore = 0;
	float score = 0;
	float totalOfMax;

	public:

	string getType() {
		return type;
	}

	float getScore() {
		return score;
	}

	float getMaxScore() {
		return maxScore;
	}

	float getPercentage() {
		return score/maxScore;
	}

	float getTotalOfMax() {
		return totalOfMax;
	}

	void setScore(float Score) {
		score = Score;
	}

	void setMaxScore(float MaxScore) {
		maxScore = MaxScore;
	}

	void setType(string Type) {
		type = Type;
	}

	void setTotalOfMax(float TotalOfMax) {
		totalOfMax = TotalOfMax;
	}
};

class Student_Grade {

	private:

	const float maxExamScore = 100;
	const float examTotalOfMax = 0.5;
	const float maxMidtermScore = 100;
	const float midtermTotalOfMax = 0.25;
	const float maxQuizScore = 10;
	const float quizTotalOfMax = 0.25/2;
	int examinationsLength = 5;
	int examinationIndex = 0;
	Examination examinations[5];

	public:

	Student_Grade() {};

	float getMaxQuizScore() {
		return maxQuizScore;
	}

	float getMaxExamScore() {
		return maxExamScore;
	}

	float getMaxMidtermScore() {
		return maxMidtermScore;
	}

	void addExamination(string type, float score, float maxScore, float outOf) {
		if (examinationIndex < examinationsLength) {
			examinations[examinationIndex].setType(type);
			examinations[examinationIndex].setScore(score);
			examinations[examinationIndex].setMaxScore(maxScore);
			examinations[examinationIndex].setTotalOfMax(outOf);
			examinationIndex++;
		} else {
			cerr << "Too many examinations! The Students quit!";
		}
	}

	void addExam(float score) {
		addExamination("Exam", score, maxExamScore, examTotalOfMax);
	}

	void addMidterm(float score) {
		addExamination("Midterm", score, maxMidtermScore, midtermTotalOfMax);
	}

	void addQuiz(float score) {
		addExamination("Quiz", score, maxQuizScore, quizTotalOfMax);
	}

	float getFinalPercentage() {
		float total = 0;
		for (int i = 0; i < examinationIndex; i++) {
			total += examinations[i].getPercentage() * examinations[i].getTotalOfMax();
		}
		return total * 100;
	}

	char getFinalGrade() {
		float p = getFinalPercentage();

		if (p >= 90) {
			return 'A';
		} else if (p >= 80) {
			return 'B';
		} else if (p >= 70) {
			return 'C';
		} else if (p >= 60) {
			return 'D';
		} else {
			return 'F';
		}

	}
};

int main() {
	float quiz1,quiz2,midterm,exam;

	Student_Grade Bob; // = new Student_Grade();
	cout << "Student Quiz 1 Score (0-" << Bob.getMaxQuizScore() << "): ";
	cin >> quiz1;
	cout << "Student Quiz 2 Score (0-" << Bob.getMaxQuizScore() << "): ";
	cin >> quiz2;
	cout << "Student Midterm Score (0-" << Bob.getMaxMidtermScore() << "): ";
	cin >> midterm;
	cout << "Student Exam Score (0-" << Bob.getMaxExamScore() << "): ";
	cin >> exam;

	Bob.addQuiz(quiz1);
	Bob.addQuiz(quiz2);
	Bob.addMidterm(midterm);
	Bob.addExam(exam);

	cout << "Percentage: " <<  Bob.getFinalPercentage() << "%" << endl;
	cout << "Letter Grade: " << Bob.getFinalGrade() << endl;

	return 0;
}
