#include "pch.h"
#include "../../BaseBall/baseball.cpp"

class BassballFixture : public testing::Test {
public:
    Baseball game{ "123" };
    void assertIllegalArgument(string guessNumber)
    {
        try {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e)
        {
            // Pass
        }
    }
};

TEST_F(BassballFixture, ThrowExceptionWhenInvalidCase) {
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
    assertIllegalArgument("121");
}

TEST_F(BassballFixture, ReturnSolveResultIfMatcheNumber) {
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0,result.balls);
}
