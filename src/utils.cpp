//
// Created by claudealves on 03.06.20.
//

#import <random>
#include <chrono>
#include "utils.h"

int utils::getRandomNumber(int from, int to) {
    // https://blog.alphorm.com/les-fonctions-aleatoires-en-c-11/
    static default_random_engine randGenerator(std::chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(from, to);
    return distribution(randGenerator);
}
