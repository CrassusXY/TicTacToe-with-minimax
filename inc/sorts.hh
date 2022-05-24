#include "movielist.hh"
using std::cout;
using std::cin;
using std::endl;

/**
 * @brief Funkcja skladajaca tablice
 * 
 * @tparam T 
 * @param arr tablica ktora ma zostac posortowana
 * @param beg poczatek tablicy
 * @param end koniec tablicy
 */
template<typename T>
void merge(T *arr, const int & beg, const int & end)
{
  int mid = (beg+end)/2;
  Movie *tmp = new Movie[end - beg+1];        //pomocniczna tablica
  int z=0, x=beg, y=mid+1;                    //z->ind dla tmp, x->ind dla 1. polowy arr, y-> dla 2. polowy

  while(x<=mid && y<=end){                    //dopoki ktoras z polow nie doszla do konca
    if (arr->get_movie(x) < arr->get_movie(y)){//przypisuje do kolejnego miejsca tmp wartosc wiekszego z elementow
      tmp[z] = arr->get_movie(y);           
      y++;
      z++;
    }
    else{
      tmp[z] = arr->get_movie(x);
      x++;
      z++;
    }
  }

  while (x <= mid){                         //przypisuje pozostale wartosci do tablicy tmp
    tmp[z] = arr->get_movie(x);
    x++;
    z++;
  }
  while (y <= end){
    tmp[z] = arr->get_movie(y);
    y++;
    z++;
  }

  for (int i = beg; i <= end; ++i){         //przypisuje wartosci tmp do glownej tablicy
    arr->set_movie(i, tmp[i-beg]);
  }
}

/**
 * @brief Funkcja sortujaca liste przy uzyciu algorytmu Merge Sort
 * 
 * @tparam T 
 * @param arr tablica ktora ma zostac posortowana
 * @param beg poczatek tablicy(domyslnie = 0)
 * @param end koniec tablicy(domyslnie = -1, wtedy koncowy indeks jest obliczany z dlugosci tablicy)
 */
template<typename T>
void mergesort(T *arr, int beg=0, int end=-1)
{ 
  if(end == -1){                      //przypadek kiedy nie zostal podany index koncowy
    end = arr->get_len()-1;
  }
  if(beg<end && beg>=0){                
    int mid = (beg+end)/2;            //srodek tablicy, puknt w ktorym, dzielimy nasza tablice
    mergesort<T>(arr, beg, mid);      //sortowanie pierwzej polowy 
    mergesort<T>(arr, mid+1, end);    //sortowanie drugiej polowy
    merge<T>(arr, beg, end);          //scalanie tablic
  }
}


/**
 * @brief 
 * 
 * @tparam T 
 * @param arr 
 * @param beg 
 * @param end 
 * @return int 
 */
template<typename T>
int partition(T *arr, int beg, int end)
{
  Movie tmp;
  Movie pivot = arr->get_movie(beg);  //ustawiam pivot jako pierwszy element
  int i = beg-1;                      //index idacy od lewej czesci tablicy
  int j = end+1;                      //index idacy od prawej czesci tablicy

  while(true){
    do {
      i++;
    } while (arr->get_movie(i)>pivot);    //szukam pierwszego od lewej elementu wiekszego od pivota
    do {
      j--;
    } while (arr->get_movie(j)<pivot);    //szukam pierwszego od prawej elementu mniejszego od pivota

    if(i>=j){                             //jesli indexy sie spotkaly, zwracam pozycje pivotu
      return j;   
    }
    tmp = arr->get_movie(i);              //zamieniam znalezione elementy miejscami
    arr->set_movie(i, arr->get_movie(j));
    arr->set_movie(j, tmp);
  }
}

/**
 * @brief Funkcja sortujaca liste przy uzyciu algorytmu Quick Sort
 * 
 * @tparam T 
 * @param arr tablica ktora ma zostac posortowana
 * @param beg poczatek tablicy(domyslnie = 0)
 * @param end koniec tablicy(domyslnie = -1, wtedy koncowy indeks jest obliczany z dlugosci tablicy)
 */
template<typename T>
void quicksort(T *arr, int beg=0, int end=-1)
{
  if(end == -1){                          //przypadek kiedy nie zostal podany index koncowy
    end = arr->get_len()-1;
  }
  if(beg<end && beg>=0){
  int pivind = partition(arr, beg, end);  //
  quicksort<T>(arr, beg, pivind);         //wywolanie funkcji dla pierwszej czesci
  quicksort<T>(arr, pivind+1, end);       //wywolanie funkcji dla drugiej czesci
  }
}



/**
 * @brief Funkcja sortujaca liste przy uzyciu algorytmu Bucket Sort
 * 
 * @param arr tablica ktora ma zostac posortowana
 */
template<typename T>
void bucketsort(T *arr)
{
  int len = arr->get_len();
  int a[2]={0};             //zmienna przechowujaca ilosc elementow w poszczegolnych wiadrach
  int b[2];
  float rating;
  int i;
  T bucket[2];

  for(i=0; i<len; i++){             //zliczam ilosc elementow w wiadrze
    rating = arr->get_movie(i).get_rating();
    if(rating<=5){
      a[0]++;
    }
    else{
      a[1]++;
    }

  }

  
  for(int j=0; j<2; j++){         //tworze 2 wiadra o konkretnych rozmiarach 
    b[j] = a[j];
    bucket[j] = MovieList(a[j]);
  }



for(i=0; i<len; i++){             //wpisuje do srodka wartosci z zalozonych przedzialow
    rating = arr->get_movie(i).get_rating();
    if(rating<=5){
      bucket[0].set_movie(b[0]-1, arr->get_movie(i));
      b[0]--;
    }
    else{
      bucket[1].set_movie(b[1]-1, arr->get_movie(i));
      b[1]--;
    }
  }

  for(int i=0;i<2;i++){           //sortuje poszczegolne wiadra
    b[i] = a[i];
    quicksort(&bucket[i], 0, b[i]-1);
  }

  i=0;
  for(int j=1; j>=0; j--){        //wypisuje w odpowiedniej kolejnosci elementy z wiader do tablicy glownej
    while(b[j] > 0){
      arr->set_movie(i, bucket[j].get_movie(a[j]-b[j]));
      b[j]--;
      i++;
    }
  }
}

/**
 * @brief Funkcja sprawdzajaca czy dana tablica jest posortowana prawidlowo
 * 
 * @param arr tablica do sprawdzenia
 * @return true jesli jest posortowana
 * @return false jesli nie jest posortowana 
 */

template<typename T>
bool sorted(T *arr)
{
  for(int i = 0; i<arr->get_len(); i++){
    cout<<arr->get_movie(i).get_title()<<", "<<arr->get_movie(i).get_rating()<<endl;
    if(i+1 == arr->get_len()){
        cout<<"Sortowanie odbylo sie pomyslnie."<<endl;
        return 1;
    }
    else if(arr->get_movie(i)<arr->get_movie(i+1)){
        cout<<"Tablica nie jest posortowana!!"<<endl;
        return 0;
    }
  }
  cout<<"Sortowanie odbylo sie pomyslnie."<<endl;
  return 1;
}
