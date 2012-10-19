    //solution 2 dutch flag problem  
    //as only 3 values exists it can also be solved using counting sort  
    void threecolors(int x[], int size){  
      
     int lo = 0, mid = 0, hi = size-1;  
      
    //move lo to a position where value is not 0  
     while ( lo < size && x[lo] ==0)  
      lo++;  
      
    //move hi to a position where value is not 2  
     while(hi >=0 && x[hi] == 2)  
      hi--;  
      
    //set mid to lo  
     mid = lo;  
     while (mid <= hi)  
     {  
      
     //swap with lo if mid points to 0  
     //swap with hi if mid points to 1  
     //increment mid if it points to 1  
      if ( x[mid] == 0) {  
       std::swap(x[lo],x[mid]);  
       lo++;mid++;  
      }  
      else if (x[mid] == 1)  
       mid++;  
      else  
      {  
      
       std::swap(x[mid],x[hi]);  
       hi--;  
      }  
     }  
    }  