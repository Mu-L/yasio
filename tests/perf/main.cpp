
#include "yasio/detail/utils.hpp"
#include "yasio/xxsocket.hpp"
#include "yasio/pod_vector.hpp"
#include "yasio/xx_podvector.hpp"

#include <stdio.h>

using namespace yasio;

int main()
{
  int64_t count, start;

  for (int k = 0; k < 3; ++k)
  {
    printf("######## Test round %d ######### \n", k + 1);
    printf("Testing xx_pod_vector...");
    count = 0;
    start = yasio::highp_clock();
    for (int i = 0; i < 100000; ++i)
    {
      xx::PodVector<int> pv;
      pv.Reserve(1000);
      for (int j = 0; j < 1000; ++j)
      {
        pv.Emplace(j);
      }
      for (int j = 0; j < 1000; ++j)
      {
        count += pv[j];
      }
    }
    printf("--> count: %lld, cost: %lf(s)\n", count,
           (yasio::highp_clock() - start) / (double)std::micro::den);

    printf("\nTesting ax_pod_vector...");
    count = 0;
    start = yasio::highp_clock();
    for (int i = 0; i < 100000; ++i)
    {
      ax::pod_vector<int> pv;
      pv.reserve(1000);
      for (int j = 0; j < 1000; ++j)
      {
        pv.emplace(j);
      }
      for (int j = 0; j < 1000; ++j)
      {
        count += pv[j];
      }
    }
    printf("--> count: %lld, cost: %lf(s)\n", count,
           (yasio::highp_clock() - start) / (double)std::micro::den);

    printf("\nTesting std_vector...");
    count = 0;
    start = yasio::highp_clock();
    for (int i = 0; i < 100000; ++i)
    {
      std::vector<int> pv;
      pv.reserve(1000);
      for (int j = 0; j < 1000; ++j)
      {
        pv.emplace_back(j);
      }
      for (int j = 0; j < 1000; ++j)
      {
        count += pv[j];
      }
    }
    printf("--> count: %lld, cost: %lf(s)\n", count,
           (yasio::highp_clock() - start) / (double)std::micro::den);

    printf("\n\n");
  }
  return 0;
}
