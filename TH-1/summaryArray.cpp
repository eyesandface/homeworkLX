#include <iostream>
#include <vector>
#include <thread>
#include <ctime>
#include <cstdlib>

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        std::cerr << "Usage: " << argv[0] << " <N> <M>\n";
        return 1;
    }

    long N = std::stol(argv[1]);
    int M = std::stoi(argv[2]);

    std::vector<int> arr(N);
    srand(time(0));
    for (long i = 0; i < N; ++i) arr[i] = rand() % 100;

    clock_t start = clock();
    long sum1 = 0;
    for (long x : arr) sum1 += x;
    double time_no_threads = double(clock() - start) / CLOCKS_PER_SEC;

    start = clock();
    std::vector<std::thread> threads;
    std::vector<long> sums(M, 0);

    for (int t = 0; t < M; ++t) 
    {
        threads.emplace_back([&, t]()  
        {
            long start_idx = t * (N / M);
            long end_idx = (t == M - 1) ? N : (t + 1) * (N / M);
            for (long i = start_idx; i < end_idx; ++i)
                sums[t] += arr[i];
        });
    }

    for (auto& th : threads) th.join();

    long sum2 = 0;
    for (long s : sums) sum2 += s;
    double time_with_threads = double(clock() - start) / CLOCKS_PER_SEC;

    std::cout << "Time without threads: " << time_no_threads << " seconds\n";
    std::cout << "Time with " << M << " threads: " << time_with_threads << " seconds\n";

    return 0;
}
