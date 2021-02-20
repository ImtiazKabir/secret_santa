// A C program implementing the perfect Secret Santa!!!


// includes
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// derrangement function prototype
void derrangement(int* out, int len);


int main() {

    // gather all the persons!
    char person[][50] = {"abir", "omar", "kayes", "rafi"};

    // call the magic function!
    int arr[4];
    derrangement(arr, 4);

    // show the results!
    for (int i = 0; i < 4; ++i) {
        printf("%s is giving a gift to %s \n", person[i], person[arr[i]]);
    }


    return 0;
}


// the implementation
void derrangement(int *out, int len) {

    // Create the index array
    int arr[len];
    for (int i = 0; i < len; ++i) {
        arr[i] = i;
    }
    
    // Shuffle the array
    srand(time(0));
    for (int i = 0; i < 10 * len; ++i) {
        int a = rand() % len;
        int b = rand() % len;
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    // Create the output array
    for (int i = 0; i < len; ++i)
        out[arr[i]] = arr[(i+1) % len];
    
}
