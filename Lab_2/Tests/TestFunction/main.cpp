#include <iostream>
#include "func.h"
#include "func.cpp"
#include "complex.h"
#include <gtest/gtest.h>
#include <string>

Complex complexR() {
    Complex a;
    return a;
}

int intR() {
    return 0;
}

float floatR() {
    return 0;
}

TEST( TestFunction, testMonotone) {
    Function<int> f;
    Sequence<int> *c1 = (Sequence<int> *) new ArraySequence<int>();
    c1->Append(1);
    c1->Append(0);
    c1->Append(0);
    Sequence<int> *c2 = (Sequence<int> *) new ArraySequence<int>();
    c2->Append(2);
    c2->Append(0);
    c2->Append(0);
    Sequence<int> *c3 = (Sequence<int> *) new ArraySequence<int>();
    c3->Append(3);
    c3->Append(1);
    c3->Append(1);
    f.Set(c1, 0, 1);
    f.Set(c2, 2, 3);
    f.Set(c3, 3, 6);
    ASSERT_TRUE(f.IsMonotone());
}

TEST( TestFunction, testNotMonotone) {
    Function<int> f;
    Sequence<int> *c1 = (Sequence<int> *) new ArraySequence<int>();
    c1->Append(1);
    c1->Append(0);
    c1->Append(0);
    Sequence<int> *c2 = (Sequence<int> *) new ArraySequence<int>();
    c2->Append(3);
    c2->Append(1);
    c2->Append(1);
    Sequence<int> *c3 = (Sequence<int> *) new ArraySequence<int>();
    c3->Append(2);
    c3->Append(0);
    c3->Append(0);
    f.Set(c1, 0, 1);
    f.Set(c2, 2, 3);
    f.Set(c3, 3, 6);
    ASSERT_FALSE(f.IsMonotone());
}

TEST( TestFunction, testContinious) {
    Function<int> f;
    Sequence<int> *c1 = (Sequence<int> *) new ArraySequence<int>();
    c1->Append(1);
    c1->Append(0);
    c1->Append(0);
    Sequence<int> *c2 = (Sequence<int> *) new ArraySequence<int>();
    c2->Append(0);
    c2->Append(0);
    c2->Append(1);
    Sequence<int> *c3 = (Sequence<int> *) new ArraySequence<int>();
    c3->Append(10);
    c3->Append(0);
    c3->Append(0);
    f.Set(c1, 0, 1);
    f.Set(c2, 1, 3);
    f.Set(c3, 3, 6);
    ASSERT_TRUE(f.IsMonotone());
}

TEST( TestFunction, testNotContinious) {
    Function<int> f;
    Sequence<int> *c1 = (Sequence<int> *) new ArraySequence<int>();
    c1->Append(1);
    c1->Append(0);
    c1->Append(0);
    Sequence<int> *c2 = (Sequence<int> *) new ArraySequence<int>();
    c2->Append(3);
    c2->Append(1);
    c2->Append(1);
    Sequence<int> *c3 = (Sequence<int> *) new ArraySequence<int>();
    c3->Append(2);
    c3->Append(0);
    c3->Append(0);
    f.Set(c1, 0, 1);
    f.Set(c2, 2, 3);
    f.Set(c3, 3, 6);
    ASSERT_FALSE(f.IsContinuous());
}

TEST( TestFunction, testValue) {
    Function<int> f;
    Sequence<int> *c1 = (Sequence<int> *) new ArraySequence<int>();
    c1->Append(1);
    c1->Append(0);
    c1->Append(0);
    Sequence<int> *c2 = (Sequence<int> *) new ArraySequence<int>();
    c2->Append(3);
    c2->Append(1);
    c2->Append(1);
    Sequence<int> *c3 = (Sequence<int> *) new ArraySequence<int>();
    c3->Append(2);
    c3->Append(0);
    c3->Append(0);
    f.Set(c1, 0, 1);
    f.Set(c2, 2, 4);
    f.Set(c3, 4, 6);
    ASSERT_TRUE(f.Value(3) == 15);
}

