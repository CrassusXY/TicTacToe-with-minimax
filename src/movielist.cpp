#include "movielist.hh"

/**
 * @brief przeciazenie operatora znaku mniejszosci
 * 
 * @param arg Obiekt Movie wzgledem ktorego komparujemy
 * @return true jesli arg jest wiekszy 
 * @return false jesli arg jest mniejszy
 */
bool Movie::operator<(Movie arg){
    if(get_rating() < arg.get_rating()){
        return true;
    }
    else 
        return false;
}

/**
 * @brief przeciazenie operatora znaku mniejszosci lub rowosci
 * 
 * @param arg Obiekt Movie wzgledem ktorego komparujemy
 * @return true jesli arg jest wiekszy lub rowny
 * @return false jesli arg jest mniejszy
 */
bool Movie::operator<=(Movie arg){
    if(get_rating() <= arg.get_rating()){
        return true;
    }
    else 
        return false;
}

/**
 * @brief przeciazenie operatora znaku wiekszosci
 * 
 * @param arg Obiekt Movie wzgledem ktorego komparujemy
 * @return true jesli arg jest mniejszy
 * @return false jesli arg jest wiekszy
 */
bool Movie::operator>(Movie arg){
    if(get_rating() > arg.get_rating()){
        return true;
    }
    else 
        return false;
}

/**
 * @brief przeciazenie operatora znaku wiekszosci lub rownosci
 * 
 * @param arg Obiekt Movie wzgledem ktorego komparujemy
 * @return true jesli arg jest mniejszy lub rowny
 * @return false jesli arg jest wiekszy
 */
bool Movie::operator>=(Movie arg){
    if(get_rating() >= arg.get_rating()){
        return true;
    }
    else 
        return false;
}

/**
 * @brief przeciazenie operatora przypisania
 * 
 * @param arg obiekt ktory przypisujemy
 */
void Movie::operator=(Movie arg){
    set_title(arg.get_title());
    set_rating(arg.get_rating());
}

/**
 * @brief Konstruktor pustej listy filmow o zadanym rozmiarze
 * 
 * @param size rozmiar tablicy
 */
MovieList::MovieList(int size){
    list = new Movie[size];
    leng = size; 
}


MovieList::MovieList(const std::string & name, int limit){
    std::fstream fin;
    int rows = 0, badrows = 0;
    std::string line, tmp, num;
    int len = 0, val = 0, inval = 0;
    float rating = 0.0;
    std::string title;


    fin.open(name, std::ios::in);       //otwanie strumienia do bazy filmow
    if( fin.good() != true ){
        throw std::logic_error("Cannot open file!");
    } 

    while (getline(fin, line) && rows < limit){     //zliczanie dobrych i zlych wpisow w bazie
        if (isdigit(line.back()))
        {
            rows++;
        }
        else{
            badrows++;
        }  
    }
    
    list = new Movie[rows];                         //alokacja tablicy o odpowiednim rozmiarze
    if(rows<limit){
        std::cout<<"Zbyt mało danych w podanym pliku!"<<std::endl;
    }
    fin.clear();                                    //powrot na poczatek pliku
    fin.seekg(0);

    while (getline(fin, line)&&val<limit){          //wczytanie bazy do listy
        if (isdigit(line.back())){
            len = line.length() - 1;
            tmp = line.substr(len - 3, len);

            if(isdigit(tmp[0])){   //ocena = 10.0
                rating  = stof(tmp);
                line.erase(len - 4, len);
            }
            else{   //ocena <10.0
                tmp = tmp.substr(1, 3);
                rating  = stof(tmp);
                line.erase(len - 3, len);
            }
            val++;
            num = std::to_string(val+inval);        //usuwanie ID znajdujacego sie na poczatku pliku
            line.erase(0, num.length()+1);      
            list[val-1] = Movie(rating, line);
        }
        else{
            inval++;
        }
    }
    std::cout<<std::endl<<"Wczytano: "<<val<<" prawidłowych wierszy"<<std::endl;
    std::cout<<"Nie wczytano: "<<inval<<" nieprawidłowych wierszy"<<std::endl;
    leng = rows;
}

/**
 * @brief Funkcja obliczajaca srednia ze wszystkich elementow tablicy
 * 
 * @return srednia
 */
float MovieList::mean(){
    float tmp=0;
    for(uint i=0; i<leng; i++){
        tmp += list[i].get_rating();
    }
    return tmp/leng;
}

/**
 * @brief Funkcja obliczajaca mediane tablicy
 * 
 * @return mediana
 */
float MovieList::mediane(){
    float tmp=0;
    if(leng%2==1)
        tmp = list[leng/2].get_rating();
    else{
        tmp = (list[leng/2-1].get_rating() + list[leng/2].get_rating())/2;
    }
    return tmp;
}