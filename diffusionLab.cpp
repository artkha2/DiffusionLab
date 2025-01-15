#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    const int M = 10; // number of trials
    const int NUMBER_OF_NS = 5; // number of different N's to try

    int step_numbers[NUMBER_OF_NS] = {10, 100, 1000, 5000, 10000}; // number of steps
  
    int d_values[NUMBER_OF_NS][M];  // final positions of each trial for every N
    // Each inner array is M final positions, there are are NUMBER_OF_NS inner arrays
    // Each row corresponds to a particular N value, values within a row are trials 1-M

    for(int n_ind=0; n_ind < NUMBER_OF_NS; n_ind++){  // iterate through different N's
        for(int trial=0; trial<M; trial++){  // Do M trials for every N
            int current_pos = 0;  // reset position for every trial

            for(int step=0; step<step_numbers[n_ind]; step++){  // Do N steps
                
                int coin_toss = rand() % 2;  // // Generate a random number (0 or 1)

                if(coin_toss){  // 1 (tails)
                    current_pos--;  // move backwards
                } else{  // 0 (heads)
                    current_pos++;  // move forward
                }
            }
            d_values[n_ind][trial] = current_pos;  // store the final position in 2D array
        }
    }

    // Output the results into a CSV file by iterating through 2D array
    // CSV makes it easier to import the data into Google Sheets/Excel and graph it
    
    ofstream out_file("diffusion_out.csv");  // create new file or overwrite existing one
    out_file << "Number of Steps (N),Trial Number (M),Final Position (D)\n";  // Write header row
    
    //cout << "Number of Steps (N) \t Trial Number (M) \t Final Position (D)\n";  // Uncomment to print to console

    for(int n_ind=0; n_ind < NUMBER_OF_NS; n_ind++){  // iterate through different N's
        for(int trial=1; trial<=M; trial++){  // Do M trials for every N
            //cout << "\t" << step_numbers[n_ind] << "\t\t\t" << trial << "\t\t\t" << d_values[n_ind][trial] << "\n"; // Uncomment to print to console
            out_file << step_numbers[n_ind] << "," << trial << "," << d_values[n_ind][trial] << "\n";
        }
    }

    
    
    
}