#include <iostream>
#include "BMP.h"
#include <cmath>


//
//The provided reading, computer graphics textbooks (2nd and 3rd edition), and GeeksForGeeks page on midpoint algorithm were referenced for the assignment.
//


void midPointEllipse(int a, int b, BMP &bmpNew){

    int x = 0;
    int y = b; 
  bmpNew.set_pixel(x + 375 , y,255, 255, 255, 0);

   double d1 = (b*b) - (a*a*b) + (0.25 * a * a);
  
     while(a*a * (y - 0.5) > b * b * (x + 1)){

        if(d1 >= 0){
            d1 = d1 + ( b * b * ((2 * x) + 3) + a*a * ((-2 * y)  + 2));
             y = y -1;
          
        }
       else {
        d1 = d1 + (b*b * ((2 * x) + 3));
       }

        x = x+1;

       bmpNew.set_pixel(x + 375, y + 250,255, 255, 255, 0);
       bmpNew.set_pixel((-1 * x) + 375, y + 250,255, 255, 255, 0);
        }
  
    double d2 = 0;

   while( y > 0){

    if (d2 >= 0){

      d2 = d2 + (a*a * ((-2 * y) +3));
    }
     else{ 
        d2 = d2 + (b*b * ((2 *x) +2) + a*a * ((-2 * y) + 3));
        x = x+ 1;
       }
     
       y = y -1;
     
     bmpNew.set_pixel(x + 375, y + 250,255, 255, 255, 0);
     bmpNew.set_pixel((-1 * x) + 375, y + 250,255, 255, 255, 0);

   }
  
}

int main() {


  
    BMP bmpNew(750,500,false);
    bmpNew.fill_region(0, 0, 750, 500, 0, 0, 0, 0);
     int a = 6 * 12;
      int b = 12 * 12;
    midPointEllipse( a, b, bmpNew);
  
    bmpNew.write("output.bmp");


}


