#include <codeanalysis\warnings.h>

#include <iostream>
#include <string>

#include "ALib/Alib.h"
#pragma warning(push)
#pragma warning(disable : ALL_CODE_ANALYSIS_WARNINGS)
#include "benchmark/benchmark.h"
#include "gtest/gtest.h"
#pragma warning(pop)


TEST(SampleTestSuite, SampleTest) {
  ASSERT_TRUE(true);
}

static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
BENCHMARK(BM_StringCreation);

// Google test sanitizer integration.
extern "C"
{
  void __ubsan_on_report()
  {
    FAIL() << "Encountered an undefined behavior sanitizer error";
  }
  void __asan_on_error()
  {
    FAIL() << "Encountered an address sanitizer error";
  }
  void __tsan_on_report()
  {
    FAIL() << "Encountered a thread sanitizer error";
  }
} // extern "C"

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
  ALib::sayHello();
  std::cout << "--- Google Test ---\n";
  // adding --gtest_break_on_failure could be interresting
  ::testing::InitGoogleTest(&argc, argv);
  if (RUN_ALL_TESTS() == EXIT_FAILURE)
  {
    return EXIT_FAILURE;
  }

   std::cout << "\n--- Google Benchmark ---\n";
  ::benchmark::Initialize(&argc, argv);
   if (::benchmark::ReportUnrecognizedArguments(argc, argv))
  {
     return EXIT_FAILURE;
   }
  ::benchmark::RunSpecifiedBenchmarks();
  ::benchmark::Shutdown();

  return EXIT_SUCCESS;
}