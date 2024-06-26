#include <iostream>
#include <stdexcept>
using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& question)
		: question(question) {

	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) return { true, 3, 0 };

		GuessResult result = { 0 };
		int questionPos = 0;
		for (auto& num : guessNumber)
		{
			int pos = question.find(num);
			if (pos == -1) continue;
			if (pos == questionPos) result.strikes++;
			else result.balls++;
			questionPos++;
		}

		result.solved = result.strikes == 3 ? true : false;

		return result;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters");
		}

		for (char ch : guessNumber)
		{
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicateNumber(guessNumber))
		{
			throw invalid_argument("Must not have the same number");
		}
	}

	bool isDuplicateNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
private:
	string question;
};