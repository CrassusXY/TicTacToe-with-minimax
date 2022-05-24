#include "sorts.hh"

using namespace std::chrono;




int main(){
int n;
  char choice;
  std::string name = "projekt2_dane.csv";

  cout<<"Program realizujacy sortowanie tablicy zawierajacej ranking filmow."<<endl;
  cout<<"Ile filmow chcesz wczytac: ";
  cin>>n;
  MovieList test(name, n);
  cout<<endl<<"Jakiej metody sortowania chcesz uzyc?"<<endl;
  cout<<"QuickSort -> q"<<endl;
  cout<<"BucketSort -> b"<<endl;
  cout<<"MergeSort -> m"<<endl;
  cin>>choice;

  if(choice == 'q'){
    auto start = high_resolution_clock::now();
    quicksort(&test);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    float time = duration.count();
    time = time/1000;
    cout<<"Posortowane, zajęło to: "<<time<<"sekund."<<endl;
    sorted(&test);
  }
  else if(choice == 'b'){
    auto start = high_resolution_clock::now();
    bucketsort(&test);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    float time = duration.count();
    time = time/1000;
    cout<<"Posortowane, zajęło to: "<<time<<"sekund."<<endl;
    sorted(&test);
  }
  else if(choice == 'm'){
    auto start = high_resolution_clock::now();
    mergesort(&test);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    float time = duration.count();
    time = time/1000;
    cout<<"Posortowane, zajęło to: "<<time<<"sekund."<<endl;
    sorted(&test);
  }
  else{
    cout<<"Brak takiej opcji!"<<endl;
  }
}
// int main(){
//     std::string name = "projekt2_dane.csv";
//     int n[19]={50000, 100000, 150000, 200000, 250000, 300000, 350000, 400000, 450000, 500000, 550000, 600000, 650000, 700000, 750000, 800000, 850000, 900000, 950000};
//     std::ofstream qs;
//     std::ofstream bs;
//     std::ofstream ms;
//     qs.open ("qs.txt");
//     ms.open ("ms.txt");
//     bs.open ("bs.txt");
//     //qs<<endl<<"mean="<<test.mean()<<endl;
//     //qs<<endl<<"mediane="<<test.mediane()<<endl;
//     for(int i=0; i<19; i++){
//       MovieList test(name, n[i]);
//       auto start = high_resolution_clock::now();
//       quicksort(&test);
//       auto stop = high_resolution_clock::now();
//       auto duration = duration_cast<microseconds>(stop - start);
//       qs<<duration.count()<<endl;
//     }
//     for(int i=0; i<19; i++){
//       MovieList test(name, n[i]);
//       auto start = high_resolution_clock::now();
//       mergesort(&test);
//       auto stop = high_resolution_clock::now();
//       auto duration = duration_cast<microseconds>(stop - start);
//       ms<<duration.count()<<endl;
//     }
//     for(int i=0; i<19; i++){
//       MovieList test(name, n[i]);
//       auto start = high_resolution_clock::now();
//       bucketsort(&test);
//       auto stop = high_resolution_clock::now();
//       auto duration = duration_cast<microseconds>(stop - start);
//       bs<<duration.count()<<endl;
//     }

//     qs.close();
//     bs.close();
//     ms.close();
// }

//DRIVER DO POMIARU CZASU
// for(int i=0; i<5; i++){
//       MovieList test(name, n[i]);
//       auto start = high_resolution_clock::now();
//       quicksort(&test);
//       auto stop = high_resolution_clock::now();
//       auto duration = duration_cast<microseconds>(stop - start);
//       qs<<duration.count()<<endl;
//     }
//     for(int i=0; i<5; i++){
//       MovieList test(name, n[i]);
//       auto start = high_resolution_clock::now();
//       mergesort(&test);
//       auto stop = high_resolution_clock::now();
//       auto duration = duration_cast<microseconds>(stop - start);
//       ms<<duration.count()<<endl;
//     }
//     for(int i=0; i<5; i++){
//       MovieList test(name, n[i]);
//       auto start = high_resolution_clock::now();
//       bucketsort(&test);
//       auto stop = high_resolution_clock::now();
//       auto duration = duration_cast<microseconds>(stop - start);
//       bs<<duration.count()<<endl;
//     }