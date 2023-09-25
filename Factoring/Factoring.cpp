
#include <iostream>
#include <vector>
#include <time.h>
#include <cmath>

int BruteForce(int N) {
    std::vector<bool> isPrime(N + 1, true);

    // iterate through all values in the given range denoted by N
    for (int num = 2; num <= N; num++) {
        // iterate through all values less than the current number being checked
        for (int x = 2; x < num - 1; x++) {
            // if the number being checked can be evenly divided by a number > 1 then its a composite and its value in our vector is set to false
            int value = num % x;
            if (value == 0) {
                isPrime[num] = false;
                // exit out of the loop and check next number.
                break;
            }
        }
    }

    // count the primes as all trues in the vector (array)
    int count = 0;
    for (int i = 2; i < N + 1; i++) {
        if (isPrime[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    int range = 1000000;

    // timer to see execution speed
    clock_t start_time = clock();

    // get count of primes
    int primeCount = BruteForce(range);
    std::cout << "The number of prime numbers between 0 and " << range << " is: " << primeCount << std::endl;

    // Show execution time (relative to other execution times from this computer only)
    printf("Time taken: %.4fs\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);
}





// RESULTS------------
// 
// Brute Force
// Range 100:       0.001 seconds - 25
// Range 1,000:     0.002 seconds - 168
// Range 10,000:    0.023 seconds - 1229
// Range 100,000:   1.422 seconds - 9592
// Range 1,000,000: 106.8 seconds - 78498

// Improrved version
// Range 100:       0.001 seconds - 25
// Range 1,000:     0.001 seconds - 168
// Range 10,000:    0.003 seconds - 1229
// Range 100,000:   0.028 seconds - 9592
// Range 1,000,000: 0.381 seconds - 78498

// Sieve version
// Range 100:       0.001 seconds - 25
// Range 1,000:     0.002 seconds - 168
// Range 10,000:    0.008 seconds - 1229
// Range 100,000:   0.084 seconds - 9592
// Range 1,000,000: 0.914 seconds - 78498











//---------GOOD_------------

//void sieveOfEratosthenes(int limit, std::vector<bool>& isPrime) {
//    // ensure the vector has enough space and default all to true
//    isPrime.resize(limit + 1, true);
//    // we are skipping 0 and 1
//    isPrime[0] = isPrime[1] = false;
//
//    // starting at 2 and stopping at p^2 > limit, if prime is true then verify
//    for (int p = 2; p * p <= limit; ++p) {
//        if (isPrime[p]) {
//            // set all multiples of p to false. This leaves only primes as true
//            for (int i = p * p; i <= limit; i += p) {
//                isPrime[i] = false;
//            }
//        }
//    }
//}
//
//int countPrimesInRange(int limit) {
//    std::vector<bool> isPrime;
//    sieveOfEratosthenes(limit, isPrime);
//
//    // count the primes
//    int count = 0;
//    for (int i = 2; i <= limit; ++i) {
//        if (isPrime[i]) {
//            count++;
//        }
//    }
//    return count;
//}
//
//int main() {
//    // What range should I check between 1 and range
//    int range = 1000000;
//
//    // timer to see execution speed
//    clock_t start_time = clock();
//
//    int primeCount = countPrimesInRange(range);
//    std::cout << "The number of prime numbers between 0 and " << range << " is: " << primeCount << std::endl;
//
//    // Show execution time (relative to other execution times from this computer only)
//    printf("Time taken: %.4fs\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);
//}

//----------------- Brute force

//int BruteForce(int N) {
//    std::vector<bool> isPrime(N + 1, true);
//
//    // iterate through all values in the given range denoted by N
//    for (int num = 2; num <= N; num++) {
//        // iterate through all values less than the current number being checked
//        for (int x = 2; x < num - 1; x++) {
//            // if the number being checked can be evenly divided by a number > 1 then its a composite and its value in our vector is set to false
//            int value = num % x;
//            if (value == 0) {
//                isPrime[num] = false;
//                // exit out of the loop and check next number.
//                break;
//            }
//        }
//    }
//
//    // count the primes as all trues in the vector (array)
//    int count = 0;
//    for (int i = 2; i < N + 1; i++) {
//        if (isPrime[i]) {
//            count++;
//        }
//    }
//    return count;
//}
//
//int main() {
//    int range = 1000000;
//
//    // timer to see execution speed
//    clock_t start_time = clock();
//
//    // get count of primes
//    int primeCount = BruteForce(range);
//    std::cout << "The number of prime numbers between 0 and " << range << " is: " << primeCount << std::endl;
//
//    // Show execution time (relative to other execution times from this computer only)
//    printf("Time taken: %.4fs\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);
//}

//------------------improved -----------------
//int ImprovedPrimeCount(int N) {
//    //instantiate variables
//    std::vector<bool> isPrime(N + 1, false);
//    bool composite = false;
//
//    //manually set 2 since its prime unlike the rest of even numbers
//    isPrime[2] = true;
//
//    // iterate through all odd values in the given range denoted by N
//    for (int num = 3; num <= N; num += 2) {
//
//        //reset composite check
//        composite = false;
//
//        // iterate through all values starting at 3 up to the square root of N-1 looking only at odd numbers
//        for (int x = 2; x * x <= num; x++) {
//            // if the number being checked can be evenly divided by a number > 1 then its a composite and its value in our vector is set to false
//            if (num % x == 0) {
//                // Its a composite. exit out of the loop and check next number.
//                composite = true;
//                break;
//            }
//        }
//        // if its not a composite then set it to be prime.
//        if (!composite) {
//            isPrime[num] = true;
//        }
//
//    }
//
//    // count the primes as all trues in the vector (array)
//    int count = 1;
//    for (int i = 3; i < N + 1; i += 2) {
//        if (isPrime[i]) {
//            count++;
//        }
//    }
//    return count;
//}
//int main() {
//    int range = 1000000;
//
//    // timer to see execution speed
//    clock_t start_time = clock();
//
//    // get count of primes
//    int primeCount = ImprovedPrimeCount(range);
//    std::cout << "The number of prime numbers between 0 and " << range << " is: " << primeCount << std::endl;
//
//    // Show execution time (relative to other execution times from this computer only)
//    printf("Time taken: %.4fs\n", (double)(clock() - start_time) / CLOCKS_PER_SEC);
//}