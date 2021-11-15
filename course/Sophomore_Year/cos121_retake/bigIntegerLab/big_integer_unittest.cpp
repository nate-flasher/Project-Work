#include "big_integer.h"
#include "gtest/gtest.h"

TEST(BIGINTEGER, HALFTEST) {
    BigInteger a = BigInteger("12345");
    BigInteger c;
    c = a.half() ;
    EXPECT_EQ(c, BigInteger("6172") );
    
}

TEST(BIGINTEGER, EXPONENTTEST) {
    BigInteger a = BigInteger("2");
    BigInteger b = BigInteger("13");
    BigInteger c;
    c = a ^ b;
    EXPECT_EQ(c, BigInteger("8192") );
    
}


TEST(BIGINTEGER, BIGBIGINTEGERBASENUMBEREXPONENTTEST) {
    BigInteger a = BigInteger("1000000000000000");
    BigInteger b = BigInteger("2");
    BigInteger c;
    c = a ^ b;
    EXPECT_EQ(c, BigInteger("1000000000000000000000000000000") );
    
}

/*
TEST(BIGINTEGER, BIGBIGINTEGEREXPONENTTEST) {
    BigInteger a = BigInteger("10");
    BigInteger b = BigInteger("1000000000");
    BigInteger c;
    c = a ^ b;
    EXPECT_EQ(c.length()-1, 1000000000 ); //testing to see if there are 1000000000 zeroes in c
    
}
*/

TEST(BIGINTEGER, THISTEST) {
    BigInteger a = BigInteger("157");
//    BigInteger b = BigInteger("213");
    BigInteger b = BigInteger("3");
    BigInteger c;
    c = a ^ b;
    EXPECT_EQ(c, BigInteger("3869893")); //  EXPECT_EQ(c, BigInteger("532875757681112878599322116001473780216217322664569160182259902778702706506185738677935479885738392507817850561793302459384467050955275808566826909862378226650502853450334714418930017785409472314056454172453601660069160744664307240896026681346498487611670298092778784792797244592515718382943828909634399296096804448640713208806360280228865944123852753071366272336157051594239072476273392438687593130692835538873153314348384885291291236194893019947734231439147583637357") );
    
}

TEST(BIGINTEGER, ADDTEST) {
    BigInteger a = BigInteger("50");
    BigInteger b = BigInteger("60");
    BigInteger c;
    c = a + b;
    EXPECT_EQ(c, BigInteger("110") );
    
}



TEST(BIGINTEGER, MULTIPLYTEST) {
    BigInteger a = BigInteger(123);
    BigInteger b = BigInteger(456);
    BigInteger c;
    c = a * b;
    EXPECT_EQ(c, 56088);
}


TEST(BIGINTEGER, 157TEST) {
    BigInteger a = BigInteger(157);
    BigInteger b = BigInteger(157);
    BigInteger c;
    c = a * b;
    EXPECT_EQ(c, 24649);
}

TEST(BIGINTEGER, 24649TEST) {
    BigInteger a = BigInteger(24649);
    BigInteger b = BigInteger(157);
    BigInteger c;
    c = a * b;
    EXPECT_EQ(c, 3869893);
}
TEST(BIGINTEGER, LESSTHANTEST) {
    BigInteger a = BigInteger(8);
    BigInteger b = BigInteger(30);
    EXPECT_LT(a, b);
}



TEST(BIGINTEGER, EQUALTOTEST) {
    BigInteger a = BigInteger(63);
    BigInteger b = BigInteger(63);
    EXPECT_EQ(a, b);
}



TEST(BigInteger, STRINGTEST) {
    BigInteger myint = BigInteger(7);
    BigInteger mystring = BigInteger("7");

    EXPECT_EQ(myint, mystring);
}



TEST(BIGINTEGER, BIGBIGINTEGERADDTEST) {
    BigInteger bigIntString = BigInteger("578000000000");
    BigInteger bigIntString2 = BigInteger("1246000000000");
    BigInteger c;
    c = bigIntString + bigIntString2;
    EXPECT_EQ(c, BigInteger("1824000000000"));
}



TEST(BIGINTEGER, BIGBIGINTEGERMULTIPLYTEST) {
    BigInteger bigIntString = BigInteger("1230000000000");
    BigInteger bigIntString2 = BigInteger("150000000000");
    BigInteger c;
    c = bigIntString * bigIntString2;
    EXPECT_EQ(c, BigInteger("184500000000000000000000"));
}



TEST(BIGINTEGER, BIGBIGLESSTHANTEST) {
    BigInteger a = BigInteger("1000000000000");
    BigInteger b = BigInteger("1000000000001");
    EXPECT_LT(a, b);
}




TEST(BIGINTEGER, BIGBIGEQUALTOTEST) {
    BigInteger a = BigInteger("1000000000000");
    BigInteger b = BigInteger("1000000000000");
    EXPECT_EQ(a, b);
}




TEST(BigInteger, BIGBIGSTRINGTEST) {
    BigInteger myint = BigInteger("1000000000000");
    BigInteger mystring = BigInteger("1000000000000");

    EXPECT_EQ(myint, mystring);
}
