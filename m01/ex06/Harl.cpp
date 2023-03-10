/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:12:43 by znichola          #+#    #+#             */
/*   Updated: 2023/03/10 11:37:46 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <iostream>

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level) const
{
	static void	(Harl::*f[])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	static const std::string msgLevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
		if (msgLevel[i] == level)
			(this->*f[i])();
}

void Harl::debug(void) const
{
	static const std::string debug_msg[] = {
		"The answer to life, the universe and everything is... oh wait, wrong branch",
		"Found the missing semicolon, the universe is saved!",
		"Debugging is like being a detective in a crime movie where you are also the murderer.",
		"It's not a bug, it's a feature - said no one ever.",
		"I see dead code.",
		"I don't always test my code, but when I do, I do it in production.",
		"Debugging is like trying to find a needle in a haystack, except the needle is also made of hay.",
		"I think, therefore I debug.",
		"I'm not lazy, I'm just conserving energy for debugging.",
		"I don't always code, but when I do, I prefer debugging.",
		"Debugging is my cardio.",
		"I have a dream that one day, all my code will work as expected.",
		"I speak fluent sarcasm and debugging code.",
		"Some people see code, I see possibilities.",
		"I don't always write bug-free code, but when I do, I prefer to do it in my sleep.",
		"Debugging is a journey, not a destination.",
		"I don't always debug, but when I do, I prefer to do it with coffee.",
	};
	std::cout << "DEBUG: " << debug_msg[std::rand() % 17] << std::endl;
}

void Harl::info(void) const
{
	static const std::string info_msg[] = {
		"Fun fact: the word 'bug' was coined by Grace Hopper when she found a moth stuck in her computer.",
		"If at first you don't succeed, call it version 1.0.",
		"A clean codebase is a happy codebase.",
		"Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live.",
		"Programming is like sex: one mistake and you have to support it for the rest of your life.",
		"Real programmers don't comment their code. If it was hard to write, it should be hard to understand.",
		"I love deadlines. I like the whooshing sound they make as they fly by.",
		"The best way to predict the future is to implement it.",
		"Programming is the only job where you get paid to type at a keyboard naked.",
		"I don't always write code, but when I do, I prefer to do it with headphones on.",
		"The code must flow.",
		"Code is poetry, if you think about it in the right way.",
		"The difference between a programmer and a non-programmer is that the non-programmer thinks six feet is a safe distance.",
		"I'm not arguing, I'm just explaining why I'm right.",
		"It's not a bug, it's an undocumented feature.",
		"Programming is easy. It's debugging that's hard.",
	};
	std::cout << "INFO: " << info_msg[std::rand() % 16] << std::endl;
}

void Harl::warning(void) const
{
	static const std::string warning_msg[] = {
		"Your code has more issues than National Geographic.",
		"I'm not responsible for the mess your code is about to become.",
		"This code may cause uncontrollable laughter or an inexplicable urge to dance.",
		"This code may cause side effects such as hair loss, insomnia, and delusions of grandeur.",
		"This code is like a box of chocolates - you never know what you're going to get.",
		"This code is intended for educational purposes only. Any resemblance to real code is purely coincidental.",
		"This code may contain traces of peanuts, soy, and undefined behavior.",
		"Proceed with caution. This code has been known to cause temporary insanity.",
		"This code is not for the faint of heart. Viewer discretion is advised.",
		"This code has been known to induce temporary blindness in developers.",
		"Use this code at your own risk. Side effects may include euphoria, caffeine addiction, and irrational confidence.",
		"This code may cause excessive use of exclamation marks!",
	};
	std::cout << "WARNING: " << warning_msg[std::rand() % 12] << std::endl;
}

void Harl::error(void) const
{
	static const std::string error_msg[] = {
		"Your code is on fire.",
		"I'm sorry, Dave. I'm afraid I can't do that.",
		"You have committed an error that cannot be undone. Kindly press Alt+F4 and start over.",
		"Something went wrong. Please blame the nearest programmer.",
		"This code is like a house of cards. One wrong move and it all falls apart.",
		"Abandon all hope, ye who enter here.",
		"Houston, we have a problem.",
		"This code is a disaster waiting to happen.",
		"Mayday! Mayday! We're going down!",
		"You have violated the laws of programming physics.",
		"This code has more bugs than a roach motel.",
		"Danger, Will Robinson! Danger!",
		"This code is a ticking time bomb.",
		"This code has crashed and burned.",
	};
	std::cout << "ERROR: " << error_msg[std::rand() % 14] << std::endl;
}
