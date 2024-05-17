#include "pch.h"
#include "../../BaseBall/baseball.cpp"

class BassballFixture : public testing::Test {
public:
    Baseball game;
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
