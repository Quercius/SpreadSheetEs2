add_subdirectory(lib)
set(gtest_SORCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp ValuesFixture.cpp ValuesTest.cpp OperationsFixture.cpp OperationsTest.cpp CellTest.cpp CellFixture.cpp)
add_executable(runSpreadSheetTests ${TEST_SOURCE_FILES})
target_link_libraries(runSpreadSheetTests gtest gtest_main core)