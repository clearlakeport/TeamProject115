#include "sorting.h"


int main()
{
   int userChoice = 99;

   srand(static_cast<unsigned int>(time(NULL)));

   Sorting st; // use randomly generate data only
   st.getSize();
   st.genData();

   // use Sorting(Vector<int> input) for user defined data.

   while ((userChoice = st.getChoice()))
   {
      st.startChoice();

      switch (userChoice)
      {
      case 1:
         st.insertionSort();
         break;
      case 2:
         st.SelectionSort();
         break;
      case 3:
         st.bubble();
         break;
      case 4:
         st.mergeSort();
         break;
      case 5:
         st.quickSort();
         break;
      case 6:
         st.heapSort();
         break;
      case 7:
         st.CountSort();
         break;
      case 8:
         st.RadixSort();
         break;
      case 9:
         st.reset();
         break;
      default:
         return 0;
      }
      st.endChoice();
   }

   return 0;
}