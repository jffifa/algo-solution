#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <ctime>

const int L1_CACHE_SIZE = 32768;
//const int L1_CACHE_SIZE = 65536;

const unsigned char bit_mask[16] = {
    0, 1<<0,
    0, 1<<1, 
    0, 1<<2, 
    0, 1<<3, 
    0, 1<<4, 
    0, 1<<5, 
    0, 1<<6, 
    0, 1<<7 
};

const int popcnt[256] = {
    8, 7, 7, 6, 7, 6, 6, 5, 7, 6, 6, 5, 6, 5, 5, 4, 
    7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3, 
    7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3, 
    6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2, 
    7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3, 
    6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2, 
    6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2, 
    5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1, 
    7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3, 
    6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2, 
    6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2, 
    5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1, 
    6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2, 
    5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1, 
    5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1, 
    4, 3, 3, 2, 3, 2, 2, 1, 3, 2, 2, 1, 2, 1, 1, 0
};

int nth_prime(int n, int limit, int seg_size=L1_CACHE_SIZE) {
    int sieve_size = seg_size<<4;
    int sqrt_limit = (int)sqrt((double)limit);

    int count = 0;
    int cnt = 0;
    int s = 2;
    int t = 0;

    int *prime = new int[sieve_size];
    int *next = new int[sieve_size];
    unsigned char *seg = new unsigned char[seg_size];//分段筛
    bool *sieve = new bool[sqrt_limit+1];//sqrt(limit)以下小筛
    memset(sieve, 0, sqrt_limit);

    for (int i = 2; i*i <= sqrt_limit; ++i) {
        if (!sieve[i]) {
            for (int j = i*i; j <= sqrt_limit; j += i) {
                sieve[j] = 1;
            }
        }
    }

    for (int left = 0; left <= limit; left += sieve_size) {
        int right = std::min(left+sieve_size, limit);

        memset(seg, 0, seg_size);
        if (left+sieve_size > limit) {
            seg[limit+1-left >> 4] |= (0xff << ((limit+1)&0xf>>1));
        }

        for (; s*s < right; ++s) {
            if (!sieve[s]) {
                prime[cnt] = s;
                next[cnt++] = s*s-left;
            }
        }

        for (int i = 1; i < cnt; ++i) {
            int j = next[i];
            for (int k = prime[i]*2; j < sieve_size; j += k) {
                seg[j>>4] |= bit_mask[j&0xf];
            }
            next[i] = j-sieve_size;
        }

        for (; t < right; t += 1<<4) {
            count += popcnt[seg[t-left >> 4]];
            if (count >= n) {
                int bit = seg[t-left >> 4];
                int tmp = count-popcnt[bit];
                for (int i = 1; i < 1<<4; i += 2) {
                    if (!(bit_mask[i] & bit)) {
                        ++tmp;
                        if (tmp == n) {
                            return t+i;
                        }
                    }
                }
            }
        }

    }

    return -1;
}

int main() {
    /*
    timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    int x = nth_prime(4263116, 100000000);
    clock_gettime(CLOCK_REALTIME, &end);
    double time = ((double)end.tv_sec*1000000000+end.tv_nsec)-((double)start.tv_sec*1000000000+start.tv_nsec);
    time /= 1000000000;
    */
    clock_t start = clock();
    int x = nth_prime(4263116, 100000000);
    clock_t end = clock();
    printf("%d, %f seconds\n", x, (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
