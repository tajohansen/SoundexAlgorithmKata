
#include <gmock/gmock.h>
#include "Soundex.h"

using namespace testing;

// Create a class fixture
class SoundexEncoding: public testing::Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    // Arrange
   Soundex soundex;
   //Act

   //Assert
   ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    // Arrange
    Soundex soundex;
    //Act

    //Assert
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantWithAppropriateDigits)
{
    // Arrange

    //Act

    //Assert
    ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
    ASSERT_THAT(soundex.encode("Ac"), Eq("A200"));
    ASSERT_THAT(soundex.encode("Ad"), Eq("A300"));
    ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
    ASSERT_THAT(soundex.encode("Ar"), Eq("A600"));
}
TEST_F(SoundexEncoding, IgnoreNonAlphabetics)
{
    // Arrange
     //Act

    //Assert
    ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}
// DISABLED_ will not run the test.
// use it when you need to refactor your code
// then, when you are ready, "enable" your test

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits)
{
    // Arrange
    //Act

    //Assert
    ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}
TEST_F(SoundexEncoding, LimitLengthToFourCharacters)
{
    // Arrange
    //Act

    //Assert
    ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, CombineDuplicateEncodings)
{
    // Arrange
    //Act

    //Assert
    ASSERT_THAT(soundex.encodeDigit('b'), Eq(soundex.encodeDigit('f')));
    ASSERT_THAT(soundex.encodeDigit('x'), Eq(soundex.encodeDigit('g')));
    ASSERT_THAT(soundex.encodeDigit('d'), Eq(soundex.encodeDigit('t')));

    ASSERT_THAT(soundex.encode("Abfxgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, UpperCaseFirstLetter)
{
    // Arrange

    //Act & Assert
    ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoreVowelsLikeLetters)
{
    // Arrange

    //Act & Assert
    ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYWwcdl"), StartsWith("B234"));
}

TEST_F(SoundexEncoding, IgnoreCaseWhenEncodingConsonants)
{
    // Arrange

    //Act & Assert
    ASSERT_THAT(soundex.encode("BCDL"), soundex.encode("Bcdl"));
}

