#include "ericHeader.h"
using namespace eric;
using namespace std;
int main() {
  files reviews=files("tripadvisor_hotel_reviews.csv"); 
  reviews.recordsToArray();
  cout<<"End of program"<<endl;
}
