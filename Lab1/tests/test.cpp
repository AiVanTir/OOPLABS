#include <gtest/gtest.h>
#include "../src/modify.hpp"

TEST(AddTest, ExampleString) {
    EXPECT_EQ(ConvertToString(std::vector<int>({1, 3, 2}), "ArrName"), "[ArrName]\n1=1\n2=3\n3=2\n");
}

TEST(AddTest, ExampleVectorCharArr) {
    EXPECT_EQ(ConvertToVector("[ArrName]\n1=1\n2=3\n3=2\n", 21), std::vector<int>({1, 3, 2}));
}

TEST(AddTest, ExampleVectorChar) {
    EXPECT_EQ(ConvertToVector("[ArrName]\n1=1\n2=3\n3=2\n"), std::vector<int>({1, 3, 2}));
}

TEST(AddTest, ExampleVectorString) {
    EXPECT_EQ(ConvertToVector("[ArrName]\n1=1\n2=3\n3=2\n"), std::vector<int>({1, 3, 2}));
}

TEST(AddTest, EmptyArr) {
    EXPECT_EQ(ConvertToString(std::vector<int>(), "[]"), "[]\n");
}

TEST(AddTest, EmptyStringArr) {
    EXPECT_EQ(ConvertToVector("[ArrName]\n"), std::vector<int>());
}

TEST(AddTest, FailScobkiBad1){
    EXPECT_THROW(ConvertToVector("ArrName]\n", 21), std::runtime_error);
}

TEST(AddTest, FailScobkiBad2) {
    EXPECT_THROW(ConvertToVector("[ArrName\n", 21), std::runtime_error);
}

TEST(AddTest, FailEmpty) {
    EXPECT_THROW(ConvertToVector(""), std::runtime_error);
}

TEST(AddTest, FailIndexErr) {
    EXPECT_THROW(ConvertToVector("[ArrName]ar\n1=1\n3=3\n2=2\n"), std::runtime_error);
}

TEST(AddTest, FailWrongIndex) {
    EXPECT_THROW(ConvertToVector("[ArrName]\neq=1\n3=3\n2=2\n"), std::runtime_error);
}

TEST(AddTest, FailWrongIndex2) {
    EXPECT_THROW(ConvertToVector("[ArrName]\n1=eq\n3=3\n2=2\n"), std::runtime_error);
}

TEST(AddTest, FailWrongEqualSign1) {
    EXPECT_THROW(ConvertToVector("[ArrName]\n=1\n3=3\n2=2\n"), std::runtime_error);
}

TEST(AddTest, FailWrongEqualSign2) {
    EXPECT_THROW(ConvertToVector("[ArrName]\n1=\n3=3\n2=2\n"), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}