TEST ( TestTimeOfComplexFunctionValue, test1 ) {
    Function<Complex> f;
    f.Generate(1000, complexR);
    Complex z = f.Value(0);
    ASSERT_TRUE(z.GetIm() == 0.0 && z.GetRe() == 0);
}

TEST ( TestTimeOfComplexFunctionValue, test2 ) {
    Function<Complex> f;
    f.Generate(6000, complexR);
    Complex z = f.Value(0);
    ASSERT_TRUE(z.GetIm() == 0.0 && z.GetRe() == 0);
}

TEST ( TestTimeOfComplexFunctionValue, test3 ) {
    Function<Complex> f;
    f.Generate(11000, complexR);
    Complex z = f.Value(0);
    ASSERT_TRUE(z.GetIm() == 0.0 && z.GetRe() == 0);
}

TEST ( TestTimeOfComplexFunctionValue, test4 ) {
    Function<Complex> f;
    f.Generate(16000, complexR);
    Complex z = f.Value(0);
    ASSERT_TRUE(z.GetIm() == 0.0 && z.GetRe() == 0);
}

TEST ( TestTimeOfComplexFunctionValue, test5 ) {
    Function<Complex> f;
    f.Generate(21000, complexR);
    Complex z = f.Value(0);
    ASSERT_TRUE(z.GetIm() == 0.0 && z.GetRe() == 0);
}

TEST ( TestTimeOfComplexFunctionValue, test6 ) {
    Function<Complex> f;
    f.Generate(26000, complexR);
    Complex z = f.Value(0);
    ASSERT_TRUE(z.GetIm() == 0.0 && z.GetRe() == 0);
}

TEST ( TestTimeOfComplexFunctionValue, test7 ) {
    Function<Complex> f;
    f.Generate(31000, complexR);
    Complex z = f.Value(0);
    ASSERT_TRUE(z.GetIm() == 0.0 && z.GetRe() == 0);
}

TEST ( TestTimeOfComplexFunctionValue, test8 ) {
    Function<Complex> f;
    f.Generate(36000, complexR);
    Complex z = f.Value(0);
    ASSERT_TRUE(z.GetIm() == 0.0 && z.GetRe() == 0);
}

TEST ( TestTimeOfComplexFunctionValue, test9 ) {
    Function<Complex> f;
    f.Generate(41000, complexR);
    Complex z = f.Value(0);
    ASSERT_TRUE(z.GetIm() == 0.0 && z.GetRe() == 0);
}

TEST ( TestTimeOfComplexFunctionValue, test10 ) {
    Function<Complex> f;
    f.Generate(46000, complexR);
    Complex z = f.Value(0);
    ASSERT_TRUE(z.GetIm() == 0.0 && z.GetRe() == 0);
}


