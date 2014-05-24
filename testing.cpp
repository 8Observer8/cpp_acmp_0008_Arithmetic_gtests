#include <gtest/gtest.h>

class LogicError : public std::logic_error {
public:

    LogicError( ) : std::logic_error( "" ) {

    }

    virtual const char *what() const throw( ) {
        return m_message.c_str( );
    }

    virtual ~LogicError( ) throw( ) {

    }

protected:
    std::string m_message;
};

class OutOfRange : public LogicError {
public:

    OutOfRange( int argument, int beginOfRange, int endOfRange ) {
        std::string str_argument, str_beginOfRange, str_endOfRange;

        str_argument = intToString( argument );
        str_beginOfRange = intToString( beginOfRange );
        str_endOfRange = intToString( endOfRange );

        m_message = "Error: the argument " + str_argument +
                " don't hit to the range [" + str_beginOfRange +
                ", " + str_beginOfRange + "]";
    }

private:
    std::string intToString( int number ) {
        std::stringstream stream;
        stream << number;
        return stream.str( );
    }
};

bool isProduct( int a, int b, int product ) throw( OutOfRange );

TEST( test001, insideOfRangeTest ) {
    int a = 0;
    int b = 54;
    int product = 0;

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isProduct( a, b, product );
                     } );
    bool expected = true;
    ASSERT_EQ( expected, actual );
}

TEST( test002, badValueTest ) {
    int a = 0;
    int b = 54;
    int product = 1;

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isProduct( a, b, product );
                     } );
    bool expected = false;
    ASSERT_EQ( expected, actual );
}

TEST( test003, outsideOfRangeTest ) {
    int a = -1;
    int b = 54;
    int product = 0;

    ASSERT_THROW( {
                      isProduct( a, b, product );
                  }, OutOfRange );
}

TEST( test004, insideOfRangeTest ) {
    int a = 8;
    int b = 0;
    int product = 0;

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isProduct( a, b, product );
                     } );
    bool expected = true;
    ASSERT_EQ( expected, actual );
}

TEST( test005, badValueTest ) {
    int a = 8;
    int b = 0;
    int product = 1;

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isProduct( a, b, product );
                     } );
    bool expected = false;
    ASSERT_EQ( expected, actual );
}

TEST( test006, outsideOfRangeTest ) {
    int a = 8;
    int b = -1;
    int product = 0;

    ASSERT_THROW( {
                      isProduct( a, b, product );
                  }, OutOfRange );
}

TEST( test007, insideOfRangeTest ) {
    int a = 100;
    int b = 1;
    int product = 100;

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isProduct( a, b, product );
                     } );
    bool expected = true;
    ASSERT_EQ( expected, actual );
}

TEST( test008, badValueTest ) {
    int a = 100;
    int b = 1;
    int product = 2;

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isProduct( a, b, product );
                     } );
    bool expected = false;
    ASSERT_EQ( expected, actual );
}

TEST( test009, outsideOfRangeTest ) {
    int a = 101;
    int b = 1;
    int product = 0;

    ASSERT_THROW( {
                      isProduct( a, b, product );
                  }, OutOfRange );
}

TEST( test010, insideOfRangeTest ) {
    int a = 1;
    int b = 100;
    int product = 100;

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isProduct( a, b, product );
                     } );
    bool expected = true;
    ASSERT_EQ( expected, actual );
}

TEST( test011, badValueTest ) {
    int a = 1;
    int b = 100;
    int product = 2;

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isProduct( a, b, product );
                     } );
    bool expected = false;
    ASSERT_EQ( expected, actual );
}

TEST( test012, outsideOfRangeTest ) {
    int a = 1;
    int b = 101;
    int product = 0;

    ASSERT_THROW( {
                      isProduct( a, b, product );
                  }, OutOfRange );
}

TEST( test013, outsideOfRangeTest ) {
    int a = 1;
    int b = 1;
    int product = 1000001;

    ASSERT_THROW( {
                      isProduct( a, b, product );
                  }, OutOfRange );
}

TEST( test014, outsideOfRangeTest ) {
    int a = 1;
    int b = 1;
    int product = 1000000;

    ASSERT_NO_THROW( {
                      isProduct( a, b, product );
                  } );
}

TEST( test015, yesAnswerTest ) {
    int a = 8;
    int b = 54;
    int product = 432;

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isProduct( a, b, product );
                     } );
    bool expected = true;
    ASSERT_EQ( expected, actual );
}

TEST( test016, noAnswerTest ) {
    int a = 16;
    int b = 19;
    int product = 777;

    bool actual = false;
    ASSERT_NO_THROW( {
                         actual = isProduct( a, b, product );
                     } );
    bool expected = false;
    ASSERT_EQ( expected, actual );
}

int main( int argc, char *argv[] ) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS( );
}
