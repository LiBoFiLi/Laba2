#include "pch.h" 
#include "Source.cpp"

TEST(CSVParserTest, ParseCSV) {
    istringstream input("name, age\nJohn, 30\nJane, 25");
    auto& data = parseCSV(input);
    ASSERT_EQ(data.size(), 3);
    ASSERT_EQ(data[0][0], "name");
    ASSERT_EQ(data[1][0], "John");
    ASSERT_EQ(data[2][0], "Jane");
    ASSERT_EQ(data[0][1], " age");
    ASSERT_EQ(data[1][1], " 30");
    ASSERT_EQ(data[2][1], " 25");
}

TEST(CSVParserTest, ConvertToJson) {

    std::vector<std::vector<std::string>> data = { {"name", "age"}, {"John", "30"}, {"Jane", "25"} };
    auto json = convertToJson(data);
    ASSERT_EQ(json, R"([{"name": "John", "age": "30"}, {"name": "Jane", "age": "25"}])");
}