TEST ( TestTimeOfComplexFunctionCountinious, test1 ) {
    Function<Complex> f;
    f.Generate(1000, complexR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfComplexFunctionCountinious, test2 ) {
    Function<Complex> f;
    f.Generate(6000, complexR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfComplexFunctionCountinious, test3 ) {
    Function<Complex> f;
    f.Generate(11000, complexR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfComplexFunctionCountinious, test4 ) {
    Function<Complex> f;
    f.Generate(16000, complexR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfComplexFunctionCountinious, test5 ) {
    Function<Complex> f;
    f.Generate(21000, complexR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfComplexFunctionCountinious, test6 ) {
    Function<Complex> f;
    f.Generate(26000, complexR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfComplexFunctionCountinious, test7 ) {
    Function<Complex> f;
    f.Generate(31000, complexR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfComplexFunctionCountinious, test8 ) {
    Function<Complex> f;
    f.Generate(36000, complexR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfComplexFunctionCountinious, test9 ) {
    Function<Complex> f;
    f.Generate(41000, complexR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfComplexFunctionCountinious, test10 ) {
    Function<Complex> f;
    f.Generate(46000, complexR);
    ASSERT_TRUE(f.IsContinuous());
}



TEST ( TestTimeOfIntFunctionValue, test1 ) {
    Function<int> f;
    f.Generate(1000, intR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0);
}

TEST ( TestTimeOfIntFunctionValue, test2 ) {
    Function<int> f;
    f.Generate(6000, intR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0);
}

TEST ( TestTimeOfIntFunctionValue, test3 ) {
    Function<int> f;
    f.Generate(11000, intR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0);
}

TEST ( TestTimeOfIntFunctionValue, test4 ) {
    Function<int> f;
    f.Generate(16000, intR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0);
}

TEST ( TestTimeOfIntFunctionValue, test5 ) {
    Function<int> f;
    f.Generate(21000, intR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0);
}

TEST ( TestTimeOfIntFunctionValue, test6 ) {
    Function<int> f;
    f.Generate(26000, intR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0);
}

TEST ( TestTimeOfIntFunctionValue, test7 ) {
    Function<int> f;
    f.Generate(31000, intR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0);
}

TEST ( TestTimeOfIntFunctionValue, test8 ) {
    Function<int> f;
    f.Generate(36000, intR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0);
}

TEST ( TestTimeOfIntFunctionValue, test9 ) {
    Function<int> f;
    f.Generate(41000, intR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0);
}

TEST ( TestTimeOfIntFunctionValue, test10 ) {
    Function<int> f;
    f.Generate(46000, intR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0);
}



TEST ( TestTimeOfFloatFunctionValue, test1 ) {
    Function<float> f;
    f.Generate(1000, floatR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0.0);
}

TEST ( TestTimeOfFloatFunctionValue, test2 ) {
    Function<float> f;
    f.Generate(6000, floatR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0.0);
}

TEST ( TestTimeOfFloatFunctionValue, test3 ) {
    Function<float> f;
    f.Generate(11000, floatR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0.0);
}

TEST ( TestTimeOfFloatFunctionValue, test4 ) {
    Function<float> f;
    f.Generate(16000, floatR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0.0);
}

TEST ( TestTimeOfFloatFunctionValue, test5 ) {
    Function<float> f;
    f.Generate(21000, floatR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0.0);
}

TEST ( TestTimeOfFloatFunctionValue, test6 ) {
    Function<float> f;
    f.Generate(26000, floatR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0.0);
}

TEST ( TestTimeOfFloatFunctionValue, test7 ) {
    Function<float> f;
    f.Generate(31000, floatR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0.0);
}

TEST ( TestTimeOfFloatFunctionValue, test8 ) {
    Function<float> f;
    f.Generate(36000, floatR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0.0);
}

TEST ( TestTimeOfFloatFunctionValue, test9 ) {
    Function<float> f;
    f.Generate(41000, floatR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0.0);
}

TEST ( TestTimeOfFloatFunctionValue, test10 ) {
    Function<float> f;
    f.Generate(46000, floatR);
    int z = f.Value(0);
    ASSERT_TRUE(z == 0.0);
}



TEST ( TestTimeOfIntFunctionCountinious, test1 ) {
    Function<int> f;
    f.Generate(1000, intR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfIntFunctionCountinious, test2 ) {
    Function<int> f;
    f.Generate(6000, intR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfIntFunctionCountinious, test3 ) {
    Function<int> f;
    f.Generate(11000, intR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfIntFunctionCountinious, test4 ) {
    Function<int> f;
    f.Generate(16000, intR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfIntFunctionCountinious, test5 ) {
    Function<int> f;
    f.Generate(21000, intR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfIntFunctionCountinious, test6 ) {
    Function<int> f;
    f.Generate(26000, intR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfIntFunctionCountinious, test7 ) {
    Function<int> f;
    f.Generate(31000, intR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfIntFunctionCountinious, test8 ) {
    Function<int> f;
    f.Generate(36000, intR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfIntFunctionCountinious, test9 ) {
    Function<int> f;
    f.Generate(41000, intR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfIntFunctionCountinious, test10 ) {
    Function<int> f;
    f.Generate(46000, intR);
    ASSERT_TRUE(f.IsContinuous());
}



TEST ( TestTimeOfFloatFunctionCountinious, test1 ) {
    Function<float> f;
    f.Generate(1000, floatR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfFloatFunctionCountinious, test2 ) {
    Function<float> f;
    f.Generate(6000, floatR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfFloatFunctionCountinious, test3 ) {
    Function<float> f;
    f.Generate(11000, floatR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfFloatFunctionCountinious, test4 ) {
    Function<float> f;
    f.Generate(16000, floatR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfFloatFunctionCountinious, test5 ) {
    Function<float> f;
    f.Generate(21000, floatR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfFloatFunctionCountinious, test6 ) {
    Function<float> f;
    f.Generate(26000, floatR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfFloatFunctionCountinious, test7 ) {
    Function<float> f;
    f.Generate(31000, floatR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfFloatFunctionCountinious, test8 ) {
    Function<float> f;
    f.Generate(36000, floatR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfFloatFunctionCountinious, test9 ) {
    Function<float> f;
    f.Generate(41000, floatR);
    ASSERT_TRUE(f.IsContinuous());
}

TEST ( TestTimeOfFloatFunctionCountinious, test10 ) {
    Function<float> f;
    f.Generate(46000, floatR);
    ASSERT_TRUE(f.IsContinuous());
}




TEST ( TestTimeOfIntFunctionMonotone, test1 ) {
    Function<int> f;
    f.Generate(1000, intR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfIntFunctionMonotone, test2 ) {
    Function<int> f;
    f.Generate(6000, intR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfIntFunctionMonotone, test3 ) {
    Function<int> f;
    f.Generate(11000, intR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfIntFunctionMonotone, test4 ) {
    Function<int> f;
    f.Generate(16000, intR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfIntFunctionMonotone, test5 ) {
    Function<int> f;
    f.Generate(21000, intR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfIntFunctionMonotone, test6 ) {
    Function<int> f;
    f.Generate(26000, intR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfIntFunctionMonotone, test7 ) {
    Function<int> f;
    f.Generate(31000, intR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfIntFunctionMonotone, test8 ) {
    Function<int> f;
    f.Generate(36000, intR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfIntFunctionMonotone, test9 ) {
    Function<int> f;
    f.Generate(41000, intR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfIntFunctionMonotone, test10 ) {
    Function<int> f;
    f.Generate(46000, intR);
    ASSERT_TRUE(f.IsMonotone());
}


TEST ( TestTimeOfFloatFunctionMonotone, test1 ) {
    Function<float> f;
    f.Generate(1000, floatR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfFloatFunctionMonotone, test2 ) {
    Function<float> f;
    f.Generate(6000, floatR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfFloatFunctionMonotone, test3 ) {
    Function<float> f;
    f.Generate(11000, floatR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfFloatFunctionMonotone, test4 ) {
    Function<float> f;
    f.Generate(16000, floatR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfFloatFunctionMonotone, test5 ) {
    Function<float> f;
    f.Generate(21000, floatR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfFloatFunctionMonotone, test6 ) {
    Function<float> f;
    f.Generate(26000, floatR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfFloatFunctionMonotone, test7 ) {
    Function<float> f;
    f.Generate(31000, floatR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfFloatFunctionMonotone, test8 ) {
    Function<float> f;
    f.Generate(36000, floatR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfFloatFunctionMonotone, test9 ) {
    Function<float> f;
    f.Generate(41000, floatR);
    ASSERT_TRUE(f.IsMonotone());
}

TEST ( TestTimeOfFloatFunctionMonotone, test10 ) {
    Function<float> f;
    f.Generate(46000, floatR);
    ASSERT_TRUE(f.IsMonotone());
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
