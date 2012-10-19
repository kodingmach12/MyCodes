#include<stdio.h>   // for srand and rand
#include<time.h>     // for time
int main() 
{
    int card[52];    // array of cards;
    int n=52,i;           // number of cards to deal
    srand(time(0));  // initialize seed "randomly"
     
    for (i=0; i<52; i++) {
        card[i] = i;  // fill the array in order
    }
    
    //while (cin >> n) {    
        //--- Shuffle elements by randomly exchanging each with one other.
        for (i=0; i<(52-1); i++) 
		{
            int r = i + (rand() % (52-i)); // Random remaining position.
            int temp = card[i]; card[i] = card[r]; card[r] = temp;
        }
        int c;
        //--- Print first n cards as ints.
        for (c=0; c<n; c++) 
		{
            printf("% d  ",card[c]);  // Just print number
        }
    //    cout << endl;
    
   
   return 0;
}