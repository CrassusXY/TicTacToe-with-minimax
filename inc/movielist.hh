#ifndef MOVIELIST_HH
#define MOVIELIST_HH
#include <algorithm>
#include <chrono>
#include <string>
#include <iostream>
#include <fstream>


class Movie
{
public:
protected:
    float rating;
    std::string title;
public:
    Movie(const float & rating_, const std::string & title_):
        rating(rating_),
        title(title_)
        {}
    Movie(){}

    float get_rating(){return rating;};
    std::string get_title(){return title;};
    void set_rating(const float & rating_){rating = rating_;};
    void set_title(const std::string & title_){title = title_;};
    bool operator< (Movie arg);
    bool operator<= (Movie arg);
    bool operator> (Movie arg);
    bool operator>= (Movie arg);
    void operator= (Movie arg);
};


class MovieList
{
protected:
    Movie *list;
    uint leng;
public:
    MovieList() {};
    MovieList(int size);
    MovieList(const std::string & name, int limit);
    Movie get_movie(const int & id){return list[id];};
    void set_movie(const int & id, Movie arg){list[id].set_rating(arg.get_rating()); list[id].set_title(arg.get_title());};
    int get_len(){return leng;};
    float mean();
    float mediane();
};

#endif