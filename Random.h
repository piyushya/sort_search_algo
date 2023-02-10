#pragma once
#ifndef GOODRANDOM_H
#define GOODRANDOM_H
#include <random>
#include <iostream>
namespace Random // capital R to avoid conflicts with functions named random()
{
	inline std::random_device rd;
	inline std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() }; // get 8 integers of random numbers from std::random_device for our seed
	inline std::mt19937 mt{ ss };

	inline int get(int min, int max)
	{
		std::uniform_int_distribution die{ min, max }; // we can create a distribution in any function that needs it
		return die(mt); // and then generate a random number from our global generator
	}
}
#endif // !GOODRANDOM_H