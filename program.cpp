// Linear Congruential Generator

#include <bits/stdc++.h>

using namespace std;

int yield_pseudo_random_number_sequence(int modulus,
                                        int multiplier,
                                        int increment,
                                        int seed,
                                        vector<long long> & pseudo_random_number_sequence,
                                        int pseudo_random_number_sequence_length)
{
    // sequence[index] = ((sequence[index - 1] * multiplier) + increment) % modulus
    
    // a = 1: additive congruence
    // b = 0: multiplicative congruence
    
    pseudo_random_number_sequence[0] = seed;
    
    for (int index = 1; index < pseudo_random_number_sequence_length; index++)
        pseudo_random_number_sequence[index] = ((pseudo_random_number_sequence[index - 1] * multiplier) + increment) % modulus;
        
    return 0;
}

int main()
{
    /*
        Park and Miller's LCG (MINSTD):
        
        modulus = 2³¹ - 1 = 2,147,483,647
        multiplier = 48,271
        increment = 0
    */
    
    int modulus = 2147483647;
    int multiplier = 16807;
    int increment = 0;
    int seed = 1;
    
    int pseudo_random_number_sequence_length = 12;
    vector<long long> pseudo_random_number_sequence(pseudo_random_number_sequence_length);
    
    yield_pseudo_random_number_sequence(modulus,
                                        multiplier,
                                        increment,
                                        seed,
                                        pseudo_random_number_sequence,
                                        pseudo_random_number_sequence_length);
                                        
    for (int index = 0; index < pseudo_random_number_sequence_length; index++)
        cout << pseudo_random_number_sequence[index] << ' ';
        
    return 0;
}
