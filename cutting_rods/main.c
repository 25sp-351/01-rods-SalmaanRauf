//sorry for overzealous commenting, this is just how i code when learning new langauge. will reduce as we go on.

//FOCUS: KISS, readable code, should flow well and easy to understand without too many comments.

#include <stdio.h>
#include <stdlib.h>

// 2. read input lengths/vals, stores in arrays

int read_input(int lengths[], int values[]) {
    int count = 0;
    printf("Enter lengths and values, following this format: '<length>, <value>'");
    //The two %d are to expect integers, sep by commas. EOF = end of user input
    while (scanf("%d, %d", &lengths[count], &values[count]) != EOF) {
        count ++;
    }
    return count;
}

//3 recursively calc max value that you can get from cutting rod
int max_value(int rod_length, int lengths[], int values[], int count) {
    //base case
    if (rod_length == 0) {
        return 0;
    }
    int max_val = 0;
    // This is our for loop from beginning to end, we use i++ like in c++ for iter
    for (int i = 0; i < count; i++) {
        //checking if our current piece can fit in rod
        if (rod_length >= lengths[i]) {
                    //recrsively try cutting rod with this piece, cal val
            int val = values[i] + max_value(rod_length - lengths[i], lengths, values, count);
            //IF the value is better, update max_val
            if (val > max_val) {
                max_val = val;
            }
        }
    }
    return max_val;
}

//1 putting it all together
int main(int argc, char *argv[]) {
    //first check if user gave us the args we want as ip
    if (argc != 2) {
        printf("Please follow formatting instructions mentioned above.");
        return 1; //exit code
    }
    //converting the rod length str to int using atoi
    int rod_length = atoi(argv[1]);

    //arrays to stores lengs and vals. arrays require set size, just to be safe i put 1000.
    //complexity wise they should be smaller but complexity is not the focus here
    int lengths[1000], values [1000];
//now we use the functions we made earlier
    int count = read_input(lengths, values);

    int total_val = max_value(rod_length, lengths, values, count);

    printf("Maximum value: %d\n", total_val);

    return 0;//exiting 

}